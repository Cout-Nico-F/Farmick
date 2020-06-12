#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador//singletone ( en nuestro juego va a existir un solo jugador )
{
    public:
    inline static Jugador* getInstancia(){return s_instancia = (s_instancia == nullptr)? new Jugador() : s_instancia;}

    private:
    Jugador(); //constructor privado
    int _monedas;
    static Jugador* s_instancia;

};

#endif // JUGADOR_H
