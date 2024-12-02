#include <algorithm>
#include <cstdint>
#include <iterator>
#include <string>
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

  string s;
  cin >> s;

  sort(s.begin(), s.end());

  vector<string> ans;
  string prev = "";
  do {
    if (s == prev) {
      continue;
    }
    ans.push_back(s);
    prev = s;
  } while (next_permutation(s.begin(), s.end()));

  cout << ans.size() << endl;
  for (auto x: ans) {
    cout << x << endl;
  }

  return 0;
}
