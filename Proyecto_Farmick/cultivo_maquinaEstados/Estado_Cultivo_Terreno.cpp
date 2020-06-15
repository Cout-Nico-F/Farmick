#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"
#include "gestorTexturas.h"
#include "Motor.h"

Estado_Cultivo_Terreno::Estado_Cultivo_Terreno(Cultivo* contexto) : punteroAcultivo(contexto)
{
   //INFO SOBRE PORQUE SE HACE ESA ASIGNACION EN EL CONSTRUCTOR ESTE EN EL PRIMER COMENTARIO 298LIKES---> https://stackoverflow.com/questions/2785612/c-what-does-the-colon-after-a-constructor-mean
    ///EL constructor esta llamando a su ves al contrusctor de la clase de la que hereda (padre)

}

void Estado_Cultivo_Terreno::hacer()
{
    std::cout<<"Implementacion de Hacer() de Terreno"<<std::endl;
    //a continuacion a modo de prueba se cambia el estado hacia estado arado( en el juego esto se disparara segun hechos o condiciones )

    //    if(condicion)
    GestorTexturas::getInstancia()->borrar("logoGrande");
    GestorTexturas::getInstancia()->borrar("terreno");
    GestorTexturas::getInstancia()->borrar("click");
    Estado_Cultivo* objeto = new Estado_Cultivo_Arado(punteroAcultivo);
    punteroAcultivo->setEstado(objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(objeto);

}

void Estado_Cultivo_Terreno::metodo_cargador_de_imagenes()
    {

        if(!cargado) //para evitar que se carge mas de una vez
        {
            GestorTexturas::getInstancia()->cargar("logoGrande","assets/logo_grande.png");
            GestorTexturas::getInstancia()->cargar("terreno","assets/cultivo_terreno.png");
            GestorTexturas::getInstancia()->cargar("click","assets/click.png");
            cargado = true;
        }

        GestorTexturas::getInstancia()->dibujar("logoGrande",150,66,728,259);
        GestorTexturas::getInstancia()->dibujar("click",391,370,174,70);
        GestorTexturas::getInstancia()->dibujar("terreno",428,500,100,50);

    }

