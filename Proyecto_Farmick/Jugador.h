#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador//singletone ( en nuestro juego va a existir un solo jugador )
{
    public:
    inline static Jugador* getInstancia(){return s_instancia = (s_instancia == nullptr)? new Jugador() : s_instancia;}
    void incrementarMonedas();
    void incrementarSemillas();
    void gastarMonedas(int cuantas);
    void gastarSemillas();
    int getMonedas();
    int getSemillas();

    private:
    Jugador(); //constructor privado
    int m_monedas;
    int m_semillas;
    static Jugador* s_instancia;

};

#endif // JUGADOR_H
