#pragma once
#include "Estado_Cultivo.h"
#include "../Motor/Motor.h"
#include "cstring"
#include <iostream>

class Cultivo ///este es nuestro Contexto
{

public:
    Cultivo();
    ~Cultivo();
    Cultivo(std::string id);
    void setEstado (Estado_Cultivo* nuevo_estado);
    void hacer();
    bool aumentarProgreso();
    void metodo_cargador_de_imagenes();
    int getProgreso();
    int getUbicacion_x();
    int getUbicacion_y();
    std::string getIdCultivo();
    void setUbicacion_x(int);
    void setUbicacion_y(int);
    std::string getTextura();
    void setM_mapaTexturas(std::string);

private:
    Estado_Cultivo* estado_actual;//composicion (un cultivo tiene un estado_cultivo)
    int m_ubicacion_x;
    int m_ubicacion_y;
    std::string m_idCultivo;
    std::string m_mapaTexturas;
};




