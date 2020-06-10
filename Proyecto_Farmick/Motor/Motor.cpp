#include "Motor.h"
#include "gestorTexturas.h"

Cultivo cultivo1;//a modo de prueba de la maquina de estados de cultivo:

//bool Motor::metodo_cargador_de_imagenes()
//{
//if(!cargado) //parche para evitar falla de memoria
//    {
//        GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
//        GestorTexturas::getInstancia()->cargar("terreno","assets/cultivo_terreno.png");
//        cargado = true;
//    }
//
//    GestorTexturas::getInstancia()->dibujar("logoGrande",150,66,728,259);
//
//    GestorTexturas::getInstancia()->dibujar("terreno",428,500,99,50);
//}

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

        //a modo de prueba de la maquina de estados de cultivo:
        cultivo1.Hacer();
}

void Motor::renderizar()
{
    SDL_SetRenderDrawColor(m_renderizador,247,229,178,255);
    SDL_RenderClear(m_renderizador); ///Fondo color amarillo arena
    //metodo_cargador_de_imagenes(/*necesita recibir el objeto a mostrar*/);///metodo de prueba
    Estado_Cultivo-> metodo_cargador_de_imagenes();
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
   // case SDL_MOUSEBUTTONDOWN
    }
}

Motor::Motor()
{
// cultivo = new Cultivo();
}

//objeto a mostrar: ( va a ser un objeto de la clase imagen )
//necesitamos la clase imagen que tenga los atributos: id, direccion, bool cargada, posX, posY, tamX, tamY

/*
if(!cargado) //parche para evitar falla de memoria
    {
        GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
        GestorTexturas::getInstancia()->cargar("terreno","assets/cultivo_terreno.png");
        cargado = true;
    }

    GestorTexturas::getInstancia()->dibujar("logoGrande",150,66,728,259);

    GestorTexturas::getInstancia()->dibujar("terreno",428,500,99,50);

*/
void actualizarEstadoCultivo(Cultivo * nuevoEstado)
{
    Estado_Cultivo = nuevoEstado;
}
