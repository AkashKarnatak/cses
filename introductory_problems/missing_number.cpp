#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  int32_t n;
  cin >> n;

  int32_t arr[n];
  for (int32_t i = 0; i < n - 1; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n - 1);

  int ans = n;

  for (int32_t i = 0; i < n - 1; ++i) {
    if (i + 1 != arr[i]) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
