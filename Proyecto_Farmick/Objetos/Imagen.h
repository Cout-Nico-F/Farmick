#ifndef IMAGEN_H
#define IMAGEN_H

#include <ObjetoDelJuego.h>


class Imagen : public ObjetoDelJuego
{
    public:
        Imagen();
        ~Imagen();


    protected:

    private:
        std::string m_dir;
        //la posicion la sabe el objeto de cultivo (ej cultivo1)
};

#endif // IMAGEN_H
