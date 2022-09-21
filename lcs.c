#include <string.h>
#include "lcs.h"

int max(int a,int b)
{
	if(a>b) return a;
    return b;
}

char* lcs(char *X, char *Y, int m, int n)
{
	int L[m+1][n+1];

	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
		if (i == 0 || j == 0)
			L[i][j] = 0;
		else if (X[i-1] == Y[j-1])
			L[i][j] = L[i-1][j-1] + 1;
		else
			L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	int index = L[m][n];

	char*  lcs;
	//qui alloco la memoria,size of char mi restituisce i byte che servono per memorizzare un carattere e lo moltiplico per index+1
	lcs = (char*)malloc(index+1 * sizeof(char));
    if (lcs == NULL) {
        printf("Memoria non allocata.\n");
        exit(0);
    }
	lcs[index] = '\0';

	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
		}
		else if (L[i-1][j] > L[i][j-1]) i--;
		else j--;
	}

	return lcs;
}

//apro il file,estraggo un carattere alla volta e ogni volta che estraggo aumento il contatore
int lengthOfFile(char* nameFile)
{
    int x, i = 0 ;

   FILE  *fd = fopen(nameFile, "r");
    if( fd==NULL ) {
        fprintf(stderr, "Errore nell'apertura del file %s.", nameFile);
        exit(1);
    }

    //leggo il carattere e lo memorizzo in x
    while(fread(&x, sizeof(char), 1, fd)==1) {
        i++;
    }

    fclose(fd);
    return i;
}

char* readFile(char* nameFile)
{
    int x, i = 0;

    static char result[1000];

    FILE *fd = fopen(nameFile, "r");
    if( fd==NULL ) {
        fprintf(stderr, "Errore nell'apertura del file %s.", nameFile);
        exit(1);
    }

    while(fread(&x, sizeof( char), 1, fd)==1)
    {
        result[i]=x;
        i++;
    }

    fclose(fd);
    return result;
}

//scrive il risultato sul file
void writeStringInformation(char* nameFile, char * info)
{
    FILE *fd = fopen(nameFile, "wb");
    if( fd==NULL ) {
        fprintf(stderr, "Errore nell'apertura del file %s.", nameFile);
        exit(1);
    }

    fwrite(info, sizeof(char), strlen(info), fd);

    fclose(fd);
}