#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void gera_frase(char s1[], int c);
int compara_string(char s1[], char meta[], int tam);
void gera_filho(char s1[], int p, int g, char meta[], int tam);
void involucao(char s1[], char s2[], char meta[], int tam);
int contachar(char s[]);
struct nodot *lista(struct nodot*, char *);
struct nodot {     	/* o nodo da árvore: */
	char *palavra; /* aponta para o texto */
	int contador; /* número da ocorrências */
	struct nodot *prox;
};
char *dupcad(char *);
struct nodot *aloca(void);
void imprlista(struct nodot *);

int main (int argc, char *argv[])
{	
	int i = 0;
	int valorP = 0;
	int valorG = 0;
	char *vp;
	vp=(char*)malloc(100*sizeof(char));
	char *vg;
	vg=(char*)malloc(100*sizeof(char));
	char *newfrase = "";
	newfrase=(char*)malloc(100*sizeof(char));
		if (argc == 1){
		valorP = 5;
		valorG = 100;
		newfrase = "CELACANTO PROVOCA MAREMOTO";
	}
		
		else if (argc == 2 || argc == 3){
			
			printf("\nENTRADA FORA DO PADRAO\n");
			exit(1);
		}
	
		else{
	strcpy (vp,argv[1]);
	valorP = atoi(&vp[2]);
	strcpy (vg,argv[2]);
	valorG = atoi(&vg[2]);

	

		strcpy(newfrase, argv[3]);
		for (i=0; i<argc; i++){
		if (i>3){
		newfrase = strcat(newfrase," ");
		newfrase = strcat(newfrase,argv[i]);
			}
		}
	}
			
	//char meta[] = "CELACANTO PROVOCA MAREMOTO";
	char frase[contachar(newfrase)];
	gera_frase(frase,contachar(newfrase));
	//printf("A pontuacao inicial e:\n%d\n", compara_string(frase,meta));
	//printf("-------------------------\n");
	gera_filho(frase, valorP, valorG, newfrase, contachar(newfrase));
	printf("A frase que deve ser obtida e:\n%s\nE contem %d caracteres", newfrase, contachar(newfrase));
	return 0;
}

int contachar(char s[]){
	int i = 0;
	for (i=0; i<strlen(s);i++){
	}
		return i;
	}


void gera_frase(char frase[], int c){
	int i = 0;
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (i=0; i< c; i++){
		frase[i] = letras[ rand() % strlen(letras)];
	}
	frase[i] = '\0';
	printf("A frase gerada e:\n%s\n", frase);	
}
	
int compara_string(char s1[], char meta[], int tam){
	//char meta[] = "CELACANTO PROVOCA MAREMOTO";
	int cont = 0;
	int i = 0;
    for (i=0; i< tam; i++){
			if (s1[i] == meta[i])
			cont++;
		}
    return cont;
}

void involucao(char s1[], char s2[], char meta[], int tam){
	if (compara_string(s1, meta, tam) >= compara_string(s2, meta, tam)){
		printf("INVOLUCAO!\n");
	}
}

struct nodot *lista(struct nodot *p, char *w)
{
    int cond = 0;

    if (p == NULL) {     /* uma nova palavra chegou */
        p = aloca();    /* cria um novo nodo */
        p->palavra = dupcad(w);
        p->contador = 1;
        p->prox = NULL;
    } else if ((cond = strcmp(w, p->palavra)) == 0)
        p->contador++;      /* palavra repetida */
    else
        p->prox = lista(p->prox, w);
    return p;
}

struct nodot *aloca(void)
{
    return (struct nodot *) malloc(sizeof(struct nodot));
}


char *dupcad(char *s) /* cria uma duplicata de s */
{
	char *p;

	p = (char *) malloc(strlen(s)+1);  /* +1 para '\0' */
	if (p!= NULL)
		strcpy(p,s);
	return p;
}

	
void imprlista(struct nodot *p)
{
    if (p != NULL) {
        imprlista(p->prox);
        printf("%s\n", p->palavra);
    }
}	

void gera_filho(char s[], int p, int g, char meta[], int tam){
	int i = 0;
	int j = 0;
	int aux = 0;
	char *inv;
	struct nodot *list;
	list = NULL;
	inv=(char*)malloc(tam*sizeof(char));
	char *maior;
	maior=(char*)malloc(tam*sizeof(char));
	srand ( time(NULL) );
	int contador[g];
	char filho[g][tam];
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	strcpy(maior,"0");
	for (j=0; j<g; j++){
		strcpy(filho[j],s);
		for (i=0; i<tam; i++){
			aux = rand() % 100;
			if (aux < p){
				filho[j][i] =  letras[ rand() % strlen(letras)];
			}
		}	
		//printf("O filho(%d) gerado e:\n%s\n", j, filho[j]);
		contador[j] = compara_string(filho[j], meta, tam);
		//printf("A pontuacao e:\n%d\n", contador[j]);
		
		//printf("-------------------------\n");
			if (contador[j] > compara_string(maior, meta, tam)){
				strcpy(maior, filho[j]);
			}
	}
	printf("A nova mae sera:\n%s\n", maior);
	//printf("Que e o filho numero:\n%d\n", cria);
	//printf("Com a pontuacao de:\n%d\n", compara_string(maior,meta));
	involucao(s, maior, meta, tam);
	list = lista(list, maior);
	
	while(compara_string(maior, meta, tam) != tam){
			strcpy(inv,maior);
			for (j=0; j<g; j++){
		strcpy(filho[j],maior);
		for (i=0; i<tam; i++){
			aux = rand() % 100;
			if (aux < p){
				filho[j][i] =  letras[ rand() % strlen(letras)];
			}
		}	
		//printf("O filho(%d) gerado e:\n%s\n", j, filho[j]);
		contador[j] = compara_string(filho[j], meta, tam);
		//printf("A pontuacao e:\n%d\n", contador[j]);
		
		//printf("-------------------------\n");
			if (contador[j] > compara_string(maior, meta, tam)){
				strcpy(maior, filho[j]);
			}
	}
		printf("A nova mae sera:\n%s\n", maior);
		involucao(inv, maior, meta, tam);
		list = lista(list, maior);
	}
	
	printf("\nAbaixo a lista das string escolhidas em cada geracao em que houve evolucao para procriar\n");
	imprlista(list);
	printf("A probabilidade de mutacao e: %d%%\nA quantidade de filhos por geracao e: %d\n", p,g);
}

