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

  if (n % 4 != 0 && (n + 1) % 4 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  if (n % 4 == 0) {
    cout << n / 2 << endl;

    for (int32_t i = 1; i <= n / 2; i += 2) {
      cout << i << " ";
    }
    for (int32_t i = n / 2 + 2; i <= n; i += 2) {
      cout << i << " ";
    }
    cout << endl;

    cout << n / 2 << endl;
    for (int32_t i = 2; i <= n / 2; i += 2) {
      cout << i << " ";
    }
    for (int32_t i = n / 2 + 1; i <= n; i += 2) {
      cout << i << " ";
    }
    cout << endl;

    return 0;
  }

  if ((n + 1) % 4 == 0) {
    cout << n / 2 + 1 << endl;

    cout << "1 2 ";
    for (int32_t i = 1; i <= (n - 3) / 2; i += 2) {
      cout << i + 3 << " ";
    }
    for (int32_t i = (n - 3) / 2 + 2; i <= n - 3; i += 2) {
      cout << i + 3 << " ";
    }
    cout << endl;

    cout << n / 2 << endl;
    cout << "3 ";
    for (int32_t i = 2; i <= (n - 3) / 2; i += 2) {
      cout << i + 3 << " ";
    }
    for (int32_t i = (n - 3) / 2 + 1; i <= n - 3; i += 2) {
      cout << i + 3 << " ";
    }
    cout << endl;

  }

  return 0;
}
