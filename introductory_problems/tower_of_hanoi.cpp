#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

typedef vector<pair<int32_t, int32_t>> vsol;

vsol solve(int32_t n) {
  if (n == 1) {
    return {make_pair(1, 3)};
  }

  vsol half = solve(n - 1);
  int32_t len = half.size();
  vsol ans(len * 2 + 1);
  for (int32_t i = 0; i < len; ++i) {
    auto p = half[i];
    if (p.first == 3)
      p.first = 2;
    else if (p.first == 2)
      p.first = 3;
    if (p.second == 3)
      p.second = 2;
    else if (p.second == 2)
      p.second = 3;
    ans[i] = p;
  }
  ans[len] = make_pair(1, 3);
  for (int32_t i = 0; i < len; ++i) {
    auto p = half[i];
    if (p.first == 1)
      p.first = 2;
    else if (p.first == 2)
      p.first = 1;
    if (p.second == 1)
      p.second = 2;
    else if (p.second == 2)
      p.second = 1;
    ans[len + 1 + i] = p;
  }
  return ans;
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

  int32_t n;
  cin >> n;

  vsol ans = solve(n);
  cout << ans.size() << endl;
  for (auto x: ans) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}
