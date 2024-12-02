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

  int32_t n, m;
  cin >> n >> m;

  int32_t arr[n];
  int32_t idx[n];
  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    --x;
    arr[i] = x;
    idx[x] = i;
  }

  int32_t ans = 1;
  bool pairs[n - 1];
  for (int32_t i = 0; i < n - 1; ++i) {
    pairs[i] = false;
    if (idx[i] > idx[i + 1]) {
      ++ans;
      pairs[i] = true;
    }
  }

  while (m--) {
    int32_t a, b;
    cin >> a >> b;
    --a;
    --b;

    int32_t tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
    idx[arr[a]] = a;
    idx[arr[b]] = b;

    a = arr[a];
    b = arr[b];

    if (a - 1 >= 0 && idx[a - 1] > idx[a] && !pairs[a - 1]) {
      pairs[a - 1] = true;
      ++ans;
    } else if (a - 1 >= 0 && idx[a - 1] <= idx[a] && pairs[a - 1]) {
      pairs[a - 1] = false;
      --ans;
    }
    if (a + 1 < n && idx[a] > idx[a + 1] && !pairs[a]) {
      pairs[a] = true;
      ++ans;
    } else if (a + 1 < n && idx[a] <= idx[a + 1] && pairs[a]) {
      pairs[a] = false;
      --ans;
    }
    if (b - 1 >= 0 && idx[b - 1] > idx[b] && !pairs[b - 1]) {
      pairs[b - 1] = true;
      ++ans;
    } else if (b - 1 >= 0 && idx[b - 1] <= idx[b] && pairs[b - 1]) {
      pairs[b - 1] = false;
      --ans;
    }
    if (b + 1 < n && idx[b] > idx[b + 1] && !pairs[b]) {
      pairs[b] = true;
      ++ans;
    } else if (b + 1 < n && idx[b] <= idx[b + 1] && pairs[b]) {
      pairs[b] = false;
      --ans;
    }

    cout << ans << endl;
  }

  return 0;
}
