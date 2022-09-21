/* Dynamic Programming implementation of LCS problem */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lcs.h"

int main(int argc, char *argv[])
{
    if(argc!=4) {
        perror("Numero di parametri errato.");
        return 1;
    }

    int m = lengthOfFile(argv[1]);
    int n = lengthOfFile(argv[2]);

    char firstSequence[m];
    char secondSequence[n];

    strcpy(firstSequence,readFile(argv[1]));
    strcpy(secondSequence,readFile(argv[2]));

    printf("La stringa uno è: %s\n",firstSequence);
    printf("La stringa due è: %s\n",secondSequence);

    printf("La LCS è : %s\n", lcs(firstSequence, secondSequence, m, n));

    writeStringInformation(argv[3], lcs(firstSequence, secondSequence, m, n));

    printf("__SALVATAGGIO COMPLETATO__\n");
}