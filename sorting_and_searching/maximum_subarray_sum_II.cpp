#include <cstdint>
#include <deque>
#include <queue>
#include <set>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _LOCAL_DEBUG
  freopen((string(getenv("HOME")) + "/.cvim_cache/input.txt").c_str(), "r",
          stdin);
  freopen((string(getenv("HOME")) + "/.cvim_cache/output.txt").c_str(), "w",
          stdout);
#endif

  int32_t n, a, b;
  cin >> n >> a >> b;

  vector<int32_t> v(n);
  for (auto &x : v) {
    cin >> x;
  }

  vector<int64_t> cumsum(n);
  cumsum[0] = v[0];
  for (int32_t i = 1; i < n; ++i) {
    cumsum[i] = cumsum[i - 1] + v[i];
  }

  int64_t ans = cumsum[a-1];
  multiset<int64_t> s;
  for (int32_t i = a; i < n; ++i) {
    if (i > b) s.erase(s.find(cumsum[i - b - 1]));
    s.insert(cumsum[i-a]);
    if (s.size() != b - a + 1)
      ans = max(ans, cumsum[i]);
    ans = max(ans, cumsum[i] - *s.begin());
  }
  cout << ans << endl;

  return 0;
}
