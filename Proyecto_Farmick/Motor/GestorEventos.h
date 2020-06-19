#ifndef GESTOREVENTOS_H
#define GESTOREVENTOS_H
#include <string>
//#include <map>

class GestorEventos// tambien conocido como InputManager, es la clase que se encarga de escuchar y comunicar las entradas de mouse teclado etc
{
    public:
        static GestorEventos* getInstancia()
        {
            return s_instancia = (s_instancia == nullptr)? new GestorEventos() : s_instancia ;
        }
        GestorEventos();
        ~GestorEventos();
        void clickEnArea(int desdeX, int hastaX, int desdeY, int hastaY, std::string idCultivo);


        //setters
        void setBotonIzq(bool estado);
    protected:

    private:
        int m_evento_x;
        int m_evento_y;
        bool m_botonIzqMouse;
        static GestorEventos* s_instancia;
};

#endif // GESTOREVENTOS_H
