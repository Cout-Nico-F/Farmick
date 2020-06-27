#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../cultivo_maquinaEstados/Cultivo.h"
#include "SDL_ttf.h"
#include <map>

#define ANCHO_PANTALLA 901 ///resolucion actual 1024x768
#define ALTO_PANTALLA 676

///Usamos m_ en los miembros de clase (atributos) para reconocerlos rapidamente.
///Usamos s_ para diferenciar los atributos estaticos.
class Cultivo;
class Motor ///Singletone ( solo puede existir una instancia de esta clase a la vez )
{
    public:
        static Motor* GetInstancia()//pasar a camelCase
        {
            return s_instancia = (s_instancia == nullptr)? new Motor() : s_instancia;
        }
        bool inicializar();
        bool limpiar();
        void salir();
        void actualizar();
        void renderizar();
        void eventos();

        bool metodo_cargador_de_imagenes();
        void indicadorMonedas();
        void indicadorSemillas();
        void mensajes();
        void actualizarEstadoCultivo(Estado_Cultivo* nuevoEstado);
        Cultivo* getCultivo(std::string idCultivo);
        std::string buscarEnMapa();

        std::map<std::string, Cultivo*> getMapa();
        void setMapa(std::string, Cultivo*);

        void crearCultivos();
        void borrarCultivos();

        inline bool juegoActivo() {return m_juegoActivo;}
        inline SDL_Renderer* getRenderizador(){return m_renderizador;}

    protected:

    private:
        Motor();///el constructor es privado porque sino cualquiera podria crear instancias de engine
        static Motor* s_instancia;///motor es estatico y debe vivir durante todo el programa
        bool m_juegoActivo;
        SDL_Window* m_ventana;
        SDL_Renderer* m_renderizador;
        Estado_Cultivo* estado_cultivo;

        TTF_Font * m_fuente;
        SDL_Surface * m_superficie;
        SDL_Texture* m_textura;
        std::map<std::string, Cultivo*> m_mapaCultivos;
};

