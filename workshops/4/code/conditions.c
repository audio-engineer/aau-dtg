#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum Constants { kTwo = 2, kFive = 5, kNine = 9 };

bool IsPrimeNumber(const int number) {
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

bool IsSpecialNumber(const int number) {
  return (bool)((int)(pow((double)kNine, (double)number) - kTwo) % kFive ==
                kTwo);
}

int main() {
  int number = 0;

  while (true) {
    printf("Enter a number: ");

    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
    scanf("%d", &number);

    // Press `0` to exit
    if (0 == number) {
      break;
    }

    const bool kIsPrimeNumber = IsPrimeNumber(number);
    const bool kIsGreatestCommonDivisorOne =
        IsGreatestCommonDivisorOne(number, 2);
    const bool kIsSpecialNumber = IsSpecialNumber(number);

    // NOLINTBEGIN(readability-implicit-bool-conversion)
    const bool kConditions =
        (kIsPrimeNumber && !kIsSpecialNumber) ||
        !(kIsPrimeNumber || !kIsGreatestCommonDivisorOne || kIsSpecialNumber) ||
        (!kIsPrimeNumber && !kIsGreatestCommonDivisorOne && kIsSpecialNumber);
    // NOLINTEND(readability-implicit-bool-conversion)

    if (!kConditions) {
      printf("Try again.\n");

      continue;
    }

    printf("You found an x!\n");
    printf("\tIs x a prime number? %s\n", (int)kIsPrimeNumber ? "Yes" : "No");
    printf("\tIs greatest common divisor of x and 2 = 1? %s\n",
           (int)kIsGreatestCommonDivisorOne ? "Yes" : "No");
    printf("\tIs 9^x - 2 %% 5 = 2? %s\n", (int)kIsSpecialNumber ? "Yes" : "No");
  }

  return EXIT_SUCCESS;
}
