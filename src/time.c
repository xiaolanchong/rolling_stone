/* 
** Copyright (C) 1999 by Andreas Junghanns.
**
** Permission to use, copy, modify, and distribute this software and its
** documentation for any purpose and without fee is hereby granted, provided
** that the above copyright notice appear in all copies and that both that
** copyright notice and this permission notice appear in supporting
** documentation.  This software is provided "as is" without express or
** implied warranty.
*/ 

#include "board.h"

#ifdef _MSC_VER

#include <windows.h>

struct itimerval {
   struct timeval it_interval; /* next value */
   struct timeval it_value;    /* current value */
};

const int ITIMER_REAL = 1;
const int ITIMER_VIRTUAL = 2;

const int SIGALRM = 0x70000;
const int SIGVTALRM = 0x70001;

static int setitimer(int which, const struct itimerval* value, struct itimerval* ovalue)
{
   Mprintf(0, "Max working time not implemented in Windows\n");
   return 0;
}

#else
#include <sys/time.h>
#endif // _MSC_VER

/* this code was generously made available by Diego Novillo
 * and Peter van Beek */

/*
 *  Signal handler for when timer expires.
 */
static void
expire(int signum)
{
        MainIdaInfo.TimedOut = YES;
	Mprintf(0,"\nTimeOut!!\n");
}

/*
 *  Set a timer (an alarm) that will expire after ``time_limit'' seconds.
 *  The timer counts in virtual time (CPU time) or real time, depending
 *  on ``type''.
 */
void SetMaxWorkTimer()
{
        struct itimerval value;
	int    time_limit;
	int    type;

	/* set alarm only, if time limit was set */
	if (MainIdaInfo.TimeOut<=0) return;

        MainIdaInfo.TimedOut = NO;
	time_limit = MainIdaInfo.TimeOut;
	type = MainIdaInfo.TimeOutType;

        /*
         *  Setting it_interval to zero causes timer to be disabled
         *  after its next expiration (assuming it_value is non-zero).
         */
        value.it_interval.tv_sec = 0;
        value.it_interval.tv_usec = 0;

        /*
         *  If it_value is non-zero, it indicates the time to the next
         *  timer expiration.
         */
        value.it_value.tv_sec = time_limit;
        value.it_value.tv_usec = 0;

        /*
         *  Set the signal handler and start the timer.
         */
        if( type == REAL ) {
                /*
                 *  ITIMER_REAL is a timer that decrements in real time.
                 *  A SIGALRM signal is delivered when it expires.
                 */
                signal( SIGALRM, expire );
                setitimer( ITIMER_REAL, &value, (struct itimerval *) NULL );
        }
        else
        if( type == VIRTUAL ) {
                /*
                 *  ITIMER_VIRTUAL is a timer that decrements in process
                 *  virtual time.  It runs only when the process is executing.
                 *  A SIGVTALRM signal is delivered when it expires.
                 */
                signal( SIGVTALRM, expire );
                setitimer( ITIMER_VIRTUAL, &value, (struct itimerval *) NULL );
        }
}

