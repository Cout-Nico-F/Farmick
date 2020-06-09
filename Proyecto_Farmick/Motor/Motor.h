#pragma once
#include "SDL.h"
#include "SDL_image.h"

#define ANCHO_PANTALLA 1024 ///resolucion actual 1024x768
#define ALTO_PANTALLA 768

///Usamos m_ en los miembros de clase (atributos) para reconocerlos rapidamente.
///Usamos s_ para diferenciar los atributos estaticos.

class Motor ///Singletone ( solo puede existir una instancia de esta clase a la vez )
{
    public:
        static Motor* GetInstancia()
        {
            return s_instancia = (s_instancia == nullptr)? new Motor() : s_instancia;
        }
        bool inicializar();
        bool limpiar();
        void salir();
        void actualizar();
        void renderizar();
        void eventos();

        bool metodo_cargador_de_imagenes();//metodo de prueba

        inline bool juegoActivo() {return m_juegoActivo;}
        inline SDL_Renderer* getRenderizador(){return m_renderizador;}

    protected:

    private:
        Motor();///el constructor es privado porque sino cualquiera podria crear instancias de engine
        static Motor* s_instancia;///motor es estatico y debe vivir durante todo el programa
        bool m_juegoActivo;
        SDL_Window* m_ventana;
        SDL_Renderer* m_renderizador;
        bool cargado = false;//parche usado en motor::renderizar
};

