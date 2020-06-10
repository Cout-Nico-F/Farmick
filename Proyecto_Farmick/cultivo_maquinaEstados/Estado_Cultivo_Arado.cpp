#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"
#include "../Motor/gestorTexturas.h"

Estado_Cultivo_Arado::Estado_Cultivo_Arado(Cultivo* contexto): _contexto(contexto)//usa su constructor + el constructor heredado de la clase base
{

};

void Estado_Cultivo_Arado::Hacer()
{
    std::cout<<"Implementacion de Hacer() de Arado"<<std::endl;
    //Cuando el metodo hacer lo implementa estado_cultivo_arado hace algo diferente a cuando hacer es implementado por otra clase de estado ( ej terreno)
    _contexto->setEstado(new Estado_Cultivo_Terreno(_contexto));//En esta linea estamos cambiando de estado hacia terreno.
}

bool Estado_Cultivo_Arado::metodo_cargador_de_imagenes()
{

    if(!cargado) //parche para evitar falla de memoria
    {
        GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
        GestorTexturas::getInstancia()->cargar("terreno","assets/cultivo_arada.png");
        cargado = true;
    }

    GestorTexturas::getInstancia()->dibujar("logoGrande",150,66,728,259);

    GestorTexturas::getInstancia()->dibujar("terreno",428,500,99,50);

    SDL_Delay(3000);
    _contexto->setEstado(new Estado_Cultivo_Arado(_contexto));//En esta linea estamos cambiando de estado hacia terreno.
}

