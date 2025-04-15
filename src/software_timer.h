#ifndef __SOFTWARE_TIMER_H__
#define __SOFTWARE_TIMER_H__

void Timer_Set(int index, int value);
int Timer_IsExpired(int index);
void Timer_Run(void);

#endif