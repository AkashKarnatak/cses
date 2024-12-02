#include <algorithm>
#include <cstdint>
#include <numeric>
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

bool valid(vector<int32_t> &v, int64_t max, int32_t k) {
  int64_t parts = 1;
  int64_t sum = 0;
  int32_t n = v.size();
  for (int32_t i = 0; i < n; ++i) {
    if (v[i] > max)
      return false;
    if (sum + v[i] <= max) {
      sum += v[i];
    } else {
      ++parts;
      sum = v[i];
    }
  }
  return parts <= k;
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

  int32_t n, k;
  cin >> n >> k;

  vector<int32_t> v(n);
  for (auto &x : v) {
    cin >> x;
  }

  int32_t l = *max_element(v.begin(), v.end()) - 1;
  int64_t u = max((int64_t)*max_element(v.begin(), v.end()), (int64_t)accumulate(v.begin(), v.end(), 0ll));
  int64_t pos = l;

  for (int64_t jmp = u - l; jmp > 0; jmp /= 2) {
    while (!valid(v, pos + jmp, k)) pos += jmp;
  }
  cout << pos + 1 << endl;

  return 0;
}
