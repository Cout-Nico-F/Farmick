#include "GestorEventos.h"
#include "../Jugador.h"
#include "SDL.h"
#include "Motor.h"
//tengo cierta desconfianza en la linea 4.Se ejecuta una sola vez?
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
//setters

bool GestorEventos::getBotonIzq()
{
    return m_botonIzqMouse;
}

void GestorEventos::clickEnArea(int desdeX, int hastaX, int desdeY, int hastaY, std::string idCultivo)
{
    if(m_evento_x >=desdeX && m_evento_x <= hastaX && m_evento_y >= desdeY && m_evento_y <= hastaY)//defino el area
    {
        if(Jugador::getInstancia()->getMonedas()>=10)
        {
            Jugador::getInstancia()->gastarMonedas(10);
            Motor::GetInstancia()->getCultivo(idCultivo)->hacer();
            m_botonIzqMouse = false;
        }
        else
        {
            SDL_Log("Monedas insuficientes, necesitas 10");
            m_botonIzqMouse = false;
        }
    }
    else
    {
        Jugador::getInstancia()->incrementarMonedas();
        SDL_Log("Encontraste una moneda");
        m_botonIzqMouse = false;
    }
}
