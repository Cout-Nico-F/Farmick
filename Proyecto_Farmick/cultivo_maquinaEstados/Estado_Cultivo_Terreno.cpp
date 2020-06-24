#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"
#include "gestorTexturas.h"
#include "Motor.h"

Estado_Cultivo_Terreno::Estado_Cultivo_Terreno(Cultivo* contexto) : punteroAcultivo(contexto)
{
   //INFO SOBRE PORQUE SE HACE ESA ASIGNACION EN EL CONSTRUCTOR ESTE EN EL PRIMER COMENTARIO 298LIKES---> https://stackoverflow.com/questions/2785612/c-what-does-the-colon-after-a-constructor-mean


}

void Estado_Cultivo_Terreno::hacer()
{
    std::cout<<"Terreno cambiando de estado hacia Arado"<<std::endl;
    //a continuacion a modo de prueba se cambia el estado hacia estado arado( en el juego esto se disparara segun hechos o condiciones )

    //    if(condicion)
    //GestorTexturas::getInstancia()->borrar("logoGrande");
    //GestorTexturas::getInstancia()->borrar("terreno");
    //GestorTexturas::getInstancia()->borrar("click");
    _objeto = new Estado_Cultivo_Arado(punteroAcultivo);
    punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);

}

void Estado_Cultivo_Terreno::metodo_cargador_de_imagenes(/*int pos_x, int pos_y*/)//recibe donde           //este metodo esta mal, porque sirve para un solo objeto de la clase terreno
    {

       // if(!cargado) //para evitar que se carge mas de una vez
       // {
            //Imagen* terreno = new Imagen();
                                                //( terreno->getId(), terreno->getDir() ); donde terreno es un puntero a la imagen terreno.

       //     cargado = true;
       // }

        GestorTexturas::getInstancia()->dibujar("logoGrande",120,66,728,259);
        GestorTexturas::getInstancia()->dibujar("click",591,570,174,70);
        //GestorTexturas::getInstancia()->dibujar("terreno",428,500,100,50); /// Lo cambiamos por el de abajo que tiene los getUbicación
        GestorTexturas::getInstancia()->dibujar("terreno",punteroAcultivo->getUbicacion_x(),punteroAcultivo->getUbicacion_y(),100,50);

        //GestorTexturas::getInstancia()->dibujar("terreno",Cultivo::getUbicacion_x(),Cultivo::getUbicacion_y(),100,50);
        //Para Ubicacion de X e Y de varios terrenos
    }

