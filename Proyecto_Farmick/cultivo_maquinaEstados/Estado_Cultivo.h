#ifndef ESTADO_CULTIVO_H
#define ESTADO_CULTIVO_H


class Estado_Cultivo ///interface ( tiene metodos virtuales declarados pero no definidos o implementados )
{
    public:
    virtual void Hacer() = 0;//igualar metodos a cero es la forma de definir una interface
    Estado_Cultivo(){};//Este constructor es necesario?

};

#endif // ESTADO_CULTIVO_H
