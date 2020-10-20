#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

int main() {
    int memorySize = 10*1024*1024;
    for (int i = 0; i < 10; ++i) {
        void *ptr = malloc(memorySize); //allocate 10 MB of memory
        memset(ptr, 0, memorySize); //fill it with zeros
        sleep(1); //sleep for 1 second
    }
    return 0;
}

/*
[1] 21378
Mach Virtual Memory Statistics: (page size of 4096 bytes)
    free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
   62937   628217    12813   604087        0   566377    98426  706660K 12417659  363434K 52149261 19277646      289681    955436  1579942   222177 65420798  175513K 27068621   226680 10735820 11571337
   60333   622056    12817   607091        0   572104    87562    12902        0     2642        7        0      289685    952279  1579937   222177        5        0        0        0        0        0
   57832   623218    12817   608321        0   572291    87380     2619        0     2611        0        0      289685    954671  1579936   222177        1        0        0        0        0        0
   55169   625570    12817   608969        0   571845    87387     2577        0     2574        0        0      289685    957671  1579936   222177        0        0        0        0        0        0
   52693   621301    12817   609827        0   577802    81387     2634        0     2613        0        0      289685    954260  1579924   222177       12        0        0        0        0        0
   50147   633607    12817   610476        0   567424    91805     2589        0     2581        0        0      289685    967215  1579922   222177        2        0        0        0        0        0
   47541   645291    12817   613626        0   555078    92787     2569        0     2562        0        0      289685    982049  1579919   222177        3        0        0        0        0        0
   44867   647146    12817   614327        0   555083    92787     2572        0     2569        0        0      289685    984605  1579918   222177        1        0        0        0        0        0
   42325   649040    12817   614986        0   555088    92782     2571        0     2566        0        0      289685    987158  1579916   222177        2        0        0        0        0        0
   68137   625722    12817   612593        0   555021    92782       35        0       30        0        0      289685    961447  1579915   222177        1        0        0        0        0        0
   78594   615329    12817   610872        0   556686    80696        8        0        5        0        0      289685    949333  1579914   222177        1        0        0        0        0        0
   78664   615289    12817   610852        0   556686    80696       17        0        7        0        0      289685    949273  1579883   222177        3        0        0        0        0        0
   78668   615292    12817   610852        0   556686    80696       10        0        5        0        0      289685    949276  1579881   222177        2        0        0        0        0        0

 swapins = swapouts = 0  =>  nothing was swapped because there was a lot of physical memory.
 */