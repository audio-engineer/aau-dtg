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

bool Is2Mod5(const int number) {
  const int kExponentCalculation = (int)pow(kNine, number % kFive);

  return (bool)((kExponentCalculation - kTwo) % kFive == kTwo);
}

int main() {
  int number = 0;

  while (true) {
    printf("Enter a number: ");

    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
    scanf("%d", &number);

    if (0 == number) {
      break;
    }

    const bool kIsPrimeNumber = IsPrimeNumber(number);
    const bool kIsGreatestCommonDivisor = IsGreatestCommonDivisorOne(number, 2);
    const bool kIs2Mod5 = Is2Mod5(number);

    bool condition =
        ((int)kIsPrimeNumber && !kIs2Mod5) ||
        !((int)kIsPrimeNumber || !kIsGreatestCommonDivisor || (int)kIs2Mod5) ||
        (!kIsPrimeNumber && !kIsGreatestCommonDivisor && (int)kIs2Mod5);

    if (!condition) {
      printf("Try again.\n");

      continue;
    }

    printf("You found an x\n");
    printf("p: %d, q: %d, r: %d\n", (int)kIsPrimeNumber,
           (int)kIsGreatestCommonDivisor, (int)kIs2Mod5);
  }

  return EXIT_SUCCESS;
}
