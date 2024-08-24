#include <algorithm>
#include <cmath>
#include <cstdint>
#include <set>
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

  int32_t n, m;
  cin >> n >> m;

  multiset<int32_t> ti;
  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    ti.insert(x);
  }

  for (int32_t i = 0; i < m; ++i) {
    if (ti.size() == 0) {
      cout << -1 << " ";
      continue;
    }

    int32_t x;
    cin >> x;
    auto it = ti.upper_bound(x);

    if (it == ti.begin()) { // first match
      cout << -1 << " ";
    } else {
      --it;
      cout << *it << " ";
      ti.erase(*it);
    }
  }
  cout << endl;

  return 0;
}
