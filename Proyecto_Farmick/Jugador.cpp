#include "Jugador.h"

Jugador* Jugador::s_instancia = nullptr; //inicializo el puntero a nulo preparandolo para el primer getInstancia

Jugador::Jugador()
{
    m_monedas = 1000; //inicializo monedas en 1000 cuando se crea el objeto de jugador.
}

void Jugador::incrementarMonedas()
{
    m_monedas++;

}
void Jugador::gastarMonedas(int cuantas)
{
    m_monedas -=cuantas;
}

int Jugador::getMonedas()
{
    return m_monedas;
}

