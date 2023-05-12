#include<stdio.h>
#include<stdbool.h>
#include <math.h>

int getInt();   
int putInt();   

int main(){
    //novo
    int x = getInt();
    int y = getInt();

    int z = x + y;

    putInt(z);

    return 0;
}

int getInt(){
    bool predznaceno = false;
    int stevilo = 0;

    int x = getchar();


    if(x == '-'){
        predznaceno = true;
        x = getchar();
    }

    while( x != ' ' && x != '\n'){
        stevilo = (stevilo*10) + ( x - '0' );
        x = getchar();
    }

    if(predznaceno){
        stevilo = stevilo* (-1);
    }

    return stevilo;
}

int putInt(int x){
    int delitelj = 1;

    if( x < 0 ){
       putchar('-');
       x = x * (-1);
    }

    while(( x / delitelj ) > 9){
        delitelj *=10;
    }

    while(delitelj > 0){

        putchar((x/delitelj)+ '0');

        x = x % delitelj; 

        
        delitelj /= 10;
    }

    
    return 0;
}