#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"

Estado_Cultivo_Terreno::Estado_Cultivo_Terreno(Cultivo* contexto) : _contexto(contexto)
{
    ///EL constructor esta llamando a su ves al contrusctor de la clase de la que hereda (padre)
}

void Estado_Cultivo_Terreno::Hacer()
{
    std::cout<<"Implementacion de Hacer() de Terreno"<<std::endl;
    //a continuacion a modo de prueba se cambia el estado hacia estado arado( en el juego esto se disparara segun hechos o condiciones )
    _contexto->setEstado(new Estado_Cultivo_Arado(_contexto));
}



