//Feito por Matheus Vargas 2019.2
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 1000

void maiuscula(char key[]);
void comprime (char s[], int c, int i);
void elimina(char key[]);
void completaChave(char key[]);
void verificaFrase2(char s[]);
void criptografia(char s[], char key[]);


int main(int argc, char **argv)
{
    char s1[N];
    char key[N];
    char s2[N];
    //Recebe a primeira string *****
    printf("\nInsira a frase para gerar uma chave:\n");
    fgets(s1,N,stdin);
    printf("\nA frase digitada foi: %s", s1);
    //Transforma a primeira string em uma chave criptográfica *****
    strcpy(key, s1);
    maiuscula(key);
    elimina(key);
    completaChave(key); 
    printf("\nA chave gerada foi: %s\n", key);
    //Recebe a segunda string
    printf("\nInsira a frase a ser utilizada na criptografia:\n");
    fgets(s2,N,stdin);
    //Trata a segunda string e realiza a criptografia *****
    verificaFrase2(s2); 
    criptografia(s2,key);
    printf("\nA frase criptografada obtida foi convertida:\n%s\n",s2);
return 0;
}
void maiuscula(char key[]){
    int i;
    for (i = 0; key[i] != '\0'; i++) {
	if(isalpha(key[i])){
	    key[i] = toupper(key[i]);
		}	
	}

}

void comprime(char s[], int c, int i){
    int j = i;
	while(s[i]!='\0'){
	    if (s[i] != c){
		s[j++] = s[i];
	}
	i++;
    }
    s[j] ='\0';
}

void elimina(char key[]){
    int c, i;
    for (i = 0; (c = key[i]) != '\0';){
	if (!isalpha(c) && c!= ' ' && c!= '.' && c!= ','){
	    comprime(key,c,i);
	}
	else {
	    comprime(key,c,i+1);
	    i++;
	}
    }
}

void completaChave(char key[]){
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
    int i = 0, j, size = 0;
    for (i = 0; key[i] != '\0'; i++)
	size++;
    for (i = 0; letras[i] != '\0'; i++) {
        for (j = 0; key[j] != '\0'; j++) {
            if (key[j] == letras[i])
                break;
        }
        if (key[j] != letras[i]) {
            key[size] = letras[i];
            key[++size] = '\0';
        }
    }

}

void verificaFrase2(char s[]) {
    int i = 0, j;
    maiuscula(s);
    while (s[i] != '\0') {
		while ( s[i] != '\0' && !((s[i] >= 'A' && s[i] <= 'Z') || s[i] == ',' || s[i] == '.' || s[i] == ' ') ) {
			for (j = i; s[j] != '\0'; j++)
				s[j] = s[j+1];
			s[++j] = '\0';
		}
        i++;
	}
}

void criptografia(char s[], char key[]) {
    int index = 0, i = 0;
    for (i=0; s[i]!='\0'; i++) {
	if (s[i] >= 'A' && s[i] <= 'Z')
            index += s[i] - 'A' + 1;
        else if (s[i] == ',')
            index += 27;
        else if (s[i] == '.')
            index += 28;
        else if (s[i] == ' ')
            index += 29;
        index = (index)%29;
        s[i] = key[index];
    }
}
