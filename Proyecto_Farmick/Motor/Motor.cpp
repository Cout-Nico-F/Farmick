#include "Motor.h"
#include "gestorTexturas.h"
#include "../Jugador.h"
#include <string>
#include <cstring>

//tips de brian:
//el gameplay le da mensajes a cultivo (lo hace con un metodo ) leer mensajes relacionado a metodos

//los objetos de cultivo los crea la clase gameplay

Motor* Motor::s_instancia = nullptr;

void Motor::crearCultivos()
{
    Cultivo* cultivo1 = new Cultivo("cultivo1");//a modo de prueba de la maquina de estados de cultivo.
    m_mapaCultivos[cultivo1->getIdCultivo()] = cultivo1;
    cultivo1->setUbicacion_x(428);
    cultivo1->setUbicacion_y(500);

    Cultivo* cultivo2 = new Cultivo("cultivo2");
    m_mapaCultivos[cultivo2->getIdCultivo()] = cultivo2;
    cultivo2->setUbicacion_x(378);
    cultivo2->setUbicacion_y(525);

    Cultivo* cultivo3 = new Cultivo("cultivo3");
    m_mapaCultivos[cultivo3->getIdCultivo()] = cultivo3;
    cultivo3->setUbicacion_x(478);
    cultivo3->setUbicacion_y(525);

    Cultivo* cultivo4 = new Cultivo("cultivo4");
    m_mapaCultivos[cultivo4->getIdCultivo()] = cultivo4;
    cultivo4->setUbicacion_x(428);
    cultivo4->setUbicacion_y(550);

    // m_mapa_cultivos[0][0] = cultivo1;
}

void Motor::borrarCultivos()
{
    std::map<std::string,Cultivo*>::iterator iterador;
    for(iterador = m_mapaCultivos.begin(); iterador!= m_mapaCultivos.end(); iterador++)
    {
        delete(iterador->second);//a que atributo del iterador esta accediendo? no aparece en la doc de cplusplus (solucionado: leer link)
    }
    ///https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean
    //basicamente second se refiere al segundo parametro del iterador, tiene 2 uno es el id y el otro es el puntero por eso le decimos delete(puntero)
    m_mapaCultivos.clear();
    SDL_Log("Mapa de Cultivos se ha limpiado correctamente");
}

bool Motor::inicializar()
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!=0)
    {
        SDL_Log("Fallo al inicializar SDL: %s", SDL_GetError());
        return false;
    }
    if(TTF_Init()==-1)
    {
        SDL_Log("Fallo al inicializar TTF: %s",SDL_GetError());
        return false;
    }
    m_ventana = SDL_CreateWindow("Titulo de la ventana",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,ANCHO_PANTALLA,ALTO_PANTALLA,0);
    if(m_ventana == nullptr)
    {
        SDL_Log("Fallo al crear la ventana: %s",SDL_GetError());
        return false;
    }
    m_renderizador = SDL_CreateRenderer(m_ventana,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_renderizador == nullptr)
    {
        SDL_Log("Failed to create Renderer: %s",SDL_GetError());
        return false;
    }
    m_fuente = TTF_OpenFont("Aarvark Cafe.ttf",25);

    crearCultivos();

    return m_juegoActivo = true;
}

bool Motor::limpiar()
{
    borrarCultivos();

    GestorTexturas::getInstancia()->limpiar();
    SDL_DestroyRenderer(m_renderizador);
    SDL_DestroyWindow(m_ventana);
    IMG_Quit();

    SDL_DestroyTexture(m_textura);
    SDL_FreeSurface(m_superficie);
    TTF_CloseFont(m_fuente);
    TTF_Quit();

    SDL_Quit();
    return true;
}

void Motor::salir()
{
    m_juegoActivo = false;
}

void Motor::renderizar()
{
    SDL_SetRenderDrawColor(m_renderizador,247,229,178,255);
    SDL_RenderClear(m_renderizador); ///Fondo color amarillo arena
    //mirando esta parte me doy cuenta que si cada cultivo
    //pudiera ejecutar el metodo cargador de imagines de manera diferente seria muy interesante
    //cultivo1.metodocargador pondria la imagen del cultivo1 en las coordinadas correctas,]
    //y al poner un cultivoN.metodocargador este se pondria en la ubicacion seteada en ese metodo concreto
    m_mapaCultivos["cultivo1"]->metodo_cargador_de_imagenes();
    m_mapaCultivos["cultivo2"]->metodo_cargador_de_imagenes();
    m_mapaCultivos["cultivo3"]->metodo_cargador_de_imagenes();
    m_mapaCultivos["cultivo4"]->metodo_cargador_de_imagenes();
    indicadorMonedas();
}

void Motor::eventos()
{
    SDL_Event evento;
    SDL_PollEvent(&evento);
    switch (evento.type)
    {
    case SDL_QUIT:
    {
        salir();
    }
    break;

    case SDL_MOUSEBUTTONDOWN:
    {
        if(evento.button.button==SDL_BUTTON_LEFT)
        {
            m_evento_x=evento.button.x;
            m_evento_y=evento.button.y;
            m_botonIzqMouse=true;
        }
    }
    break;
    default:
    {
        m_botonIzqMouse=false;
    }
    break;
    }
}

