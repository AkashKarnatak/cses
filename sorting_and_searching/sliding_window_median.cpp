#include <cstdint>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

template <typename T, typename _Compare = less<T>>
using ordered_set = tree<T, null_type, _Compare, rb_tree_tag,
                         tree_order_statistics_node_update>;
// lower_bound and upper_bound swaps values for multiset
template <typename T, typename _Compare = less_equal<T>>
using ordered_multiset = tree<T, null_type, _Compare, rb_tree_tag,
                              tree_order_statistics_node_update>;

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

  ordered_multiset<int32_t> s;
  for (int32_t i = 0; i < k; ++i) {
    s.insert(v[i]);
  }
  cout << *s.find_by_order((k - 1) / 2) << endl;
  for (int32_t i = k; i < n; ++i) {
    s.erase(s.upper_bound(v[i - k]));
    s.insert(v[i]);
    cout << *s.find_by_order((k - 1) / 2) << endl;
  }

  return 0;
}
