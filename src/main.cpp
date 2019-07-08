/*****************************************************************************
* Product: History Example, Win32
* Last updated for version 5.6.0
* Last updated on  2015-12-18
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) Quantum Leaps, LLC. All rights reserved.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Alternatively, this program may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GNU General Public License and are specifically designed for
* licensees interested in retaining the proprietary status of their code.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
* Contact information:
* http://www.state-machine.com
* mailto:info@state-machine.com
*****************************************************************************/

//#define DEBUG_SM                // Printing states

//#include "qep_port.h"
//#include "qassert.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#include "bsp.h"
#include "oregonPlayer.h"
#include "oregonPill.h"
#include "service.h"
#include "eventHandlers.h"
#include "qhsm.h"

/*..........................................................................*/

int main() {
    uint8_t     i;                                      // Universal counter
    uint32_t    seconds=0;
    printf("Heart Of Storm State Machines\n");
    #ifdef DEBUG_SM
        printf("DEBUG_SM enabled\n\r");
    #endif
    #ifdef DESKTOP
        printf("Desktop version\n\r");
    #endif
    //for (i = 0; i < ARRAY_SIZE(KeyStrokes) - 1;i++)     // Exluding ESC
    for (i = 0; i < KeyNumber()-1; i++)      // Exluding ESC
        printf("%18s - '%c'\n\r", KeyStrokes[i].Alias, KeyStrokes[i].Key);
    printf("Press ESC to quit...\n");

      /* instantiate the HSM and trigger the initial transition */

    OregonPlayer_ctor(27000, HEALTHY, 0);
    QMSM_INIT(the_oregonPlayer, (QEvt *)0);
    OregonPill_ctor();
    QMSM_INIT(the_oregonPill, (QEvt *)0);
    QEvt e;
    //e.sig = MAX_PILL_SIG;
    //QMSM_DISPATCH(the_hand,  &e);
    for (;;) {
        static int tickCtr = 1;
        std::string msg;
        usleep(100000);

        if (kbhit()) {
            char c = _getch();     /* read one character from the console */
            printf("%c: ", c);
            //for (i = 0; i < ARRAY_SIZE(KeyStrokes);i++) {
            for (i = 0; i < (TERMINATE_SIG - Q_USER_SIG); i++) {
                if (c ==    KeyStrokes[i].Key) {
                    e.sig = KeyStrokes[i].Com;
                    msg = c;
                    break;
                }
            }
        }
        else if (--tickCtr == 0) { /* time for the tick? */
            tickCtr = 10;
            e.sig = TIME_TICK_1S_SIG;
            msg = "TICK";
            seconds++;
            printf("Time: %ds. ", seconds);
       }

        // if (BlinkOn) {c
        //     if (tickCtr % BlinkTimer == 0) RGB_blink_toggle();
        // }
        if (msg.length()) {
                                 /* dispatch the event into the state machine */
            QState r;
            oregonPlayerQEvt Oregon_e;
            if (e.sig == RAD_RCVD_SIG) {
                Oregon_e.super = e;
                Oregon_e.value = 1000;
                //r = QMSM_DISPATCH(the_oregonPill,  (QEvt *)&Oregon_e);
                r = QMSM_DISPATCH(the_oregonPlayer,  (QEvt *)&Oregon_e);

            }
            else if (e.sig == TIME_TICK_10S_SIG) {
                e.sig = TIME_TICK_1S_SIG;
                for (i = 1; i <= 10; i++) {
                    r = QMSM_DISPATCH(the_oregonPill, &e);
                    r = QMSM_DISPATCH(the_oregonPlayer,  &e);
                    seconds++;
                }
                e.sig = TIME_TICK_10S_SIG;
                r = QMSM_DISPATCH(the_oregonPill, &e);
                r = QMSM_DISPATCH(the_oregonPlayer,  &e);
            }
            else if (e.sig == TIME_TICK_1M_SIG) {
                e.sig = TIME_TICK_1S_SIG;
                for (i = 1; i <= 60; i++) {
                    r = QMSM_DISPATCH(the_oregonPill, &e);
                    r = QMSM_DISPATCH(the_oregonPlayer,  &e);
                    seconds++;
                }
                e.sig = TIME_TICK_1M_SIG;
                r = QMSM_DISPATCH(the_oregonPill, &e);
                r = QMSM_DISPATCH(the_oregonPlayer,  &e);
            }
            else if (e.sig == TIME_TICK_1S_SIG) {
                e.sig = TIME_TICK_1S_SIG;
			    r = QMSM_DISPATCH(the_oregonPill, &e);
                r = QMSM_DISPATCH(the_oregonPlayer,  &e);

            } else {
            	r = QMSM_DISPATCH(the_oregonPill,  &e);
                //r = QMSM_DISPATCH(the_oregonPlayer,  &e);
            }
            #ifdef DEBUG
                printf("returned: %u\n\r", r);
            #endif
            if (msg != "TICK") {
                printf("\n");
                //BlinkCoord.Y--;   // FAR manager console needs this
            }
        }
    }
    return 0;
}
/*..........................................................................*/
void Q_onAssert(char const * const file, int line) {
    fprintf(stderr, "Assertion failed in %s, line %d", file, line);
    _exit(-1);
}
