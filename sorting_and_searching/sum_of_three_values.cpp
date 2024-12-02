#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

class Sum {
public:
  int32_t i;
  int32_t j;
  int64_t v;

  Sum(int32_t i, int32_t j, int64_t v) : i(i), j(j), v(v) {}

  bool operator<(const Sum &other) const { return this->v < other.v; }
};

using namespace std;
// using namespace __gnu_pbds;

// template <typename T, typename _Compare = less<T>>
// using ordered_set = tree<T, null_type, _Compare, rb_tree_tag,
//                          tree_order_statistics_node_update>;
// // lower_bound and upper_bound swaps values for multiset
// template <typename T, typename _Compare = less_equal<T>>
// using ordered_multiset = tree<T, null_type, _Compare, rb_tree_tag,
//                          tree_order_statistics_node_update>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _LOCAL_DEBUG
  freopen((string(getenv("HOME")) + "/.cvim_cache/input.txt").c_str(), "r",
          stdin);
  freopen((string(getenv("HOME")) + "/.cvim_cache/output.txt").c_str(), "w",
          stdout);
#endif

  int32_t n, x;
  cin >> n >> x;

  vector<pair<int32_t, int32_t>> v(n);
  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    v[i].first = x;
    v[i].second = i;
  }
  sort(v.begin(), v.end());

  [&v, &x, &n]() {
    for (int32_t i = 0; i < n; ++i) {
      for (int32_t j = i + 1, k = n - 1; j < k;) {
        int64_t sum = (int64_t)v[i].first + v[j].first + v[k].first;
        if (sum == x) {
          cout << v[i].second + 1 << " " << v[j].second + 1 << " "
               << v[k].second + 1 << endl;
          return;
        } else if (sum > x) {
          --k;
        } else {
          ++j;
        }
      }
    }
    cout << "IMPOSSIBLE" << endl;
  }();

  return 0;
}
