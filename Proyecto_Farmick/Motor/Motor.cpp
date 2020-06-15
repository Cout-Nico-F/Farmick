#include "Motor.h"
#include "gestorTexturas.h"
#include "../Jugador.h"
#include <string>
#include <cstring>



Cultivo cultivo1;//a modo de prueba de la maquina de estados de cultivo.

//el gameplay le da mensajes a cultivo (lo hace con un metodo ) leer mensajes relacionado a metodos
//los objetos de cultivo los crea la clase gameplay


Motor* Motor::s_instancia = nullptr;

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
    return m_juegoActivo = true;
}

bool Motor::limpiar()
{
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
    if(m_boton)
    {
        //necesita un if (click fuera del cultivo)

        //Aca va la llamada a un metodo que contiene este framento de code *--*
        if(m_evento_x >=428 && m_evento_x <= 527 && m_evento_y >=500 && m_evento_y <= 550)
        {
            if(Jugador::getInstancia()->getMonedas()>=10)
            {
                Jugador::getInstancia()->gastarMonedas(10);
                cultivo1.hacer();
            }
            else
            {
                SDL_Log("Monedas insuficientes, necesitas 10");
            }
        }
        else
        {
            Jugador::getInstancia()->incrementarMonedas();
            SDL_Log("Encontraste una moneda");
        }
    }
}   //*--*
//metodo();

//este metodo necesita delegar hacia una interface?
//SDL_Log("Actualizando!");


void Motor::renderizar()
{
    SDL_SetRenderDrawColor(m_renderizador,247,229,178,255);
    SDL_RenderClear(m_renderizador); ///Fondo color amarillo arena

    cultivo1.metodo_cargador_de_imagenes();
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
            m_boton=true;
        }
    }
    break;
    default:
    {
        m_boton=false;
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

//objeto a mostrar: ( va a ser un objeto de la clase imagen )
//necesitamos la clase imagen que tenga los atributos: id, direccion, bool cargada, posX, posY, tamX, tamY
