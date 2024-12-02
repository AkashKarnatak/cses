#include <cstdint>
#include <set>
#include <utility>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <algorithm>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// template <typename T, typename _Compare = less<T>>
// using ordered_set = tree<T, null_type, _Compare, rb_tree_tag,
//                          tree_order_statistics_node_update>;
// // lower_bound and upper_bound swaps values for multiset
// template <typename T, typename _Compare = less_equal<T>>
// using ordered_multiset = tree<T, null_type, _Compare, rb_tree_tag,
//                          tree_order_statistics_node_update>;

struct item {
  int32_t i;
  int32_t v;
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

  vector<struct item> v(n);
  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    v[i] = {.i = i, .v = x};
  }

  sort(v.begin(), v.end(), [](struct item &a, struct item &b) -> bool {
    if (a.v == b.v)
      return a.i > b.i;
    return a.v < b.v;
  });

  vector<int32_t> ans(n);
  set<int32_t> s;
  for (int32_t i = 0; i < n; ++i) {
    if (s.empty()) {
      ans[v[i].i] = 0;
      s.insert(v[i].i + 1);
      continue;
    }
    auto it = s.lower_bound(v[i].i + 1);
    if (it == s.begin()) {
      ans[v[i].i] = 0;
    } else {
      ans[v[i].i] = *--it;
    }
    s.insert(v[i].i + 1);
  }

  for (auto x: ans) {
    cout << x << endl;
  }

  return 0;
}
