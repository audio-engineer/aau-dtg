#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum { kTwo = 2, kFive = 5, kNine = 9 };

/* Denne funktion skal returnere 1 hvis x er et primtal og 0 ellers */
bool IsPrime(int number) {
  for (int i = 2; i < number / 2; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

/* Denne funktion skal returnere 1 hvis gcd(x,2)=1 og 0 ellers */
bool IsGcd1(int number);

/* Denne funktion skal returnere 1 hvis 9^x-2 mod 5 = 2 og 0 ellers */
bool Is2Mod5(int number) {
  int exponent_calculation = (int)pow(kNine, number % kFive);
  // NOLINTNEXTLINE(readability-implicit-bool-conversion)
  return (exponent_calculation - kTwo) % kFive == kTwo;
}

int main(void) {
  int number_to_test = 0;
  int is_prime_number = 0;
  int is_greatest_common_divisor = 0;
  int is_2mod5 = 0;
  printf("Hvilket heltal vil du tjekke?\n");
  // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
  scanf("%d", &number_to_test);
  printf("x er %d\n", number_to_test);

  // NOLINTNEXTLINE(readability-implicit-bool-conversion)
  is_prime_number = IsPrime(number_to_test);
  // NOLINTNEXTLINE(readability-implicit-bool-conversion)
  is_greatest_common_divisor = IsGcd1(number_to_test);
  // NOLINTNEXTLINE(readability-implicit-bool-conversion)
  is_2mod5 = Is2Mod5(number_to_test);

  if ((is_prime_number && !is_2mod5) ||
      !(is_prime_number || !is_greatest_common_divisor || is_2mod5) ||
      (!is_prime_number && !is_greatest_common_divisor && is_2mod5)) {
    printf("Du fandt et x\n");
    printf("p er %d, q er %d, and r er %d\n", is_prime_number,
           is_greatest_common_divisor, is_2mod5);
  } else {
    printf("Proev igen\n");
  }

  return EXIT_SUCCESS;
}
