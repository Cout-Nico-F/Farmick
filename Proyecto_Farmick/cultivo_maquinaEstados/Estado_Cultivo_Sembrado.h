#pragma once
#include "Cultivo.h"

class Estado_Cultivo_Sembrado : public Estado_Cultivo
{
public:
    Estado_Cultivo_Sembrado(Cultivo* contexto);

    void hacer()override;
    void metodo_cargador_de_imagenes()override;

private:
    Cultivo* _punteroAcultivo;
    Estado_Cultivo* _objeto;

};

