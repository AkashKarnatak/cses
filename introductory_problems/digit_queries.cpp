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

  int32_t q;
  cin >> q;

  for (int32_t i = 0; i < q; ++i) {
    int64_t k;
    cin >> k;

    int64_t outer = 9;
    int64_t len = 1;
    while (k > outer) {
      ++len;
      outer += 9 * len * (int64_t)pow(10ll, len - 1);
    }
    int64_t inner = outer - 9 * len * (int64_t)pow(10ll, len - 1) + 1;
    int64_t idx = (k - inner) / len;
    int64_t num = (int64_t)pow(10ll, len - 1) + idx;
    int64_t num_idx = len - 1 - (k - inner) % len;
    for (int64_t j = 0; j < num_idx; ++j) {
      num /= 10;
    }
    cout << num % 10 << endl;
  }

  return 0;
}
