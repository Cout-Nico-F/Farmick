#include "Jugador.h"

Jugador* Jugador::s_instancia = nullptr; //inicializo el puntero a nulo preparandolo para el primer getInstancia

Jugador::Jugador()
{
    m_monedas = 1000; //inicializo monedas en 1000 cuando se crea el objeto de jugador.
    m_semillas = 0;
}

void Jugador::incrementarMonedas(int cuantas)
{
    m_monedas+=cuantas;
}

void Jugador::incrementarSemillas()
{
    m_semillas ++;
}

void Jugador::gastarMonedas(int cuantas)
{
    m_monedas -=cuantas;
}

void Jugador::gastarSemillas()
{
    m_semillas --;
}

int Jugador::getMonedas()
{
    return m_monedas;
}

int Jugador::getSemillas()
{
    return m_semillas;
}


