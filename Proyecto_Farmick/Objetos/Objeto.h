#ifndef OBJETO_H
#define OBJETO_H


class Objeto //interface
{
    public:
        virtual void Dibujar()=0;
        virtual void Actualizar(float deltaTiempo)=0;
        virtual void Limpiar()=0;

    protected:

    private:
};

#endif // OBJETO_H
