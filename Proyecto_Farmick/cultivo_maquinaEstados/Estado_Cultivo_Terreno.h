#ifndef ESTADO_CULTIVO_TERRENO_H
#define ESTADO_CULTIVO_TERRENO_H
#include "Cultivo.h"
#include "Estado_Cultivo.h"


///estado concreto: terreno (sin arar)
class Estado_Cultivo_Terreno : public Estado_Cultivo ///Estado N en concreto (Estado Terreno)
{

public:
    Estado_Cultivo_Terreno(Cultivo* contexto);

    void hacer () override; ///sobrecarga
    void metodo_cargador_de_imagenes()override;
    bool aumentarProgreso() override;
    int getProgreso() override;

private:
    Cultivo* punteroAcultivo;///referencia a cultivo
///estado_cultivo_terreno tiene un cultivo ( composicion usada para cerrar el circulo de la maquina finita de estados )
    Estado_Cultivo* _objeto;
    int progreso;
};

#endif // ESTADO_CULTIVO_TERRENO_H
