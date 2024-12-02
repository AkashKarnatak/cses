#include <cstdint>
#include <map>
#include <set>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>
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

  int32_t n, k;
  cin >> n >> k;

  vector<int32_t> v(n);
  for (auto &x : v) {
    cin >> x;
  }

  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }

  int32_t i = 0, j = 0;
  map<int32_t, int32_t> m;
  int64_t ans = 0;
  int32_t uniq = 0;

  while (j < n) {
    if (uniq <= k) {
      if (m[v[j]] == 0)
        ++uniq;
      ++m[v[j]];
    }
    if (uniq > k) {
      ans += j - i;
      --m[v[i]];
      if (m[v[i]] == 0)
        --uniq;
      ++i;
    }
    if (uniq <= k) {
      ++j;
    }
  }
  while (i < n) {
    ans += j - i;
    --m[v[i]];
    if (m[v[i]] == 0)
      --uniq;
    ++i;
  }
  cout << ans << endl;

  return 0;
}
