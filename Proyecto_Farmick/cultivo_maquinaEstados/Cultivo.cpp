#include "Cultivo.h"
#include "Estado_Cultivo_Terreno.h"

Cultivo::Cultivo()
{
    estado_actual = new Estado_Cultivo_Terreno(this);//al construir un objeto se setea en el estado inicial: terreno
    //ctor
}

void Cultivo::setEstado(Estado_Cultivo* nuevo_estado)
{
    estado_actual = nuevo_estado;
}

void Cultivo::Hacer()
{
    estado_actual->Hacer();
}
