#include <stdint.h>
#include <stdio.h>

int main() {
  int64_t n;
  scanf("%ld", &n);
  for (;;) {
    printf("%ld\n", n);
    if (n == 1) {
      break;
    } else if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
  }
  return 0;
}
