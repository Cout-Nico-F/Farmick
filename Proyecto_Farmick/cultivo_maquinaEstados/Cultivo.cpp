#include "Cultivo.h"
#include "Estado_Cultivo_Terreno.h"
#include "../Motor/Motor.h"

Cultivo::Cultivo()
{
    estado_actual = new Estado_Cultivo_Terreno(this);//al construir un objeto se setea en el estado inicial: terreno
    //constructor
}

Cultivo::Cultivo(std::string id)
{
    estado_actual = new Estado_Cultivo_Terreno(this);
    m_idCultivo = id;
    m_mapaTexturas= "a00terreno";
}

std::string Cultivo::getTextura()
{
    return m_mapaTexturas;
}

Cultivo::~Cultivo()
{
    delete estado_actual;
}//el compilador nos avisa que esto puede traer comportamientos indefinidos(no deseados).

void Cultivo::setEstado(Estado_Cultivo* nuevo_estado)
{
    estado_actual = nuevo_estado;
}

void Cultivo::setM_mapaTexturas(std::string mapa)
{
    m_mapaTexturas=mapa;
}

int Cultivo::getProgreso()
{
    estado_actual->getProgreso();
}

bool Cultivo::aumentarProgreso()
{
    //delegacion.
    if(estado_actual->aumentarProgreso()) return true;
return false;
}

void Cultivo::hacer()
{
    //delegacion.
    estado_actual->hacer();
}

void Cultivo::metodo_cargador_de_imagenes()
{

    //delegacion
    estado_actual-> metodo_cargador_de_imagenes();
}

int Cultivo::getUbicacion_x()
{
    return m_ubicacion_x;
}

int Cultivo::getUbicacion_y()
{
    return m_ubicacion_y;
}

std::string Cultivo::getIdCultivo()
{
    return m_idCultivo;
}

void Cultivo::setUbicacion_x(int x)
{
    m_ubicacion_x=x;
}

void Cultivo::setUbicacion_y(int y)
{
    m_ubicacion_y=y;
}
