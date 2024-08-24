#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int64_t n;
  cin >> n;

  for (;;) {
    cout << n << endl;

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
