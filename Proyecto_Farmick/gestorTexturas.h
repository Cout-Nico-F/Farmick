#pragma once
#include <string>
#include "SDL.h"
#include <map>


class GestorTexturas ///singletone ( solo necesitamos un encargado de texturas
{
public:
    static GestorTexturas* getInstancia()
    {
        return s_instancia = (s_instancia == nullptr)? new GestorTexturas() : s_instancia;
    }
    bool cargar(std::string id, std::string nombreArchivo);
    bool borrar(std::string id);
    bool limpiar();
    void dibujar(std::string id, int x, int y,int ancho, int alto, SDL_RendererFlip flip=SDL_FLIP_NONE);

protected:

private:
    GestorTexturas();///el constructor es privado porque sino cualquiera podria crear instancias
    static GestorTexturas* s_instancia;
    std::map <std::string,SDL_texture*> m_mapaTexturas;
};



