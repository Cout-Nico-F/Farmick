#pragma once
#include "Cultivo.h"

class Estado_Cultivo_Crecido : public Estado_Cultivo
{
public:
    Estado_Cultivo_Crecido(Cultivo* contexto);

    void hacer()override;
    void metodo_cargador_de_imagenes()override;
    bool aumentarProgreso() override;
    int getProgreso() override;

private:
    Cultivo* _punteroAcultivo;
    Estado_Cultivo* _objeto;
    int progreso;
};

