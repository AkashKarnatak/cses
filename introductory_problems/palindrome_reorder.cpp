#include <cstdint>
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

  vector<int32_t> count(26);

  for (auto x : s) {
    count[x - 'A'] += 1;
  }

  int32_t op = 0;
  string oc = "";
  for (int32_t i = 0; i < 26; ++i) {
    if (count[i] % 2 != 0) {
      ++op;
      if (op > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      oc += i + 'A';
    }
  }
  string front = "";
  for (char c = 'A'; c <= 'Z'; ++c) {
    for (int32_t i = 0; i < count[c - 'A'] / 2; ++i) {
      front += c;
    }
  }
  string back = "";
  for (auto it = front.rbegin(); it < front.rend(); ++it) {
    back += *it;
  }
  cout << front + oc + back << endl;

  return 0;
}
