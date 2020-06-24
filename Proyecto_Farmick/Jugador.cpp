#include "Jugador.h"

Jugador* Jugador::s_instancia = nullptr; //inicializo el puntero a nulo preparandolo para el primer getInstancia

Jugador::Jugador()
{
    _monedas = 110; //inicializo monedas en cero cuando se crea el objeto de jugador.
}

void Jugador::incrementarMonedas()
{
    _monedas++;

}
void Jugador::gastarMonedas(int cuantas)
{
    _monedas -=cuantas;
}

int Jugador::getMonedas()
{
    return _monedas;
}

