#ifndef GAMEPLAY_H
#define GAMEPLAY_H


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



    protected:

    private:

        static GamePlay* s_instancia;

};

#endif // GAMEPLAY_H
