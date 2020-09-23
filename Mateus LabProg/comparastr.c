#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int cont, i = 0;
    char s1[] = "CELACANTO PROVOCA MAREMOTO";
    char s2[] = "CELACANTO PROVOCA MAREMOTO";
    for (i=0; i< 26; i++){
			if (s1[i] == s2[i])
			cont++;
		}
    printf("o numero de pontos foi:\n%d\n", cont);
	return 0;
}

