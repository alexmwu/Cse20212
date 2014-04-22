#ifndef TIMER_H
#define TIMER_H
#include "SDL/SDL.h"

//The timer
class Timer
{    
    public:
    //Initializes variables
    Timer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    int get_ticks();
    
    //Checks the status of the timer
    int is_started();
    int is_paused();  


    private:
    //The clock time when the timer started
    int startTicks;
    
    //The ticks stored when the timer was paused
    int pausedTicks;
    
    //The timer status
    int paused;
    int started;
  
};

#endif