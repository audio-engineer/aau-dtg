#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum Constants { kTwo = 2, kFive = 5, kNine = 9 };

bool IsPrimeNumber(int number) {
  for (int i = 2; i < number / 2; i++) {
    if (number % i == 0) {
      return false;
    }
  }

  return true;
}

bool IsGreatestCommonDivisorOne(int number_one, int number_two) {
  // NOLINTNEXTLINE(readability-identifier-length)
  int r = 0;

  while (number_two != 0) {
    r = number_one % number_two;

    number_one = number_two;
    number_two = r;
  }

  return (bool)(number_one == 1);
}

bool Is2Mod5(int number) {
  int exponent_calculation = (int)pow(kNine, number % kFive);

  return (bool)((exponent_calculation - kTwo) % kFive == kTwo);
}

int main() {
  int number = 0;

  printf("Enter a number: ");

  // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
  scanf("%d", &number);

  bool is_prime_number = IsPrimeNumber(number);
  bool is_greatest_common_divisor = IsGreatestCommonDivisorOne(number, 2);
  bool is_2mod5 = Is2Mod5(number);

  if (((int)is_prime_number && !is_2mod5) ||
      !((int)is_prime_number || !is_greatest_common_divisor || (int)is_2mod5) ||
      (!is_prime_number && !is_greatest_common_divisor && (int)is_2mod5)) {
    printf("You found an x\n");
    printf("p: %d, q: %d, r: %d\n", (int)is_prime_number,
           (int)is_greatest_common_divisor, (int)is_2mod5);

    return EXIT_SUCCESS;
  }

  printf("Try again.\n");

  return EXIT_SUCCESS;
}
