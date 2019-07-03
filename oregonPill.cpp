/*****************************************************************************
* Model: oregonPill.qm
* File:  ./oregonPill.cpp
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*${.::oregonPill.cpp} .....................................................*/
#include "qhsm.h"
#include "oregonPill.h"
#include "oregonPlayer.h"

#include "eventHandlers.h"

#include <stdint.h>

//Q_DEFINE_THIS_FILE

/* protected: */
static QState OregonPill_initial(OregonPill * const me, QEvt const * const e);
static QState OregonPill_global(OregonPill * const me, QEvt const * const e);
static QState OregonPill_active(OregonPill * const me, QEvt const * const e);
static QState OregonPill_cast_rad_immune(OregonPill * const me, QEvt const * const e);
static QState OregonPill_radx(OregonPill * const me, QEvt const * const e);
static QState OregonPill_antirad(OregonPill * const me, QEvt const * const e);
static QState OregonPill_atom(OregonPill * const me, QEvt const * const e);
static QState OregonPill_wait_curse(OregonPill * const me, QEvt const * const e);
static QState OregonPill_wait_bless(OregonPill * const me, QEvt const * const e);
static QState OregonPill_idle(OregonPill * const me, QEvt const * const e);
static QState OregonPill_wait_heal(OregonPill * const me, QEvt const * const e);
static QState OregonPill_station(OregonPill * const me, QEvt const * const e);
static QState OregonPill_simple(OregonPill * const me, QEvt const * const e);

#ifdef DESKTOP
static QState OregonPill_final(OregonPill * const me, QEvt const * const e);
#endif /* def DESKTOP */



static OregonPill oregonPill; /* the only instance of the OregonPill class */



/* global-scope definitions -----------------------------------------*/
QHsm * const the_oregonPill = (QHsm *) &oregonPill; /* the opaque pointer */

/*${SMs::OregonPill_ctor} ..................................................*/
void OregonPill_ctor() {
     OregonPill *me = &oregonPill;
     me->Timer = 0;
     me->Value = 0;
     QHsm_ctor(&me->super, Q_STATE_CAST(&OregonPill_initial));
}
/*${SMs::OregonPill} .......................................................*/
/*${SMs::OregonPill::SM} ...................................................*/
static QState OregonPill_initial(OregonPill * const me, QEvt const * const e) {
    /* ${SMs::OregonPill::SM::initial} */
    return Q_TRAN(&OregonPill_idle);
}
/*${SMs::OregonPill::SM::global} ...........................................*/
static QState OregonPill_global(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {

#ifdef DESKTOP
        /* ${SMs::OregonPill::SM::global::TERMINATE} */
        case TERMINATE_SIG: {
            status_ = Q_TRAN(&OregonPill_final);
            break;
        }
#endif /* def DESKTOP */

        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active} ...................................*/
static QState OregonPill_active(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            printf("Entered pill_active\n");
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::PILL_ANY} */
        case PILL_ANY_SIG: {
            PillIndicate();
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::1]} */
        case TIME_TICK_1S_SIG: {
        	if (me->Timer > 1) {
                me->Timer--;
                status_ = Q_HANDLED();
                break;
        	}
        	else {
        		status_ = Q_TRAN(&OregonPill_idle);
        	}
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::PILL_REMOVED} */
        case PILL_REMOVED_SIG: {
        	PASS_EVENT_TO(the_oregonPlayer);
            status_ = Q_TRAN(&OregonPill_idle);
            break;
        }
        case PILL_GHOUL_REMOVED_SIG: {
           	PASS_EVENT_TO(the_oregonPlayer);
            status_ = Q_TRAN(&OregonPill_idle);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::PILL_RESET} */
        case PILL_RESET_SIG: {
            PASS_EVENT_TO(the_oregonPlayer);
            status_ = Q_TRAN(&OregonPill_idle);
            break;
        }
        case PILL_TEST_SIG: {
            PASS_EVENT_TO(the_oregonPlayer);
            status_ = Q_TRAN(&OregonPill_idle);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::PILL_GHOUL} */
        case PILL_GHOUL_SIG: {
            PASS_EVENT_TO(the_oregonPlayer);
            status_ = Q_TRAN(&OregonPill_idle);
            break;
        }
        case Q_EXIT_SIG: {
            printf("Exited pill_active\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_global);
            break;
        }
    }
    return status_;
}

/*${SMs::OregonPill::SM::global::active::cast_rad_immune} ..................*/
static QState OregonPill_cast_rad_immune(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::cast_rad_immune} */
        case Q_ENTRY_SIG: {
        	printf("Entered pill_cast_rad_immune\n");
            SIMPLE_DISPATCH(the_oregonPlayer, IMMUNE);
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
        	printf("Exited pill_cast_rad_immune\n");
            SIMPLE_DISPATCH(the_oregonPlayer, NOT_IMMUNE);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_active);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::cast_rad_immune::radx} ............*/
