#include <cstdint>
#include <set>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <algorithm>
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

  int32_t x, n;
  cin >> x >> n;

  int32_t arr[n];
  set<int32_t> s{0, x};
  for (int32_t i = 0; i < n; ++i) {
    cin >> arr[i];
    s.insert(arr[i]);
  }

  vector<int32_t> gaps;

  int32_t max_gap = 0;
  int32_t prev = 0;
  for (auto x : s) {
    max_gap = max(max_gap, x - prev);
    prev = x;
  }
  gaps.push_back(max_gap);

  for (int32_t i = n - 1; i >= 1; --i) {
    auto it = s.find(arr[i]);
    auto low = it, high = it;
    --low, ++high;
    max_gap = max(max_gap, *high - *low);
    gaps.push_back(max_gap);
    s.erase(arr[i]);
  }

  for (auto it = gaps.rbegin(); it != gaps.rend(); ++it) {
    cout << *it << endl;
  }

  return 0;
}
