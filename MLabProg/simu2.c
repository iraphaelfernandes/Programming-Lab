#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 1000

void gera_chave(char key[], char s[]);
void maiuscula (char s[]);
void elimina(char key[]);
void comprime (char s[], int c, int i);
void completaChave (char s[]);
void criptografaFrase (char s[], char key[]);
void validaFrase (char s[]);

int main () {
    char s1[N];
    char s2[N];
	char key[N]; 
    
    printf("\nInsira a frase a se tornar uma chave:\n");
	fgets(s1,N,stdin);
	
	strcpy(key, s1);
	maiuscula(key);
	elimina(key);
	completaChave(key); 
	printf("\nA chave gerada foi:\n%s\n",key);

    
    printf("\nInsira a frase a ser criptografada:\n");
    fgets(s2,N,stdin); 
    
    validaFrase(s2); //valida frase a ser criptografada
    criptografaFrase(s2,key); //criptografa frase
    printf("\nfrase convertida:\n%s\n",s2);
    
    return 0;
}
void maiuscula (char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
		if(isalpha(s[i])){
			s[i] = toupper(s[i]);
		}	
	}
}

void comprime (char s[], int c, int i){
    int j =i;
	while(s[i]!='\0'){
	    if (s[i] != c){
		s[j++] = s[i];
	}
	i++;
    }
    s[j] ='\0';
}

void elimina(char key[]){
	int c;
	for (int i = 0; (c = key[i]) != '\0';){
		if (!isalpha(c) && c!= ' ' && c!= '.' && c!= ','){
			comprime(key, c , i);
		}
		else {
			comprime(key, c, i+1);
			i++;
		}
	}
}
void completaChave (char s[]) {
    char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
    int i = 0, j, size = 0;
    //verifica tamanho original da chave
    for (i = 0; s[i] != '\0'; i++)
        size++;
    //completa os caracteres restantes
    for (i = 0; letras[i] != '\0'; i++) {
        for (j = 0; s[j] != '\0'; j++) {
            //sai do loop se caracter já está na chave
            if (s[j] == letras[i])
                break;
        }
        //se caracter não está na chave, adiciona-o
        if (s[j] != letras[i]) {
            s[size] = letras[i];
            s[++size] = '\0';
        }
    }
}

void gera_chave(char key[], char s[]){
	strcpy(key, s);
	maiuscula(key);
	elimina(key);
	completaChave(key); 
}




void criptografaFrase (char s[], char key[]) {
    int index = 0, i = 0;
    //criptografa
    for (i=0; s[i]!='\0'; i++) {
        //indice é movido para direita pelo valor do char
        if (s[i] >= 'A' && s[i] <= 'Z')
            index += s[i] - 'A' + 1;
        else if (s[i] == ',')
            index += 27;
        else if (s[i] == '.')
            index += 28;
        else if (s[i] == ' ')
            index += 29;
        //circular
        index = (index)%29;
        //valor criptografado
        s[i] = key[index];
    }
}

void validaFrase (char s[]) {
    int i = 0, j;
    maiuscula(s); //converte das letras minúsculas em maiúsculas
    // loop que ignora char inválido
    while (s[i] != '\0') {
		while ( s[i] != '\0' && !((s[i] >= 'A' && s[i] <= 'Z') || s[i] == ',' || s[i] == '.' || s[i] == ' ') ) {
			for (j = i; s[j] != '\0'; j++)
				s[j] = s[j+1];
			s[++j] = '\0';
		}
        i++;
	}
}

