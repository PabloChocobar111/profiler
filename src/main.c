#include <windows.h>
#include "..\header\profiler.h"
#include <stdio.h>

int main(){
    begin_clock("Total");
    {

        begin_clock("block1");
        {
            begin_clock("block2");
            printf("Filename: %s.\n",file_name);
            end_clock();
            begin_clock("block3");
            end_clock();

        }
        end_clock();

    }
    end_clock();


    begin_clock("new block1");
    {
        begin_clock("new block2");

        end_clock();
    }
    end_clock();

    main1();

    begin_clock("new block3");
    {
        begin_clock("new block4");
        end_clock();
    }
    time_end();
    
}
