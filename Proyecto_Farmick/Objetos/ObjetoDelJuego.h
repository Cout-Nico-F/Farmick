#ifndef OBJETODELJUEGO_H
#define OBJETODELJUEGO_H
#include "Objeto.h"
#include <string>


//clase con la que vamos crear nuestro sistema de herencia
class ObjetoDelJuego : public Objeto
{
public:
    ObjetoDelJuego() {}

   // virtual void Dibujar()=0;
  //  virtual void Actualizar(float deltaTiempo)=0;
   // virtual void Limpiar()=0;
protected:

    int m_ancho, m_alto;
    std::string m_idTextura;
    //SDL_RendererFlip m_giro;


};

#endif // OBJETODELJUEGO_H
