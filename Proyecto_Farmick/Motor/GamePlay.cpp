#include "GamePlay.h"
#include "../cultivo_maquinaEstados/Cultivo.h"
#include "GestorEventos.h"
#include <math.h>

GamePlay* GamePlay::s_instancia = nullptr;

//tips de brian:
//el gameplay le da mensajes a cultivo (lo hace con un metodo ) leer mensajes relacionado a metodos

//los objetos de cultivo los crea la clase gameplay

GamePlay::GamePlay()
{

}

void GamePlay::aumentarProgresoCultivos()
{
    std::map<std::string,Cultivo*>::iterator iterador;
    std::map<std::string,Cultivo*> mapa= Motor::GetInstancia()->getMapa();

    for(iterador = mapa.begin(); iterador!= mapa.end(); iterador++)
    {
        if(strcmp(iterador->second->getTextura().c_str(),"a13")>0 &&
           strcmp(iterador->second->getTextura().c_str(),"a24")<0)
        {
            GestorEventos::getInstancia()->clickEnArea(iterador->first);
        }
    }
}

void GamePlay::crearCultivos()
{
    //Se crea la Matriz de posiciones en el mapa

    int matrizPosiciones[cantidadCultivos][2]={0};
    int x=posXcultivos;
    int y=posYcultivos;
    short maxiterador=sqrt(cantidadCultivos);
    for(int i=0;i<maxiterador;i++)
    {
        for(int j=0;j<maxiterador;j++)
        {
            matrizPosiciones[i*maxiterador+j][0]=x;
            matrizPosiciones[i*maxiterador+j][1]=y;
            x+=50;
            y-=25;
        }
        y+=(25*maxiterador+25)-2;
        x-=(50*maxiterador-50)+2;
    }

    //Se crean los objetos cultivo en las coordenadas seteadas previamente

    for(int i=0;i<cantidadCultivos;i++)
    {
        std::string nombreCultivo = "CULTIVO_" + std::to_string(i+1);
        Cultivo* cultivoX = new Cultivo(nombreCultivo);
        Motor::GetInstancia()->setMapa(cultivoX->getIdCultivo(),cultivoX);
        cultivoX->setUbicacion_x(matrizPosiciones[i][0]);
        cultivoX->setUbicacion_y(matrizPosiciones[i][1]);
    }
}
