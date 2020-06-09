#include "gestorTexturas.h"
#include "Motor.h"

GestorTexturas* GestorTexturas::s_instancia = nullptr; //necesitamos entender un poco mejor esta linea

bool GestorTexturas::cargar(std::string id, std::string nombreArchivo)
{
    SDL_Surface* superficie = IMG_Load(nombreArchivo.c_str());//que funcion es c_str?
    if(superficie==nullptr)
    {
        SDL_Log("Fallo al cargar la textura: %s, %s", nombreArchivo.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* textura =  SDL_CreateTextureFromSurface(Motor::GetInstancia()->getRenderizador(),superficie);
    if(textura==nullptr)
    {
        SDL_Log("Fallo al crear la textura: %s", SDL_GetError());
        return false;
    }
    m_mapaTexturas[id] = textura;
    return true;
}

bool GestorTexturas::borrar(std::string id)
{
    SDL_DestroyTexture(m_mapaTexturas[id]);
    m_mapaTexturas.erase(id);
}

bool GestorTexturas::limpiar()
{
    std::map<std::string,SDL_Texture*>::iterator iterador;
    for(iterador = m_mapaTexturas.begin();iterador!=m_mapaTexturas.end();iterador++)
    {
        SDL_DestroyTexture(iterador->second);//a que atributo del iterador esta accediendo? no aparece en la doc de cplusplus
    }
    m_mapaTexturas.clear();
    SDL_Log("Mapa de texturas se ha limpiado correctamente");
}

void GestorTexturas::dibujar(std::string id, int x, int y, int ancho, int alto, SDL_RendererFlip flip)
{
    SDL_Rect rectFuente = {0, 0, ancho, alto};
    SDL_Rect rectDestino= {x, y, ancho, alto};
    SDL_RenderCopyEx(Motor::GetInstancia()->getRenderizador(), m_mapaTexturas[id], &rectFuente, &rectDestino, 0,nullptr, flip);
}

GestorTexturas::GestorTexturas()
{
    //constructor
}
