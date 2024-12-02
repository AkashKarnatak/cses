#include <cstdint>
#include <utility>
#include <vector>
#include <algorithm>
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

  vector<pair<int32_t, int32_t>> arr;

  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    arr.emplace_back(x, i);
  }

  sort(arr.begin(), arr.end());

  int32_t ans = 1;

  for (int32_t i = 0; i < n - 1; ++i) {
    if (arr[i].second > arr[i + 1].second) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
