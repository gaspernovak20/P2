#include<stdio.h>

int getInt();
int toBin(int bin_stevilo);
int log_dva(int x);


int main(){

    int bin_stevilo = getInt();

    int stevilo = toBin(bin_stevilo); 

    int log2_vrednost = log_dva(stevilo);

    printf("%d\n", log2_vrednost );
    return 0;
}

int log_dva(int x){    
    int stevilo = 1;
    int i = 0;

    while(x > stevilo){
        i++;
        stevilo *=2;
    }

    return i;
}

int toBin(int bin_stevilo){

    int stevilo = 0;
    int dvojice = 1;

    while(bin_stevilo > 0){    

        stevilo += (bin_stevilo % 10) * dvojice;

        bin_stevilo /= 10;

        dvojice *= 2;
    }       

    return stevilo;
}

int getInt(){

    int stevilo = 0;

    int x = getchar();

    while(x != ' ' && x != '\n'){
        stevilo = ( stevilo*10 ) + ( x - '0' );
        x = getchar();
    }

    return stevilo;
}