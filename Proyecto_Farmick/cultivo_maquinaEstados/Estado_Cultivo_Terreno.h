#ifndef ESTADO_CULTIVO_TERRENO_H
#define ESTADO_CULTIVO_TERRENO_H
#include "Cultivo.h"
#include "Estado_Cultivo.h"

///estado concreto: terreno (sin arar)
class Estado_Cultivo_Terreno : public Estado_Cultivo ///Estado N en concreto (Estado Terreno)
{
private:
    Cultivo* _contexto;//referencia a cultivo
//estado_cultivo_terreno tiene un cultivo ( composicion usada para cerrar el circulo de la maquina finita de estados )
public:
    Estado_Cultivo_Terreno(Cultivo* contexto);
    void Hacer()override; //sobrecarga

};

#endif // ESTADO_CULTIVO_TERRENO_H
