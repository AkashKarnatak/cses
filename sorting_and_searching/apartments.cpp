#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
#ifdef _LOCAL_DEBUG
  freopen("../.cvim_cache/input.txt", "r", stdin);
  freopen("../.cvim_cache/output.txt", "w", stdout);
#endif

  int32_t n, m, k;
  cin >> n;
  cin >> m;
  cin >> k;

  int32_t req[n];
  int32_t avail[m];

  for (int32_t i = 0; i < n; ++i) {
    cin >> req[i];
  }

  for (int32_t i = 0; i < m; ++i) {
    cin >> avail[i];
  }

  sort(req, req + n);
  sort(avail, avail + m);

  int32_t ans = 0;
  for (int32_t i = 0, j = 0; i < n && j < m;) {
    if (avail[j] < req[i] - k) {
      ++j;
    } else if (avail[j] == req[i] ||
               (avail[j] >= req[i] - k && avail[j] <= req[i] + k)) {
      ++ans;
      ++i;
      ++j;
    } else if (avail[j] > req[i] + k) {
      ++i;
    }
  }

  cout << ans << endl;

  return 0;
}
