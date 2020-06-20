#pragma once
#include "Cultivo.h"

class Estado_Cultivo_Arado : public Estado_Cultivo
{
public:
    Estado_Cultivo_Arado(Cultivo* contexto);

    void hacer()override; //palabra clave para asegurarse que esta sobreescribiendo un metodo efectivamente ( seguro anti errores )
    void metodo_cargador_de_imagenes()override;

private:
    Cultivo* _punteroAcultivo;
    Estado_Cultivo* _objeto;

//esta composicion es una de las formas de cerrar el circulo de la maquina finita de estados
//en la documentacion se habla de otras maneras mas utiles devolviendo un new estado

    bool cargado = false;//parche usado en cultivo_arado
};

