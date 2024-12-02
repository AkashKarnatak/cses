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
    int32_t a, b;
    cin >> a >> b;
    if (2 * a >= b && (2 * a - b) % 3 == 0 && 2 * b >= a)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
