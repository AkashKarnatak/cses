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

typedef pair<int32_t, int32_t> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _LOCAL_DEBUG
  freopen((string(getenv("HOME")) + "/.cvim_cache/input.txt").c_str(), "r",
          stdin);
  freopen((string(getenv("HOME")) + "/.cvim_cache/output.txt").c_str(), "w",
          stdout);
#endif

  int32_t n, k;
  cin >> n >> k;

  vector<pii> v(n);
  for (auto &x: v) {
    cin >> x.first >> x.second;
  }

  sort(v.begin(), v.end(), [](pii &a, pii &b) -> bool {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  });

  multiset<int32_t> s;
  for (int32_t i = 0; i < k; ++i) {
    s.insert(0);
  }

  int32_t ans = 0;
  for (int32_t i = 0; i < n; ++i) {
    auto it = s.upper_bound(v[i].first);
    if (it != s.begin()) {
      ++ans;
      s.erase(--it);
      s.insert(v[i].second);
    }
  }
  cout << ans << endl;

  return 0;
}
