#include <stdio.h>

#define MIN 0
#define MAX 500

int main (){
	int i;
	for ( i=MIN ; i <= MAX ; i++ ) {
		printf("indice: %d\tvalor: %c\n",i,i);
	}
	return 0;
}
