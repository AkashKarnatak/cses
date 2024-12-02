#include <cstdint>
#include <set>
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

  int32_t lower_size = (k + 1) / 2;
  int32_t upper_size = k - lower_size;
  multiset<int32_t> ls;
  multiset<int32_t> us;

  int64_t lower_sum = 0, upper_sum = 0;
  for (int32_t i = 0; i < k; ++i) {
    ls.insert(v[i]);
    us.insert(v[i]);
    lower_sum += v[i];
    upper_sum += v[i];
  }
  while (ls.size() != lower_size) {
    lower_sum -= *--ls.end();
    ls.erase(--ls.end());
  }
  while (us.size() != upper_size) {
    upper_sum -= *us.begin();
    us.erase(us.begin());
  }

  cout << (lower_size * *ls.rbegin() - lower_sum) +
              (upper_sum - upper_size * *ls.rbegin())
       << endl;

  for (int32_t i = k; i < n; ++i) {
    auto it = ls.find(v[i - k]);
    if (it != ls.end()) {
      lower_sum -= *it;
      ls.erase(it);
    } else {
      auto it = us.find(v[i - k]);
      upper_sum -= *it;
      us.erase(it);
    }
    if (ls.size() > 0 && v[i] <= *ls.rbegin()) {
      ls.insert(v[i]);
      lower_sum += v[i];
    } else {
      us.insert(v[i]);
      upper_sum += v[i];
    }
    while (ls.size() != lower_size) {
      if (ls.size() < lower_size) {
        lower_sum += *us.begin();
        ls.insert(*us.begin());
        upper_sum -= *us.begin();
        us.erase(us.begin());
      } else {
        upper_sum += *ls.rbegin();
        us.insert(*ls.rbegin());
        lower_sum -= *--ls.end();
        ls.erase(--ls.end());
      }
    }
    cout << (lower_size * *ls.rbegin() - lower_sum) +
                (upper_sum - upper_size * *ls.rbegin())
         << endl;
  }

  return 0;
}
