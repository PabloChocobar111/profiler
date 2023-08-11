#include "..\header\profiler.h"
var1=-1,var2=-1,var2_init=-1;
void (*curr_func)(char*)=begin_clock1;
void begin_clock1(char* label){
    QueryPerformanceFrequency(&freq);
    clocks[++var1].label=label;
    QueryPerformanceCounter(&(clocks[var1].time));
    var2+=b_flag;
    b_flag=1;
    curr_func=begin_clock2;
}
void begin_clock2(char* label){
    clocks[++var1].label=label;
    var2+=b_flag;
    clocks[var1].spaces=(var2-var2_init)<<1;
    QueryPerformanceCounter(&(clocks[var1].time));
    b_flag=1,e_flag=0;
}
void end_clock(void){
    LARGE_INTEGER temp;
    QueryPerformanceCounter(&temp);
    if(e_flag)
        clocks[var2].time.QuadPart=(1000000*(temp.QuadPart-clocks[var2--].time.QuadPart))/freq.QuadPart;
    else
        clocks[var1].time.QuadPart=(1000000*(temp.QuadPart-clocks[var1].time.QuadPart))/freq.QuadPart;
    e_flag=1,b_flag=0;
    if(var2==var2_init) var2=var2_init=var1;
}
void print_times(void){
    
    unsigned int max_line_width = 0;
    FreeConsole();
    AllocConsole();
    DWORD dwBytesWritten;
    for(int j=0;j<=var1;j++)
    {
        max_line_width = max_line_width < (clocks[j].spaces+strlen(clocks[j].label)) ? (clocks[j].spaces+strlen(clocks[j].label)) : max_line_width;
    }
    max_line_width+=2;
    for(int j=0;j<=var1;j++)
        printf("%*s%-*s%llu us\n",clocks[j].spaces,"",max_line_width-clocks[j].spaces,clocks[j].label,clocks[j].time.QuadPart);
    getch();
    FreeConsole();
}
void time_end(void){
    end_clock();
    atexit(print_times);
}