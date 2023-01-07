#include <stdio.h>

/*
    Print Temperature Table
*/

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = LOWER;
    upper = UPPER;
    step = STEP;

    fahr = lower;
    while(fahr <= upper){
        celsius = 5.0*(fahr-32.0)/9.0;
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }
}