Motor::Motor()
{
// cultivo = new Cultivo(); <-?
}

void Motor::actualizarEstadoCultivo(Estado_Cultivo* nuevoEstado)
{
    estado_cultivo = nuevoEstado;
}

void Motor::indicadorMonedas()
{
    std::string monedas = "MONEDAS: " + std::to_string(Jugador::getInstancia()->getMonedas());
    const char*monedas_mostrar=monedas.c_str();

    SDL_Color color = {239,184,16}; //Color oro.
    m_superficie = TTF_RenderText_Solid(m_fuente,monedas_mostrar, color);
    m_textura = SDL_CreateTextureFromSurface(m_renderizador, m_superficie);
    int texW, texH;
    SDL_QueryTexture(m_textura, NULL, NULL, &texW, &texH);
    SDL_Rect destRect = {20,20, texW, texH};
    SDL_RenderCopy (m_renderizador, m_textura, NULL, &destRect);
    SDL_RenderPresent (m_renderizador);
    SDL_DestroyTexture (m_textura);
    SDL_FreeSurface (m_superficie);
}
//idea
//objeto a mostrar: ( va a ser un objeto de la clase imagen )
//necesitamos la clase imagen que tenga los atributos: id, direccion, bool cargada, posX, posY, tamX, tamY

//void Motor::inicializarUbicacionCultivos()
//{
//    int x=428;
//    int y=500;
//    for (int f=0; f<3;f++)
//    {
//        y=y+f*25;
//        for(int col=0;col<3;col++)
//        {
//            mapa_cultivos[f][col].m_ubicacion_x=x;
//            mapa_cultivos[f][col].m_ubicacion_y=y;
//            x=x+col*50;
//        }
//    }
//}
//     INICIALIZACION CON MATRIZ

void Motor::actualizar()
{
    if(m_botonIzqMouse)
    {
        clickEnArea(428,527,500,550,"cultivo1");
        //Aca podemos pensar una manera de que esto este seteado en algun lado
        //como en una clase objeto que tenga estos valores o alguna otra clase
        //recibiendo clickEnArea(objeto) y ese objeto ya conozca los parametros q pasamos ahora
    }
}
//este metodo necesita delegar hacia una interface?


void Motor::clickEnArea(int desdeX, int hastaX, int desdeY, int hastaY, std::string idCultivo)
//void Motor::clickEnArea()
{
    ///Cambiar fórmula para que sirva en los rombos.
    /// if(m_evento_x >=desdeX && m_evento_x <= hastaX && m_evento_y >= desdeY && m_evento_y <= hastaY)//defino el area
    if(buscarEnMatriz())
        //idCultivo = buscarIDCultivo();
    {
        if(Jugador::getInstancia()->getMonedas()>=10)
        {
            Jugador::getInstancia()->gastarMonedas(10);

            m_mapaCultivos[idCultivo]->hacer();


            m_botonIzqMouse = false;
        }
        else
        {
            SDL_Log("Monedas insuficientes, necesitas 10");
            m_botonIzqMouse = false;
        }
    }
    else
    {
        Jugador::getInstancia()->incrementarMonedas();
        SDL_Log("Encontraste una moneda");
        m_botonIzqMouse = false;
    }
}

bool Motor::buscarEnMatriz()
{
    int ubicacionPrimeraFilaY=500;   //ubicacion del rombo superior en Y
    int ubicacionUltimaColumnaX=428; //ubicacion del rombo superior en X
    int tamanioTerrenoX=100;
    int tamanioTerrenoY=50;
    int cantidadFilas=2;
    int cantidadColumnas=2;
    int x,y;

    for(x=ubicacionUltimaColumnaX; x > ubicacionUltimaColumnaX-(cantidadColumnas*(tamanioTerrenoX/2)); x-=(tamanioTerrenoX/2))
    {
        for(y=ubicacionPrimeraFilaY; y < ubicacionPrimeraFilaY+(cantidadFilas*(tamanioTerrenoY/2)); y+= (tamanioTerrenoY/2))
        {
            if(m_evento_y>y && m_evento_y<50+y)
            {
                if((m_evento_x>x) && (m_evento_x<x+100))
                return true;
//
//                if((m_evento_x>x) && (m_evento_x<50+x))
//                {
//                    if((m_evento_y>-0.5*m_evento_x+25)&&(m_evento_y<0.5*m_evento_x+25))
//                        return true;
//                }
//                else if((m_evento_x>50+x) && (m_evento_x<100+x))
//                {
//                    if((m_evento_y>0.5*m_evento_x-25)&&(m_evento_y<-0.5*m_evento_x+75))
//                        return true;
            }
        }
//                    if(((m_evento_y > -0.5*m_evento_x+25)&& (m_evento_y < 0.5*m_evento_x+25)) ||
//                       ((m_evento_y > 0.5*m_evento_x-25)&& (m_evento_y < -0.5*m_evento_x+75)))
    }
    return false;
}
