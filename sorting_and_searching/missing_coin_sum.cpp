#include <algorithm>
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

  sort(arr, arr + n);

  int64_t ans = 0;

  if (arr[0] != 1) {
    cout << 1 << endl;
    return 0;
  }

  for (int32_t i = 0; i < n; ++i) {
    if (arr[i] <= ans + 1) {
      ans += arr[i];
    } else {
      break;
    }
  }

  cout << ans + 1 << endl;

  return 0;
}
