#include <stdio.h>

#define OUT 0
#define IN 1

/*Count lines,words,chars*/

int main(){
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while((c = getchar()) != EOF){
        nc++;
        if(c=='\n') nl++;
        if(c==' '||c=='\n'||c=='\t') state = OUT;
        else if(state == OUT){
            state = IN;
            nw++;
        }
    }

    printf("%d %d %d\n",nc,nw,nl);
}