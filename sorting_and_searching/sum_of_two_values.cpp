#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

bool comp(const pair<int32_t, int32_t> &a, const int32_t &b) {
  return a.first < b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _LOCAL_DEBUG
  freopen((string(getenv("HOME")) + "/.cvim_cache/input.txt").c_str(), "r",
          stdin);
  freopen((string(getenv("HOME")) + "/.cvim_cache/output.txt").c_str(), "w",
          stdout);
#endif

  int32_t n, x;
  cin >> n >> x;

  vector<pair<int32_t, int32_t>> arr;

  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    arr.emplace_back(x, i + 1);
  }

  sort(arr.begin(), arr.end());

  int32_t i = 0;
  for (; i < n; ++i) {
    int32_t y = x - arr[i].first;
    // auto itr = lower_bound(arr.begin(), arr.end(),
    //                        make_pair(y, numeric_limits<int32_t>::min()));
    auto itr = lower_bound(arr.begin(), arr.end(), y, comp);
    if (itr < arr.end() && itr != arr.begin() + i && itr->first == y) {
      cout << arr[i].second << " " << itr->second << endl;
      break;
    }
  }
  if (i == n) {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
