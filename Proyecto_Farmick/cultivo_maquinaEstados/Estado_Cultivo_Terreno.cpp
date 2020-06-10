#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"
#include "gestorTexturas.h"
#include "Motor.h"

Estado_Cultivo_Terreno::Estado_Cultivo_Terreno(Cultivo* contexto) : punteroAcultivo(contexto)
{

    ///EL constructor esta llamando a su ves al contrusctor de la clase de la que hereda (padre)

}

void Estado_Cultivo_Terreno::Hacer()
{
    std::cout<<"Implementacion de Hacer() de Terreno"<<std::endl;
    //a continuacion a modo de prueba se cambia el estado hacia estado arado( en el juego esto se disparara segun hechos o condiciones )

    //    if(si hizo click)
    Estado_Cultivo* objeto = new Estado_Cultivo_Arado(punteroAcultivo);
    punteroAcultivo->setEstado(objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(objeto);

}

bool Estado_Cultivo_Terreno::metodo_cargador_de_imagenes()
    {

        if(!cargado) //para evitar falla de memoria
        {
            GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
            GestorTexturas::getInstancia()->cargar("terreno","assets/cultivo_terreno.png");
            cargado = true;
        }

        GestorTexturas::getInstancia()->dibujar("logoGrande",150,66,728,259);

        GestorTexturas::getInstancia()->dibujar("terreno",428,500,99,50);
        //SDL_Delay(1000);
    }

