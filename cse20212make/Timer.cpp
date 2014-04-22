#include "SDL/SDL.h"
#include "Timer.h"

Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = 0;
    started = 0;    
}

void Timer::start()
{
    //Start the timer
    started = 1;
    
    //Unpause the timer
    paused = 0;
    
    //Get the current clock time
    startTicks = SDL_GetTicks();    
}

void Timer::stop()
{
    //Stop the timer
    started = 0;
    
    //Unpause the timer
    paused = 0;    
}

int Timer::get_ticks()
{
    //If the timer is running
    if( started == 1 )
    {
        //If the timer is paused
        if( paused == 1 )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }    
    }
    
    //If the timer isn't running
    return 0;    
}

void Timer::pause()
{
    //If the timer is running and isn't already paused
    if( ( started == 1 ) && ( paused == 0 ) )
    {
        //Pause the timer
        paused = 1;
    
        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    //If the timer is paused
    if( paused == 1 )
    {
        //Unpause the timer
        paused = 0;
    
        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;
        
        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int Timer::is_started()
{
    return started;    
}

int Timer::is_paused()
{
    return paused;    
}



