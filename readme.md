>[!NOTE]
>There is some flaws with my code which I will fix soon.
>Currently using fixed size array of length 256 to store clock variable. (see line#5 of profiler.h). And to handle this either we have to check if currentsize > allocated size everytime we call begin_clock() or we need to know how many times begin_clock() and end_clock() have been called. I choose the later because in doing so I can check to make sure if for every begin_clock() there exist end_clock().
>