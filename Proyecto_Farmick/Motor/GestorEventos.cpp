#include "GestorEventos.h"
#include "../Jugador.h"

GestorEventos::GestorEventos()
{

    //ctor
}

GestorEventos::~GestorEventos()
{
    //dtor
}

void GestorEventos::clickEnArea(int desdeX, int hastaX, int desdeY, int hastaY, std::string idCultivo)
{
    if(m_evento_x >=desdeX && m_evento_x <= hastaX && m_evento_y >= desdeY && m_evento_y <= hastaY)//defino el area
    {
        if(Jugador::getInstancia()->getMonedas()>=10)
        {
            Jugador::getInstancia()->gastarMonedas(10);

            m_mapaCultivos[idCultivo]->hacer();
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
