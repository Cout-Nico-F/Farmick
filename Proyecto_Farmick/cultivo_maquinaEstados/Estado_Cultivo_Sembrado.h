#pragma once
#include "Cultivo.h"

class Estado_Cultivo_Sembrado : public Estado_Cultivo
{
public:
    Estado_Cultivo_Sembrado(Cultivo* contexto);

    void hacer()override;
    void metodo_cargador_de_imagenes()override;
    bool aumentarProgreso() override;
    int getProgreso() override;

private:
    Cultivo* _punteroAcultivo;
    Estado_Cultivo* _objeto;
    int progreso;
    int m_tiempoCrecimiento;
    unsigned long int tiempoCreacion;
};

