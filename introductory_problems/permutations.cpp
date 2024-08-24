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

  if (n == 1) {
    cout << 1 << endl;
  } else if (n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
  } else {
    for (int32_t i = 2; i <= n; i += 2) {
      cout << i << " ";
    }
    for (int32_t i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
