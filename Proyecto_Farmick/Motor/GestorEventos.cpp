#include "GestorEventos.h"
#include "../Jugador.h"
#include "SDL.h"
#include "Motor.h"


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
    m_botonIzqMouse = false; /// Esto lo corrí aca porque estaba en todos los casos de los if

    if(idCultivo!="0000")
    {
        if(Jugador::getInstancia()->getMonedas()>=4)
        {
            Jugador::getInstancia()->gastarMonedas(4);
            std::map<std::string,Cultivo*> mapa= Motor::GetInstancia()->getMapa();
            if(mapa[idCultivo]->aumentarProgreso()) mapa[idCultivo]->hacer();
        }
        else
        {
            SDL_Log("Monedas insuficientes, necesitas 10");
        }
    }
    else
    {
        Jugador::getInstancia()->incrementarMonedas();
        SDL_Log("Encontraste una moneda");
    }
}
