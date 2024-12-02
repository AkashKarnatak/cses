#include <cmath>
#include <cstdint>
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

  int32_t n;
  cin >> n;

  int32_t mod = 1e9 + 7;

  int32_t ans = 1;
  for (int32_t i = 0; i < n; ++i) {
    ans = ans * 2;
    if (ans >= mod) {
      ans = ans - mod;
    }
  }
  cout << ans << endl;

  return 0;
}
