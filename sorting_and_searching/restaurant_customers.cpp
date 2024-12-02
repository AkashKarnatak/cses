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

  int32_t a[n];
  int32_t d[n];
  for (int32_t i = 0; i < n; ++i) {
    int32_t at, dt;
    cin >> at >> dt;
    a[i] = at;
    d[i] = dt;
  }

  sort(a, a + n);
  sort(d, d + n);

  int32_t i = 0;
  int32_t j = 0;
  int32_t cnt = 0;
  int32_t ans = 0;

  while (i < n && j < n) {
    if (a[i] < d[j]) {
      cnt += 1;
      if (cnt > ans) {
        ans = cnt;
      }
      ++i;
    } else if (a[i] > d[j]) {
      cnt -= 1;
      ++j;
    } else {
      ++i; ++j;
    }
  }

  for (; i < n; ++i) {
    cnt += 1;
    if (cnt > ans) {
      ans = cnt;
    }
  }

  cout << ans << endl;

  return 0;
}
