#include "Motor.h"
#include "gestorTexturas.h"
#include "../Jugador.h"
#include "GestorEventos.h"
#include "GamePlay.h"
#include "Timer.h"
#include "../Objetos/Mercado.h"

Motor* Motor::s_instancia = nullptr;

Motor::Motor()
{
// constructor
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

    GamePlay::getInstancia()->crearCultivos();

    GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
    GestorTexturas::getInstancia()->cargar("click","assets/click.png");

    GestorTexturas::getInstancia()->cargar("terreno","assets/cultivo_terreno.png");
    GestorTexturas::getInstancia()->cargar("arado","assets/cultivo_arado.png");
    GestorTexturas::getInstancia()->cargar("sembrado","assets/cultivo_sembrado.png");
    GestorTexturas::getInstancia()->cargar("crecido","assets/cultivo_crecido.png");
    GestorTexturas::getInstancia()->cargar("mercado","assets/mercado.png");

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

void Motor::actualizar()
{
    if(GestorEventos::getInstancia()->getBotonIzq())
    {

        std::string idCultivo = Motor::buscarEnMapa();
        GestorEventos::getInstancia()->clickEnArea(idCultivo);


        //Aca podemos pensar una manera de que esto este seteado en algun lado
        //como en una clase objeto que tenga estos valores o alguna otra clase
        //recibiendo clickEnArea(objeto) y ese objeto ya conozca los parametros q pasamos ahora
    }
}
//este metodo necesita delegar hacia una interface?

void Motor::renderizar()
{
    SDL_SetRenderDrawColor(m_renderizador,247,229,178,255);
    SDL_RenderClear(m_renderizador); ///Fondo color amarillo arena
    //mirando esta parte me doy cuenta que si cada cultivo
    //pudiera ejecutar el metodo cargador de imagines de manera diferente seria muy interesante
    //cultivo1.metodocargador pondria la imagen del cultivo1 en las coordinadas correctas,]
    //y al poner un cultivoN.metodocargador este se pondria en la ubicacion seteada en ese metodo concreto

    std::map<std::string,Cultivo*>::iterator iterador;
    Mercado::getInstancia()->dibujar();

    for(iterador = m_mapaCultivos.begin(); iterador!= m_mapaCultivos.end(); iterador++)
    {
        iterador->second->metodo_cargador_de_imagenes();
    }

    indicadorMonedas();
    indicadorSemillas();
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
            GestorEventos::getInstancia()->setEventoX(evento.button.x);
            GestorEventos::getInstancia()->setEventoY(evento.button.y);
            GestorEventos::getInstancia()->setBotonIzq(true);
        }
    }
    break;
    default:
    {

    }
    break;
    }
}

void Motor::indicadorMonedas()//esta tiene que ir al textureManager o alguna clase referida a la GUI (la interfaz grafica de usuario )
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
    //SDL_RenderPresent (m_renderizador); esta linea hace parpadear al indicador de semillas.
    SDL_DestroyTexture (m_textura);
    SDL_FreeSurface (m_superficie);
}

void Motor::indicadorSemillas()//esta tambien tiene que ir al textureManager o alguna clase referida a la GUI (la interfaz grafica de usuario )
{
    std::string monedas = "SEMILLAS: " + std::to_string(Jugador::getInstancia()->getSemillas());
    const char*semillas_mostrar = monedas.c_str();

    SDL_Color color = {0,170,50}; //Color verde.
    m_superficie = TTF_RenderText_Solid(m_fuente,semillas_mostrar, color);
    m_textura = SDL_CreateTextureFromSurface(m_renderizador, m_superficie);
    int texW, texH;
    SDL_QueryTexture(m_textura, NULL, NULL, &texW, &texH);
    SDL_Rect destRect = {5,50, texW, texH}; //
    SDL_RenderCopy (m_renderizador, m_textura, NULL, &destRect);
    SDL_RenderPresent (m_renderizador);
    SDL_DestroyTexture (m_textura);
    SDL_FreeSurface (m_superficie);
}

//idea
//objeto a mostrar: ( va a ser un objeto de la clase imagen )
//necesitamos la clase imagen que tenga los atributos: id, direccion, bool cargada, posX, posY, tamX, tamY

std::string Motor::buscarEnMapa()
{
    std::map<std::string,Cultivo*>::iterator iterador;
    for(iterador = m_mapaCultivos.begin(); iterador!= m_mapaCultivos.end(); iterador++)
    {
        int x= GestorEventos::getInstancia()->getX() - iterador->second->getUbicacion_x();
        int y= GestorEventos::getInstancia()->getY() - iterador->second->getUbicacion_y();

        if((x>0) && (x<50))
        {
            if((y>-0.5*x+25)&&(y<0.5*x+25))
                return iterador->first;
        }

        else if((x>50) && (x<100))
        {
            if((y>0.5*x-25)&&(y<-0.5*x+75))
                return iterador->first;
        }
    }
    //si hizo click en el area de mercado return 1111
    if((GestorEventos::getInstancia()->getX()>= 650 && GestorEventos::getInstancia()->getX() <= 743 ) && (GestorEventos::getInstancia()->getY() >=390 && GestorEventos::getInstancia()->getY() <= 461 ) )
    //Reducir este if
    {
        return "mercado";
    }
    return "0000";
}

void Motor::borrarCultivos()
{
    std::map<std::string,Cultivo*>::iterator iterador;
    for(iterador = m_mapaCultivos.begin(); iterador!=m_mapaCultivos.end(); iterador++)
    {
        delete(iterador->second);//a que atributo del iterador esta accediendo? no aparece en la doc de cplusplus (solucionado: leer link)
    }
    ///https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean
    //basicamente second se refiere al segundo parametro del iterador, tiene 2 uno es el id y el otro es el puntero por eso le decimos delete(puntero)
    m_mapaCultivos.clear();
    SDL_Log("Mapa de Cultivos se ha limpiado correctamente");
}

//getters
Cultivo* Motor::getCultivo(std::string idCultivo)
{
    return m_mapaCultivos[idCultivo];
}

std::map<std::string,Cultivo*> Motor::getMapa()
{
    return m_mapaCultivos;
}

//setters

void Motor::actualizarEstadoCultivo(Estado_Cultivo* nuevoEstado)
{
    estado_cultivo = nuevoEstado;
}

void Motor::setMapa(std::string idCultivo, Cultivo* nuevoCultivo)
{
    m_mapaCultivos[idCultivo]=nuevoCultivo;
}


