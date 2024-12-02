#include <cstdint>
#include <map>
#include <unordered_map>
#include <unordered_set>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _LOCAL_DEBUG
  freopen((string(getenv("HOME")) + "/.cvim_cache/input.txt").c_str(), "r",
          stdin);
  freopen((string(getenv("HOME")) + "/.cvim_cache/output.txt").c_str(), "w",
          stdout);
#endif

  map<int32_t, int32_t> m;
  int32_t start = 0;

  int32_t n;
  cin >> n;
  int32_t ans = 0;
  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;

    if (m.count(x) > 0 && m[x] >= start) {
      start = m[x] + 1;
    }
    m[x] = i;
    ans = max(ans, i - start + 1);
  }
  cout << ans << endl;

  return 0;
}
