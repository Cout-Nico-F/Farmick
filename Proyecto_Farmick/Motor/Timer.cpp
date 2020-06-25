#include "Timer.h"
#include "SDL.h"

Timer* Timer::s_Instancia = nullptr;

void Timer::tick()
{
    m_deltaTime = (SDL_GetTicks() - m_lastTime) * (TARGET_FPS / 1000.0f);

    if(m_deltaTime > TARGET_DELTATIME){ m_deltaTime =  TARGET_DELTATIME; }

    m_lastTime = SDL_GetTicks();
}

Timer::Timer()
{

}

