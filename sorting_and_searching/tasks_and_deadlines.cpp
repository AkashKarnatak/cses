#include <cstdint>
#include <numeric>
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

  int32_t n;
  cin >> n;

  int64_t du[n];
  int64_t dl[n];
  for (int32_t i = 0; i < n; ++i) {
    cin >> du[i] >> dl[i];
  }

  sort(du, du + n);

  int64_t ans = dl[0] - du[0];
  for (int32_t i = 1; i < n; ++i) {
    du[i] += du[i-1];
    ans += (dl[i] - du[i]);
  }
  cout << ans << endl;

  return 0;
}
