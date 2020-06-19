#ifndef GESTOREVENTOS_H
#define GESTOREVENTOS_H
#include <string>
#include <map>

class GestorEventos// tambien conocido como InputManager, es la clase que se encarga de escuchar y comunicar las entradas de mouse teclado etc
{
    public:
        GestorEventos();
        ~GestorEventos();
        void clickEnArea(int desdeX, int hastaX, int desdeY, int hastaY, std::string idCultivo);


    protected:

    private:
        int m_evento_x;
        int m_evento_y;
        bool m_botonIzqMouse;
        std::map* m_mapaCultivos;
};

#endif // GESTOREVENTOS_H
