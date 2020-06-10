#include "Cultivo.h"
#include "Estado_Cultivo_Terreno.h"
#include "Motor.h"

Cultivo::Cultivo()
{
    estado_actual = new Estado_Cultivo_Terreno(this);//al construir un objeto se setea en el estado inicial: terreno
    //constructor
}

void Cultivo::setEstado(Estado_Cultivo* nuevo_estado)
{
    estado_actual = nuevo_estado;
}

void Cultivo::Hacer()
{
    //delegacion.

    estado_actual->Hacer();
}

bool Cultivo::metodo_cargador_de_imagenes()
{

    //delegacion
    estado_actual-> metodo_cargador_de_imagenes();
}
