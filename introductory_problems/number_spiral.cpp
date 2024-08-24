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

  int32_t t;
  cin >> t;

  while (t--) {
    int32_t y, x;
    cin >> y >> x;

    if (y > x) {
      if (y % 2 == 0) {
        cout << (1ll * y * y) - (x - 1) << endl;
      } else {
        cout << (1ll * (y - 1) * (y - 1)) + x << endl;
      }
    } else {
      if (x % 2 == 0) {
        cout << (1ll * (x - 1) * (x - 1)) + y << endl;
      } else {
        cout << (1ll * x * x) - (y - 1) << endl;
      }
    }
  }

  return 0;
}
