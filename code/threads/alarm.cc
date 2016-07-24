// alarm.cc
//	Routines to use a hardware timer device to provide a
//	software alarm clock.  For now, we just provide time-slicing.
//
//	Not completely implemented.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "alarm.h"
#include "main.h"

//----------------------------------------------------------------------
// Alarm::Alarm
//      Initialize a software alarm clock.  Start up a timer device
//
//      "doRandom" -- if true, arrange for the hardware interrupts to 
//		occur at random, instead of fixed, intervals.
//----------------------------------------------------------------------

Alarm::Alarm(bool doRandom)
{
    timer = new Timer(doRandom, this);
}

//----------------------------------------------------------------------
// Alarm::CallBack
//	Software interrupt handler for the timer device. The timer device is
//	set up to interrupt the CPU periodically (once every TimerTicks).
//	This routine is called each time there is a timer interrupt,
//	with interrupts disabled.
//
//	Note that instead of calling Yield() directly (which would
//	suspend the interrupt handler, not the interrupted thread
//	which is what we wanted to context switch), we set a flag
//	so that once the interrupt handler is done, it will appear as 
//	if the interrupted thread called Yield at the point it is 
//	was interrupted.
//
//	For now, just provide time-slicing.  Only need to time slice 
//      if we're currently running something (in other words, not idle).
//----------------------------------------------------------------------

void 
Alarm::CallBack() 
{
    Interrupt *interrupt = kernel->interrupt;
    MachineStatus status = interrupt->getStatus();
     cout << "\n-----call back  " << kernel->stats->totalTicks << "-----" << endl << endl;    
     cout<<"The current is "<<kernel->currentThread->getName() << "  TimeSlice:"<<kernel->currentThread->getRemainTimeSlice()<<"  Priority:"<<kernel->currentThread->getPriority()<<endl;
    kernel->TimeSpent+=TimerTicks;
    

    if (status != IdleMode) 
    {

	kernel->currentThread->subTimeSlice(TimerTicks);
	 if(kernel->currentThread->getRemainTimeSlice()<=0) //currentThread use up all the timeSlice
	{ 
            kernel->currentThread->setRemainTimeSlice(INITSLICE); //set the remain time slice
            kernel->currentThread->updatePriority(10); //update the priority
            interrupt->YieldOnReturn();
        }

/**	
            if(kernel->stats->totalTicks % 50 == 0){ //update every 50 TimeTicks
                kernel->scheduler->updateReadyListPriority();
                kernel->TimeSpent = 0;
            }                
            
           
**/        

    }
    else{
        cout<<"Thread Done!!!"<<endl;
        cout<<"Machine Halting...."<<endl;
        delete kernel;
    }
    
}
