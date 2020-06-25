#include "Mercado.h"
#include "gestorTexturas.h"

Mercado* Mercado::s_instancia = nullptr;

Mercado::Mercado()
{
    //ctor
}

void Mercado::vender()
{

}

void Mercado::dibujar()
{
    GestorTexturas::getInstancia()->dibujar("mercado",650,390,93,71);
}
