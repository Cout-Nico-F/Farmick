#include "GestorEventos.h"
#include "gestorTexturas.h"
#include "../Jugador.h"
#include "SDL.h"
#include "Motor.h"
#include "GamePlay.h"


GestorEventos* GestorEventos::s_instancia = nullptr;

GestorEventos::GestorEventos()
{
    //ctor
}

GestorEventos::~GestorEventos()
{
    //dtor
}

//setters
void GestorEventos::setEventoX(int eventoX)
{
    this->m_evento_x = eventoX;
}

void GestorEventos::setEventoY(int eventoY)
{
    this->m_evento_y = eventoY;
}

void GestorEventos::setBotonIzq(bool estado)
{
    this->m_botonIzqMouse = estado;
}
//getters

int GestorEventos::getX()
{
    return m_evento_x;
}

int GestorEventos::getY()
{
    return m_evento_y;
}

bool GestorEventos::getBotonIzq()
{
    return m_botonIzqMouse;
}

void GestorEventos::clickEnArea(std::string idCultivo)
{
    m_botonIzqMouse = false;

    if(idCultivo!="0000" && idCultivo!= "mercado")
    {
        std::map<std::string,Cultivo*> mapa= Motor::GetInstancia()->getMapa();
        int progreso = mapa[idCultivo]->getProgreso();
        if(mapa[idCultivo]->aumentarProgreso())
        {
            mapa[idCultivo]->hacer();
        }
        else if(mapa[idCultivo]->getProgreso()>progreso)
        {
            std::map <std::string,SDL_Texture*>::iterator iterador;
            iterador = GestorTexturas::getInstancia()->getMapaTexturas().find(mapa[idCultivo]->getTextura());
            iterador++;
            mapa[idCultivo]->setM_mapaTexturas(iterador->first);
        }
    }

    if (idCultivo == "mercado")
    {
       if(Jugador::getInstancia()->getMonedas() >= 10)
        {
            Jugador::getInstancia()->gastarMonedas(10);
            Jugador::getInstancia()->incrementarSemillas();
            GamePlay::getInstancia()->setMensajes("Compraste un paquete de semillas por 10 monedas"); // Aca es donde estamos comprando semillas.
        }
       else
        {
            GamePlay::getInstancia()->setMensajes("Monedas insuficientes, necesitas 10 monedas para comprar un paquete de semillas");
            SDL_Log("Monedas insuficientes, necesitas 10 monedas para comprar un paquete de semillas");
        }
    }

    if ( idCultivo == "0000" )
    {
        Jugador::getInstancia()->incrementarMonedas(1);
        GamePlay::getInstancia()->setMensajes("Encontraste una moneda");
        SDL_Log("Encontraste una moneda");
    }
}
