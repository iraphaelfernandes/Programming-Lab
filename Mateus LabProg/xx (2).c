#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
    int np, c, prevblank;

    prevblank = FALSE;
    np = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (prevblank == FALSE)
                putchar('\n');
                np++;
            prevblank = TRUE;
        } else {
            prevblank = FALSE;
            putchar(c);
        }
    }
    printf("\n%d\n", np);
    return EXIT_SUCCESS;
}
