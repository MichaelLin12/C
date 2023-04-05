#include "stdio.h"


int main(int argc, char **argv){
    int i = 0;
    int *ptr = &i;
    int temp = (intptr_t) ptr;
    printf("The address of i/2 from ptr is: %d, and the address of i is: %d", temp/2, (intptr_t)&i);
    return 0;
}