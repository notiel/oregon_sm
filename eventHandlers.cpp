/*
 * eventHandlers.cpp
 *
 *  Created on: 28 θών. 2019 γ.
 *      Author: juice
 */
#include "eventHandlers.h"
#include <stdio.h>

void UpdateHP(OregonPlayer* me, unsigned int NewHP) {
    if (NewHP <= DEFAULT_HP) {
        me->CharHP = NewHP;
    } else {
        me->CharHP = DEFAULT_HP;
    }
    SaveHP(me->CharHP);
	printf("Update HP %u\n", HP);
}

void UpdateTimerAgony(OregonPlayer* me, unsigned int Timer) {
	printf("Updated timer agony %u", Timer);
    me->TimerAgony = Timer;
    SaveTimerAgony(Timer);
}

void Reset(OregonPlayer* me) {
	printf("Reseted\n");
	UpdateHP(me, DEFAULT_HP);
	me->TimerDeath = 0;
	UpdateTimerAgony(me, 0);
}

//only a stub
void Flash(unsigned int R, unsigned int G, unsigned int B, unsigned int Timeout) {
	printf("Flash %u, %u, %u color for %u ms\n", R, G, B, Timeout);
}

//only a stub
void BeepForTime(unsigned int Period) {
	printf("Beep for %u ms\n", Timeout);
}

//only a stub
void SaveHP(unsigned int HP) {
	printf("HP saved (%u)\n", HP);
}

//only a stub
void SaveTimerAgony(unsigned int Timer) {
	printf("TimerAgony saved (%u)\n", Timer);
}

void ShowCurrentHealth (OregonPlayer* me) {
     Flash(255 - me->CharHP*me->ScaleStep, me>CharHP*me->ScaleStep, 0, FLASH_MS);
}

void ShowCurrentHealthGhoul (OregonPlayer* me) {
     Flash(255 - me->CharHP*me->ScaleStep, me>CharHP*me->ScaleStep, 0, FLASH_MS);
}



