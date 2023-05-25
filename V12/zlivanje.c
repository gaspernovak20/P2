#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000000

FILE *openFiles( int n, char *mode){
    FILE **files = (FILE *)malloc(n * sizeof(FILE*));
    char * fileName = (char*)malloc( (MAX_LINE_LENGTH+1) * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &fileName);
        files[i] = fopen(fileName, mode);
        if(files[i] == NULL){
            printf("[napaka]: %s", fileName);
        }
    }

    free(fileName);
    return files;
}

void closeFiles(FILE **files, int n){
    for (int i = 0; i < n; i++)
    {
        free(files[i]);
    }
    free(files);
}

int indexMinimuma(int **t, int n){
    int iMin = 1;
    for (int i = 0; i < n; i++)
    {
        if (t[i] >= 0 && (t[i] < 0 || t[i] < t[iMin]))
        {
            iMin = i;
        }
    }
    
}

void mergeSort(FILE **vhodi, int n, FILE *izhodi){
    
    // st vhodnih datotek pri katerih smo prsli do konca
    int stkoncanih;
    // blok[i]: trenutni element iz i-te vhodne datoteke 0z -1 ze smp šreispelči do konca traku
    int *blok = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if ((fscanf("%d", &blok[i])) < 1)
        {
            blok[i] = -1;
            stkoncanih++;
        }
    }

    while (stkoncanih < n)
    {
        int iMin = indekMinimuma(blok,n);
        fprintf(izhodi, "%d\n", iMin);

        if(fscanf(vhodi[iMin], "%d", &blok[iMin]) <1){
            blok[iMin] = -1;
            stkoncanih++;
        }
    }
        


    }

int main(int argc, char const *argv[])
{
    int stDatotek;
    scanf("%d",&stDatotek);

    FILE **vhodi = openFiles(stDatotek , "r");
    FILE **izhodni = openFiles(1 , "w");

    

    return 0;
}
