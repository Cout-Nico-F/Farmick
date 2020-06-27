#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define posXcultivos 200
#define posYcultivos 475
#define cantidadCultivos 25 // debe ser un numero resultante de n al cuadrado (1,4,9,16,25...)

class GamePlay //clase que va a tener las acciones ( metodos que segun si se cumple o no validaciones permitiran las acciones de los actores. )
{
    public:
        static GamePlay* getInstancia()
        {
            return s_instancia = (s_instancia == nullptr)? new GamePlay() : s_instancia;
        }

        GamePlay();
        ~GamePlay();

        void crearCultivos();
        void aumentarProgresoCultivos();


    protected:

    private:

        static GamePlay* s_instancia;

};

#endif // GAMEPLAY_H
