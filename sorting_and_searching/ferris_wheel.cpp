#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
#ifdef _LOCAL_DEBUG
  freopen("../.cvim_cache/input.txt", "r", stdin);
  freopen("../.cvim_cache/output.txt", "w", stdout);
#endif

  int32_t n, x;
  cin >> n >> x;

  int32_t ws[n];
  for (int32_t i = 0; i < n; ++i) {
    cin >> ws[i];
  }

  sort(ws, ws + n);

  int32_t ans = 0;
  for (int32_t i = 0, j = n - 1; i <= j; --j) {
    if (i != j && ws[j] + ws[i] <= x) {
      ++ans;
      ++i;
    } else if (ws[j] <= x) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
