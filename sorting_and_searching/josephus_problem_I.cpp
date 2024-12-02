#include <cstdint>
#include <queue>
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

  bool skip = true;
  queue<int32_t> q;
  for (int32_t i = 1; i <= n; ++i) {
    q.push(i);
  }

  while (!q.empty()) {
    int32_t x = q.front(); q.pop();
    if (skip) {
      q.push(x);
    } else {
      cout << x << endl;
    }
    skip = !skip;
  }

  return 0;
}
