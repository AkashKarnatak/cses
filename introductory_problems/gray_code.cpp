#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

vector<string> solve(int32_t n) {
  if (n == 1)
    return {"0", "1"};

  vector<string> half = solve(n - 1);
  int32_t len = half.size();

  vector<string> ans(len * 2);
  for (int32_t i = 0; i < len; ++i) {
    ans[i] = half[i] + "0";
    ans[len * 2 - 1 - i] = half[i] + "1";
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

  vector<string> ans = solve(n);
  for (auto x: ans) {
    cout << x << endl;
  }

  return 0;
}
