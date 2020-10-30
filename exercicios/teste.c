#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 100

int getln(char line[], int lim);
int htoi(char hex[]);

//---------------------------------
int main(void){
    
    char p = 8;
    
    int a = isdigit(p);
    
    printf("%d\n", a);

    return 0;
}

//---------------------------------

