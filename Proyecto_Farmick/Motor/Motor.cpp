#include "Motor.h"
#include "gestorTexturas.h"

Cultivo cultivo1;//a modo de prueba de la maquina de estados de cultivo:

Motor* Motor::s_instancia = nullptr;

bool Motor::inicializar()
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!=0)
    {
        SDL_Log("Fallo al inicializar SDL: %s", SDL_GetError());
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
    //la siguiente linea deberia estar en otra clase ( esta cargando la imagen de prueba palmera )
    //TextureManager::GetInstancia()->cargar("palmerabig", "assets/palmerabig.png");
    return m_juegoActivo = true;
}

bool Motor::limpiar()
{
    SDL_DestroyRenderer(m_renderizador);
    SDL_DestroyWindow(m_ventana);
    IMG_Quit();
    SDL_Quit();
}

void Motor::salir()
{
    m_juegoActivo = false;
}

void Motor::actualizar()
{
    //este metodo necesita delegar hacia una interface?
    SDL_Log("Actualizando!");
}

void Motor::renderizar()
{

    SDL_SetRenderDrawColor(m_renderizador,247,229,178,255);
    SDL_RenderClear(m_renderizador); ///Fondo color amarillo arena

    cultivo1.metodo_cargador_de_imagenes();//
    SDL_RenderPresent(m_renderizador);
}

void Motor::eventos()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        salir();
        break;
    case SDL_MOUSEBUTTONDOWN:
        cultivo1.Hacer();
        //cambiar estado
    }
}

Motor::Motor()
{
// cultivo = new Cultivo();
}

void Motor::actualizarEstadoCultivo(Estado_Cultivo* nuevoEstado)
{
    estado_cultivo = nuevoEstado;
}

//objeto a mostrar: ( va a ser un objeto de la clase imagen )
//necesitamos la clase imagen que tenga los atributos: id, direccion, bool cargada, posX, posY, tamX, tamY
