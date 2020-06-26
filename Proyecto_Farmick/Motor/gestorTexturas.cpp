#include "gestorTexturas.h"
#include "Motor.h"

GestorTexturas* GestorTexturas::s_instancia = nullptr; //necesitamos entender un poco mejor esta linea

GestorTexturas::GestorTexturas()
{

}

bool GestorTexturas::cargar_cultivos()
{
    this->cargar("a00terreno","assets/cultivo_terreno.png");
    this->cargar("a01terreno1","assets/tierra para arar1.png");
    this->cargar("a02terreno2","assets/tierra para arar2.png");
    this->cargar("a03terreno3","assets/tierra para arar3.png");
    this->cargar("a04terreno4","assets/tierra para arar4.png");
    this->cargar("a05terreno5","assets/tierra para arar5.png");
    this->cargar("a06terreno6","assets/tierra para arar6.png");
    this->cargar("a07arado","assets/arado1.png");
    this->cargar("a08arado","assets/arado2.png");
    this->cargar("a09arado","assets/arado3.png");
    this->cargar("a10arado","assets/arado4.png");
    this->cargar("a11arado","assets/arado5.png");
    this->cargar("a12arado","assets/arado6.png");
    this->cargar("a13sembrado","assets/tierraplantada1.png");
    this->cargar("a14sembrado","assets/tierraplantada2.png");
    this->cargar("a15sembrado","assets/tierraplantada3.png");
    this->cargar("a16sembrado","assets/tierraplantada4.png");
    this->cargar("a17sembrado","assets/tierraplantada5.png");
    this->cargar("a18sembrado","assets/tierraplantada6.png");

    this->cargar("a90crecido","assets/cultivo_crecido.png");
}

bool GestorTexturas::cargar(std::string id, std::string nombreArchivo)
{
    //leer el patron de recursos (resourse) recomendacion de brian

    //debe preguntar si ya esta cargada ( si piden cargar con un id de recurso que todavia no existe)
    //se guarda una lista de imagenes para comprobar si ya esta cargado. si ya esta cargado devuelve un recurso ( un puntero al buffer de texturas)

    SDL_Surface* superficie = IMG_Load(nombreArchivo.c_str());
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

std::map <std::string,SDL_Texture*> GestorTexturas::getMapaTexturas()
{
    return m_mapaTexturas;
}

bool GestorTexturas::borrar(std::string id)
{
    SDL_DestroyTexture(m_mapaTexturas[id]);
    //SDL_FreeSurface();
    m_mapaTexturas.erase(id);

return true;
}

bool GestorTexturas::limpiar()
{
    std::map<std::string,SDL_Texture*>::iterator iterador;
    for(iterador = m_mapaTexturas.begin();iterador!=m_mapaTexturas.end();iterador++)
    {
        SDL_DestroyTexture(iterador->second);//a que atributo del iterador esta accediendo? no aparece en la doc de cplusplus (solucionado: leer link)
    }
    ///https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean
    //basicamente second se refiere al segundo parametro del iterador, tiene 2 uno es el id y el otro es el puntero por eso le decimos delete(puntero)
    m_mapaTexturas.clear();
    SDL_Log("Mapa de texturas se ha limpiado correctamente");
return true;
}

void GestorTexturas::dibujar(std::string id, int x, int y, int ancho, int alto, SDL_RendererFlip flip)
{
    SDL_Rect rectFuente = {0, 0, ancho, alto};
    SDL_Rect rectDestino= {x, y, ancho, alto};
    SDL_RenderCopyEx(Motor::GetInstancia()->getRenderizador(), m_mapaTexturas[id], &rectFuente, &rectDestino, 0,nullptr, flip);
}
