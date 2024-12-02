#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>
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

  vector<pair<int32_t, int32_t>> m;
  for (int32_t i = 0; i < n; ++i) {
    int32_t st, et;
    cin >> st >> et;
    m.emplace_back(et, st);
  }

  sort(m.begin(), m.end());

  int32_t ans = 0;
  int32_t cur = 0;

  for (auto [et, st]: m) {
    if (cur <= st) {
      cur = et;
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
