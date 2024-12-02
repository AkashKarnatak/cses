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
  int64_t sum = 0;
  for (int32_t i = 0; i < n; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }

  int64_t ans = 2e9;
  for (int32_t i = 0; i < (1 << n); ++i) {
    int64_t first_sum = 0;
    for (int32_t j = 0; j < n; ++j) {
      if ((1 << j) & i) {
        first_sum += arr[j];
      }
    }
    int64_t second_sum = sum - first_sum;
    int64_t diff = abs(second_sum - first_sum);
    ans = min(ans, diff);
  }

  cout << ans << endl;

  return 0;
}
