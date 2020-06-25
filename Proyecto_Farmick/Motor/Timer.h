#ifndef TIMER_H
#define TIMER_H

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;

class Timer
{
    public:
        inline static Timer* getInstancia(){return s_Instancia = (s_Instancia != nullptr)? s_Instancia : new Timer();}
        inline float getDeltaTime(){return m_deltaTime;}
        void tick();

    protected:

    private:
        Timer();
        static Timer* s_Instancia;
        float m_deltaTime;
        float m_lastTime;
};

#endif // TIMER_H
