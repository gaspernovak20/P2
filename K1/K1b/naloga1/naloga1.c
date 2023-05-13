
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int main() {
    // dopolnite ...

    int n;
    scanf("%d", &n);

    int *a = (int*)malloc(n*sizeof(int));

    //vnos a kordinate
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    //vnos b kordinate
    int *b = (int*)malloc(n*sizeof(int));

    for(int j = 0; j < n; j++){
         scanf("%d", &b[j]);
    }


    //izracun razdalje

    int razdalja = 0;

    for(int x = 0; x<n; x++){
        razdalja += ((a[x] - b[x])* (a[x] - b[x]));
    }

    printf("%d", razdalja);

    return 0;
}
