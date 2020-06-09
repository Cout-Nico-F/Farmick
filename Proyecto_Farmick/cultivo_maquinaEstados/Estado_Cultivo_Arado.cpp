#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"

Estado_Cultivo_Arado::Estado_Cultivo_Arado(Cultivo* contexto): _contexto(contexto)//usa su constructor + el constructor heredado de la clase base
{

};

void Estado_Cultivo_Arado::Hacer()     //sobrecarga de metodo
{
    std::cout<<"Implementacion de Hacer() de Arado"<<std::endl;
    //Cuando el metodo hacer lo implementa estado_cultivo_arado hace algo diferente a cuando hacer es implementado por otra clase de estado ( ej terreno)
    _contexto->setEstado(new Estado_Cultivo_Terreno(_contexto));//En esta linea estamos cambiando de estado hacia terreno.
}

