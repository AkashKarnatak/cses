#include <cstdint>
#include <iostream>
using namespace std;

int main() {
#ifdef _LOCAL_DEBUG
  freopen("../.cvim_cache/input.txt", "r", stdin);
  freopen("../.cvim_cache/output.txt", "w", stdout);
#endif

  int32_t n;
  cin >> n;

  int32_t arr[n];
  for (int32_t i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int64_t ans = 0;
  for (int32_t i = 1; i < n; ++i) {
    if (arr[i] < arr[i - 1]) {
      ans += (arr[i - 1] - arr[i]);
      arr[i] = arr[i - 1];
    }
  }

  cout << ans << endl;

  return 0;
}
