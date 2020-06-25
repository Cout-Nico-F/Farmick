#ifndef MERCADO_H
#define MERCADO_H


class Mercado
{
    public:

        static Mercado* getInstancia()
        {
            return s_instancia = (s_instancia == nullptr)? new Mercado() : s_instancia ;
        }

        virtual void vender();
        virtual void dibujar();

    protected:

    private:
        Mercado();
        static Mercado* s_instancia;
};

#endif // MERCADO_H
