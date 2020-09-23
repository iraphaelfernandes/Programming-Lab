#include <stdio.h>

void converteFraseEmChave (char s[], char key[]);
void maiuscula (char s[]);
void primeiroChar (char s[], char key[]);
void completaChave (char s[]);
void criptografaFrase (char s[], char key[]);
void validaFrase (char s[]);

int main () {
    char string1[1000];
    
    char string2[1000];
    
    char key[30];
    int i;
    for (i = 0; i < 30; i++)
       key[i] = 0;
    
    printf("\nInsira a frase a se tornar chave:\n");
	fgets(string1,1000,stdin);
    
    printf("\nInsira a frase a ser criptografada:\n");
    fgets(string2,1000,stdin); 
    
    converteFraseEmChave(string1,key);//converte frase em chave
    printf("\nchave:\n%s\n",key);
    
    validaFrase(string2); //valida frase a ser criptografada
    criptografaFrase(string2,key); //criptografa frase
    printf("\nfrase convertida:\n%s\n",string2);
    
    return 0;
}

/******************************
    converte de frase em chave
*******************************/
void converteFraseEmChave (char s[], char key[]){
    maiuscula(s); //converte letras minúsculas em maiúsculas
    primeiroChar(s,key); //elimina caracter inválido e verificação de primeira ocorrência
    completaChave(key); //completa chave com caracteres restantes
}

/******************************
    converte das letras
    minúsculas em maiúsculas
*******************************/
void maiuscula (char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
		//remove \n no final
		if (s[i] == '\n' && s[i+1] == '\0')
			s[i] = '\0';
        else if (s[i] >= 'a' && s[i]<='z')
            s[i] += 'A' - 'a';
	}
}

/******************************
    elimina de caracter
    inválido e verificação de
    primeira ocorrência
*******************************/
void primeiroChar (char s[], char key[]) {
    int i = 0, j, k = 0;
    while (s[i] != '\0') {
        //ignora char inválido
        while (!( (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ',' || s[i] == '.' || s[i] == ' ') )
            if (s[++i] == '\0')
                break;
        if (s[i] == '\0')
            break;
        //sai do loop se não é a primeira ocorrência
        for (j = 0; j < k; j++)
            if (s[i] == key[j])
                break;
        //se é a primeira ocorrência, adiciona caracter na chave
        if (s[i] != key[j])
            key[k++] = s[i];
        i++;
    }
    key[k]='\0';
}

/******************************
    completa chave com
    caracteres restantes
*******************************/
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

/******************************
    criptografa frase
*******************************/
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

/******************************
    valida frase
    a ser criptografada
*******************************/
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
