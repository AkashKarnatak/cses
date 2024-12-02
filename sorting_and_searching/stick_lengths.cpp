#include <algorithm>
#include <cstdint>
#include <cstdlib>
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

  sort(arr, arr + n);

  int32_t median = arr[n / 2];

  int64_t ans = 0;

  for (int32_t i = 0; i < n; ++i) {
    ans += abs(arr[i] - median);
  }

  cout << ans << endl;

  return 0;
}
