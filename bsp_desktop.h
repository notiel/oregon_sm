/* 
Board Support Package.
Module to replace for various platforms.
*/
#ifndef bsp_desktop_h
#define bsp_desktop_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DESKTOP

#ifdef DESKTOP
    #include "mHoS.h"
    enum DesktopSignal {
        TERMINATE_SIG = LAST_USER_SIG + 1 /* terminate the application */
    };
#endif

#endif
