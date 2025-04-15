#ifndef __SOFTWARE_TIMER_H__
#define __SOFTWARE_TIMER_H__

void SoftwareTimer_Set(int index, int value);
int SoftwareTimer_IsExpired(int index);
void SoftwareTimer_Run(void);

#endif