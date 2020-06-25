#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador//singletone ( en nuestro juego va a existir un solo jugador )
{
    public:
    inline static Jugador* getInstancia(){return s_instancia = (s_instancia == nullptr)? new Jugador() : s_instancia;}
    void incrementarMonedas();
    void gastarMonedas(int cuantas);
    int getMonedas();

    private:
    Jugador(); //constructor privado
    int m_monedas;
    static Jugador* s_instancia;

};

#endif // JUGADOR_H
