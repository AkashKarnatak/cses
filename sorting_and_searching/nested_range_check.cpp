#include <cstdint>
#include <utility>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int32_t, int32_t> pii;

struct range {
  int32_t l;
  int32_t r;
  int32_t i;
};

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


  vector<range> v;
  for (int32_t i = 0; i < n; ++i) {
    int32_t a, b;
    cin >> a >> b;
    range r = {.l = a, .r = b, .i = i};
    v.push_back(r);
  }

  sort(v.begin(), v.end(), [](range a, range b) -> bool {
    if (a.l == b.l) return a.r > b.r;
    return a.l < b.l;
  });

  vector<int32_t> contained(n);
  vector<int32_t> contains(n);

  if (contains.size() > 1) {
    contains[n-1] = v[n-1].l == v[n-2].l && v[n-1].r == v[n-2].r;
  }

  if (contained.size() > 1) {
    contained[0] = v[0].l == v[1].l && v[0].r == v[1].r;
  }

  int32_t max_end = 0;
  for (int32_t i = 0; i < n; ++i) {
    contained[v[i].i] = v[i].r <= max_end;
    max_end = max(max_end, v[i].r);
  }

  int32_t min_end = 2e9;
  for (int32_t i = n - 1; i >= 0; --i) {
    contains[v[i].i] = min_end <= v[i].r;
    min_end = min(min_end, v[i].r);
  }

  for (auto x : contains) {
    cout << x << " ";
  }
  cout << endl;

  for (auto x : contained) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