static QState OregonPill_radx(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::cast_rad_immune::radx} */
        case Q_ENTRY_SIG: {
            printf("Entered pill_radx\n");
        	ClearPill();
            me->Timer = TIMEOUT_RADX_S;
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            printf("Exited pill_radx\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_cast_rad_immune);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::cast_rad_immune::antirad} .........*/
static QState OregonPill_antirad(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            printf("Entered pill_antirad\n");
            status_ = Q_HANDLED();
            break;
        }
        case TIME_TICK_1S_SIG: {
        	status_ = Q_HANDLED();
        	break;
        }
        case Q_EXIT_SIG: {
           printf("Exited pill_antirad\n");
           status_ = Q_HANDLED();
           break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_cast_rad_immune);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::atom} .............................*/
static QState OregonPill_atom(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::atom} */
        case Q_ENTRY_SIG: {
            printf("Entered pill_atom\n");
        	ClearPill();
            SIMPLE_DISPATCH(the_oregonPlayer, AGONY);
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            printf("Exited pill_atom\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_active);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::atom::wait_curse} .................*/
static QState OregonPill_wait_curse(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            printf("Entered pill_wait_curse\n");
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            printf("Exited pill_wait_curse\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_atom);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::atom::wait_bless} .................*/
static QState OregonPill_wait_bless(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::atom::wait_bless} */
        case Q_ENTRY_SIG: {
        	printf("Entered pill_wait_bless\n");
            me->Timer = TIMEOUT_ATOM_S;
            status_ = Q_HANDLED();
            break;
        }
        case PILL_REMOVED_SIG: { //discard
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::atom::wait_bless} */
        case Q_EXIT_SIG: {
        	printf("Exited pill_wait_bless\n");
            SIMPLE_DISPATCH(the_oregonPlayer, BLESSED);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_atom);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::idle} .............................*/
static QState OregonPill_idle(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::idle} */
        case Q_ENTRY_SIG: {
        	printf("Entered pill_idle\n");
            me->Timer = 0;
            status_ = Q_HANDLED();
            break;
        }
        case TIME_TICK_1S_SIG: {
        	status_ = Q_HANDLED();
        	break;
        }
        /* ${SMs::OregonPill::SM::global::active::idle::PILL_HEAL} */
        case PILL_HEAL_SIG: {
            status_ = Q_TRAN(&OregonPill_simple);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::idle::PILL_HEALSTATION} */
        case PILL_HEALSTATION_SIG: {
            status_ = Q_TRAN(&OregonPill_station);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::idle::PILL_BLESS} */
        case PILL_BLESS_SIG: {
            status_ = Q_TRAN(&OregonPill_wait_bless);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::idle::PILL_CURSE} */
        case PILL_CURSE_SIG: {
            status_ = Q_TRAN(&OregonPill_wait_curse);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::idle::PILL_ANTIRAD} */
        case PILL_ANTIRAD_SIG: {
            status_ = Q_TRAN(&OregonPill_antirad);
            break;
        }
        /* ${SMs::OregonPill::SM::global::active::idle::PILL_RAD_X} */
        case PILL_RAD_X_SIG: {
            status_ = Q_TRAN(&OregonPill_radx);
            break;
        }
        case Q_EXIT_SIG: {
            printf("Exited pill_idle\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_active);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::wait_heal} ........................*/
static QState OregonPill_wait_heal(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::wait_heal} */
        case Q_ENTRY_SIG: {
        	printf("Entered pill_wait_heal\n");
            me->Timer = TIMEOUT_HEAL_S;
            status_ = Q_HANDLED();
            break;
        }
        case TIME_TICK_1S_SIG: {
        	if (me->Timer == 1) {
        	    oregonPillQEvt new_e;
        	    new_e.super.sig = HEAL_SIG;
        	    new_e.Value = me->Value;
        	    QMSM_DISPATCH(the_oregonPlayer, (QEvt *)&new_e);
        	    status_ = Q_TRAN(&OregonPill_idle);
        	}
        	else {
        		me->Timer--;
        		status_ = Q_HANDLED();
        	}
        	break;
        }
        /* ${SMs::OregonPill::SM::global::active::wait_heal} */
        case Q_EXIT_SIG: {
        	printf("Exited pill_wait_heal\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_active);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::wait_heal::station} ...............*/
static QState OregonPill_station(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::wait_heal::station} */
        case Q_ENTRY_SIG: {
        	printf("Entered pill_healstation\n");
            me->Value = DEFAULT_HP;
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            printf("Exited pill_healstation\n");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_wait_heal);
            break;
        }
    }
    return status_;
}
/*${SMs::OregonPill::SM::global::active::wait_heal::simple} ................*/
static QState OregonPill_simple(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::global::active::wait_heal::simple} */
        case Q_ENTRY_SIG: {
        	printf("Entered pill_heal_simple\n");
            ClearPill();
            me->Value = DEFAULT_HP/2;
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
             printf("Exited pill_heal_simple\n");
             me->Timer = 0;
             status_ = Q_HANDLED();
             break;
        }
        default: {
            status_ = Q_SUPER(&OregonPill_wait_heal);
            break;
        }
    }
    return status_;
}

#ifdef DESKTOP
/*${SMs::OregonPill::SM::final} ............................................*/
static QState OregonPill_final(OregonPill * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::OregonPill::SM::final} */
        case Q_ENTRY_SIG: {
            printf("Bye! Bye!"); exit(0);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
#endif /* def DESKTOP */




/*tranlated from diagrams code*/

