#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Denne funktion skal returnere 1 hvis x er et primtal og 0 ellers */
int isPrime(int x){
    int result = 1;
    for(int i = 2; i < x / 2; i++){
        if(x % i = 0){
            result = 0;
            break;
        }
    }
    return result;
}

/* Denne funktion skal returnere 1 hvis gcd(x,2)=1 og 0 ellers */
int isGcd1(int x){
    return;
}

/* Denne funktion skal returnere 1 hvis 9^x-2 mod 5 = 2 og 0 ellers */ 
int is2mod5(int x){
    int result = ((int)pow(9, x % 5) - 2) % 5 == 2 ? 1 : 0;
    return result;
}



int main(void){
    int x;
    int p, q, r;
    printf("Hvilket heltal vil du tjekke?\n");
    scanf("%d", &x);
    printf("x er %d\n", x);

    p = isPrime(x);
    q = isGcd1(x);
    r = is2mod5(x);

    if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
        printf("Du fandt et x\n");
        printf("p er %d, q er %d, and r er %d\n", p,q,r);
    } else {
        printf("Proev igen\n");
    }

    return EXIT_SUCCESS;
}