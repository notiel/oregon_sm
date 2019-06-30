#ifndef EVENTSHANDLERS_H_
#define EVENTSHANDLERS_H_

#include "stdio.h"
#include "qhsm.h"
#include <stdbool.h>


//logic functions
void UpdateHP(OregonPlayer* me, unsigned int HP);
void Reset(MHoS* me); 
void Flash(unsigned int R, unsigned int G, unsigned int B, unsigned int Timeout);
void BeepForTime(unsigned int Period);
void SaveHP(unsigned int HP);
void SaveTimerAgony(unsigned int Timer);
void ShowCurrentHealth (OregonPlayer* me);
void ShowCurrentHealthGhoul (OregonPlayer* me);


#endif /* EVENTSHANDLERS_H_ */
