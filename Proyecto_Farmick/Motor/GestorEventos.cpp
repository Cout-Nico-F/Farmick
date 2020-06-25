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
    m_botonIzqMouse = false;

    if(idCultivo!="0000" && idCultivo!= "mercado")
    {
        if(Jugador::getInstancia()->getMonedas()>=4)
        {
            Jugador::getInstancia()->gastarMonedas(4);
            std::map<std::string,Cultivo*> mapa= Motor::GetInstancia()->getMapa();
            if(mapa[idCultivo]->aumentarProgreso()) mapa[idCultivo]->hacer();
        }
        else
        {
            SDL_Log("Monedas insuficientes, necesitas 10 para pasar de estado");
        }
    }

    if (idCultivo == "mercado")
    {
       if(Jugador::getInstancia()->getMonedas() >= 10)
        {
            Jugador::getInstancia()->gastarMonedas(10);
            Jugador::getInstancia()->incrementarSemillas(); // Aca es donde estamos comprando semillas.
        }
       else
        {
            SDL_Log("Monedas insuficientes, necesitas 10 monedas para comprar un paquete de semillas");
        }
    }

    if ( idCultivo == "0000" )
    {
        Jugador::getInstancia()->incrementarMonedas();
        SDL_Log("Encontraste una moneda");
    }


}
