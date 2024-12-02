#include <algorithm>
#include <cstdint>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

vector<int> a{1, 2, 3};
vector<int32_t> sub;

void subset(int32_t n) {
  if (n == a.size()) {
    for (auto x : sub) {
      cout << x << " ";
    }
    cout << endl;
    return;
  }
  subset(n + 1);
  sub.push_back(a[n]);
  subset(n + 1);
  sub.pop_back();
}

vector<bool> cons(a.size());

void permute() {
  if (sub.size() == a.size()) {
    for (auto x : sub) {
      cout << x << " ";
    }
    cout << endl;
    return;
  }
  for (int32_t i = 0; i < a.size(); ++i) {
    if (cons[i])
      continue;
    cons[i] = true;
    sub.push_back(a[i]);
    permute();
    cons[i] = false;
    sub.pop_back();
  }
}

vector<int32_t> pos;
int32_t ans = 0;

void queens(int32_t n) {
  if (n == 4) {
    ++ans;
    for (auto x : pos) {
      cout << x << " ";
    }
    cout << endl;
    return;
  }
  for (int32_t i = 0; i < 4; ++i) {
    int32_t x = [&] {
      if (pos.size() != 0) {
        for (auto x : pos) {
          if (x == i)
            return -1;
        }
        if (abs(pos[pos.size() - 1] - i) <= 1)
          return -1;
      }
      return 0;
    }();
    if (x == -1)
      continue;
    pos.push_back(i);
    queens(n + 1);
    pos.pop_back();
  }
}

int32_t n = 7;
vector<vector<bool>> v(n, vector<bool>(n));

void search(int32_t i, int32_t j) {
  if (i == n - 1 && j == n - 1) {
    ++ans;
    return;
  }
  v[i][j] = true;
  if (i - 1 > 0 && !v[i - 1][j]) {
    search(i - 1, j);
  }
  if (i + 1 < n && !v[i + 1][j]) {
    search(i + 1, j);
  }
  if (j - 1 > 0 && !v[i][j - 1]) {
    search(i, j - 1);
  }
  if (j + 1 < n && !v[i][j + 1]) {
    search(i, j + 1);
  }
  v[i][j] = false;
}

int32_t fast_binary_search(vector<int32_t> arr, int32_t x) {
  int32_t j = 0;
  for (int32_t k = arr.size() - 1; k >= 1; k /= 2) {
    while (x >= arr[j + k])
      j += k;
  }
  if (arr[j] == x)
    return j;
  return -1;
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

  // vector<int> a{1,2,3, 3, 3, 3, 3,10,60};

  // cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(),
  // a.end(), 3) << endl; cout << *lower_bound(a.begin(), a.end(), 4) << endl;

  // do {
  //   for (auto x : a) {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // } while (next_permutation(a.begin(), a.end()));

  // permute();
  // subset(0);

  search(0, 0);
  cout << ans << endl;
  // queens(0);
  return 0;
}
