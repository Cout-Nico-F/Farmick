#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>

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




        void crearCultivos();
        void aumentarProgresoCultivos();
        void setMensajes(std::string mensaje){m_mensajes = mensaje;}
        std::string getMensajes(){return m_mensajes;}


    protected:

    private:
        GamePlay();
        static GamePlay* s_instancia;
        std::string m_mensajes;

};

#endif // GAMEPLAY_H
