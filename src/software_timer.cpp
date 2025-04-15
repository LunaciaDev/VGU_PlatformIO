#include "software_timer.h"

int timer_counter[10];
int timer_flag[10];

void SoftwareTimer_Set(int index, int value) {
    timer_counter[index] = value;
    timer_flag[index] = 0;
}

int SoftwareTimer_IsExpired(int index) {
    if (timer_flag[index] == 1) {
        timer_flag[index] = 0;
        return 1;
    }

    return 0;
} 

void SoftwareTimer_Run(void) {
    for (int i = 0; i < 10; i++) {
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            if (timer_counter[i] == 0) {
                timer_flag[i] = 1;
            }
        }
    }
}