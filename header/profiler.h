#ifndef PROFILER_H
#define PROFILER_H
#include <windows.h>
#include "..\..\shared headers\mytypes.h"
LARGE_INTEGER freq;
#define MAX_CLOCKS 256
#define file_name __FILE__
typedef struct
{
    LARGE_INTEGER time;
    uint spaces;
    char* label;
}clock;
int var1,var2,var2_init;
char b_flag,e_flag;
clock clocks[MAX_CLOCKS];
void main1();
void begin_clock1(char*);
void begin_clock2(char*);
void (*curr_func)(char*);
#define begin_clock(label) curr_func(label);
void end_clock(void);
void time_end(void);
void customconsoleoutput(unsigned int,unsigned int);
void print_times(void);

#endif