#include <stdio.h>
void main(){
	int c,nl=0;
	while((c=getchar()) != EOF){
		if (c == ' '){
			++nl;
			printf("%d\n", nl);
		}		
printf("apareceu! %d\n", nl);
	}
	
}

