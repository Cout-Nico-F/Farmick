#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"
#include "../Motor/gestorTexturas.h"

Estado_Cultivo_Arado::Estado_Cultivo_Arado(Cultivo* contexto): _punteroAcultivo(contexto)//(esta inicializando el atributo)
{
 //_contexto(contexto) esto es lo mismo que: _contexto = contexto;
};

void Estado_Cultivo_Arado::hacer()
{
    std::cout<<"Implementacion de Hacer() de Arado"<<std::endl;
    //Cuando el metodo hacer lo implementa estado_cultivo_arado hace algo diferente a cuando hacer es implementado por otra clase de estado ( ej terreno)
    Estado_Cultivo* objeto = new Estado_Cultivo_Terreno(_punteroAcultivo);
    _punteroAcultivo->setEstado(objeto);//En esta linea estamos cambiando de estado hacia terreno.
    Motor::GetInstancia()->actualizarEstadoCultivo(objeto);
}

void Estado_Cultivo_Arado::metodo_cargador_de_imagenes()
{

    if(!cargado) //para evitar falla de memoria
    {
        GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
        GestorTexturas::getInstancia()->cargar("arada","assets/cultivo_arada.png");
        cargado = true;
    }

    GestorTexturas::getInstancia()->dibujar("logoGrande",150,66,728,259);

    GestorTexturas::getInstancia()->dibujar("arada",428,500,99,50);

}

