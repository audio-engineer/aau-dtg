#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Denne funktion skal returnere 1 hvis x er et primtal og 0 ellers */
int isPrime(int number) {
  int result = 1;
  for (int i = 2; i < number / 2; i++) {
    if (number % i == 0) {
      result = 0;
      break;
    }
  }
  return result;
}

/* Denne funktion skal returnere 1 hvis gcd(x,2)=1 og 0 ellers */
int isGcd1(int number) { return 1; }

/* Denne funktion skal returnere 1 hvis 9^x-2 mod 5 = 2 og 0 ellers */
int is2mod5(int number) {
  int result = ((int)pow(9, number % 5) - 2) % 5 == 2 ? 1 : 0;
  return result;
}

int main(void) {
  int number_to_test;
  int isPrime_bool, isGcd1_bool, is2mod5_bool;
  printf("Hvilket heltal vil du tjekke?\n");
  scanf("%d", &number_to_test);
  printf("x er %d\n", number_to_test);

  isPrime_bool = isPrime(number_to_test);
  isGcd1_bool = isGcd1(number_to_test);
  is2mod5_bool = is2mod5(number_to_test);

  if ((isPrime_bool && !is2mod5_bool) ||
       !(isPrime_bool || !isGcd1_bool || is2mod5_bool) ||
       (!isPrime_bool && !isGcd1_bool && is2mod5_bool)) {
    printf("Du fandt et x\n");
    printf("p er %d, q er %d, and r er %d\n", isPrime_bool, isGcd1_bool,
           is2mod5_bool);
  }
  else {
    printf("Proev igen\n");
  }

  return EXIT_SUCCESS;
}
