#include "Jugador.h"

Jugador* Jugador::s_instancia = nullptr; //inicializo el puntero a nulo preparandolo para el primer getInstancia

Jugador::Jugador()
{
    _monedas = 0; //inicializo monedas en cero cuando se crea el objeto de jugador.
}
