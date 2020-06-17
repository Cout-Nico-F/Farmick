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

    bool cargado = false;//parche usado en cultivo_arado

private:
    Cultivo* punteroAcultivo;///referencia a cultivo
///estado_cultivo_terreno tiene un cultivo ( composicion usada para cerrar el circulo de la maquina finita de estados )

    //Imagen* terreno;

   // Imagen* imagen; ///los objetos de esta clase van a tener una imagen (composicion)
//los metodos para mostrar esta imagen deben ser parte de esta clase o de otra intermedia? un objeto de esta clase deberia poder mostrarse a si mismo?

};

#endif // ESTADO_CULTIVO_TERRENO_H
