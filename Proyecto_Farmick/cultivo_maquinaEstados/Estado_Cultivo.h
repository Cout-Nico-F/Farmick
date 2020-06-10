#ifndef ESTADO_CULTIVO_H
#define ESTADO_CULTIVO_H


class Estado_Cultivo ///interface ( tiene metodos virtuales declarados pero no definidos o implementados )
{
    public:
    virtual void hacer() = 0;//igualar metodos a cero es la forma de definir una interface
    virtual bool metodo_cargador_de_imagenes()=0;
    Estado_Cultivo(){};//Este constructor es necesario?

};

#endif // ESTADO_CULTIVO_H
