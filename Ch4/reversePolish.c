#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <ctype.h>


# define MAXOP 100 /*Max size for operand or operator*/
# define NUMBER '0' /*signal that a number was found*/
# define MAXVAL 100 /*MAX depth of stack*/
# define BUFSIZE 100

int sp = 0; /*Value of stack*/
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/*reverse Polish Calculator*/

int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getops(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);
            break;
        case '*':
            push(pop()*pop());
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop()/op2);
            else
                printf("Error: zero divsor\n");
            break;
        default:
            printf("Error: unknown command %s\n",s);
            break;
        }
    }

    return 0;
}


void push(double f){
    if(sp<MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full, can't push %g\n",f);
}

double pop(void){
    if(sp>0){
        return val[--sp];
    }else{
        printf("Error: stack empty\n");
        return 0.0;
    }
}


int getop(char s[]){
    int i,c;
    while((s[0] = c = getch()) == ' ' || c=='\t'){
    }
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));
    s[i] = '/0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void){
    return (bufp > 0)? buf[--bufp]:getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
