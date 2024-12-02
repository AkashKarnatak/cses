#include <algorithm>
#include <cstdint>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>
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

int64_t value(vector<int32_t> &ts, int64_t n) {
  int64_t sum = 0;
  for (auto &x : ts) {
    sum += n / x;
  }
  return sum;
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

  int32_t n, t;
  cin >> n >> t;

  vector<int32_t> ts(n);
  for (auto &x : ts) {
    cin >> x;
  }

  int64_t l = 0;
  int64_t u = *min_element(ts.begin(), ts.end()) * (int64_t)t;

  int64_t ans = l;
  for (int64_t jmp = u - l + 1; jmp > 0; jmp /= 2) {
    while (value(ts, ans + jmp) < t)
      ans += jmp;
  }
  cout << ans + 1 << endl;

  return 0;
}
