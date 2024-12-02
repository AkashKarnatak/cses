#include <algorithm>
#include <cstdint>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>

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

  vector<int32_t> arr;

  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    auto it = upper_bound(arr.begin(), arr.end(), x);
    if (it == arr.end()) {
      arr.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << arr.size() << endl;


  return 0;
}
