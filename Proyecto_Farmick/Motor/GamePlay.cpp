#include "GamePlay.h"
#include "../cultivo_maquinaEstados/Cultivo.h"

GamePlay* GamePlay::s_instancia = nullptr;

//tips de brian:
//el gameplay le da mensajes a cultivo (lo hace con un metodo ) leer mensajes relacionado a metodos

//los objetos de cultivo los crea la clase gameplay

GamePlay::GamePlay()
{
    //ctor
}

GamePlay::~GamePlay()
{
    //dtor
}

void GamePlay::aumentarProgresoCultivoSembrado()
{
    std::map<std::string,Cultivo*>::iterator iterador;
    std::map<std::string,Cultivo*> mapa= Motor::GetInstancia()->getMapa();

    for(iterador = mapa.begin(); iterador!= mapa.end(); iterador++)
    {
        if(strcmp(iterador->second->getTextura().c_str(),"a13")>0 &&
           strcmp(iterador->second->getTextura().c_str(),"a19")<0)
        {
            iterador->second->aumentarProgreso();
        }
    }
}

void GamePlay::crearCultivos()
{
    //Se crea la Matriz de posiciones en el mapa

    int matrizPosiciones[25][2]={0};
    int x=200;
    int y=475;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            matrizPosiciones[i*5+j][0]=x;
            matrizPosiciones[i*5+j][1]=y;
            x+=50;
            y-=25;
        }
        y+=148;
        x-=202;
    }

    //Se crean los objetos cultivo en las coordenadas seteadas previamente

    for(int i=0;i<25;i++)
    {
        std::string nombreCultivo = "CULTIVO_" + std::to_string(i+1);
        Cultivo* cultivoX = new Cultivo(nombreCultivo);//a modo de prueba de la maquina de estados de cultivo.
        Motor::GetInstancia()->setMapa(cultivoX->getIdCultivo(),cultivoX);
        cultivoX->setUbicacion_x(matrizPosiciones[i][0]);
        cultivoX->setUbicacion_y(matrizPosiciones[i][1]);
    }
}
