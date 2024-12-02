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

  int32_t arr[n];
  for (int32_t i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int64_t best = arr[0];
  int64_t besti_ = 0;

  for (int32_t i = 0; i < n; ++i) {
    int64_t besti = max((int64_t)arr[i], besti_ + arr[i]);
    if (besti > best) {
      best = besti;
    }
    besti_ = besti;
  }

  cout << best << endl;

  return 0;
}
