#include "Motor.h"

Motor* Motor::s_instancia = nullptr;

bool Motor::inicializar()
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!=0)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    m_window = SDL_CreateWindow("Titulo de la ventana",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    if(m_window == nullptr)
    {
        SDL_Log("Failed to create Window: %s",SDL_GetError());
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_window,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_renderer == nullptr)
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

}

void Motor::salir()
{

}

void Motor::actualizar()
{

}

void Motor::Renderizar()
{

}

void Motor::Eventos()
{

}

Motor::Motor()
{

}
