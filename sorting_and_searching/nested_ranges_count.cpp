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
 
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    rordered_multiset;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
 
struct range {
  int32_t l;
  int32_t r;
  int32_t i;
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
 
  vector<range> v;
  for (int32_t i = 0; i < n; ++i) {
    int32_t a, b;
    cin >> a >> b;
    range r = {.l = a, .r = b, .i = i};
    v.push_back(r);
  }
 
  sort(v.begin(), v.end(), [](range a, range b) -> bool {
    if (a.l == b.l)
      return a.r > b.r;
    return a.l < b.l;
  });
 
  vector<int32_t> contains(n);
  vector<int32_t> contained(n);
 
  rordered_multiset contains_end;
  for (int32_t i = n - 1; i >= 0; --i) {
    contains[v[i].i] =
        contains_end.size() - contains_end.order_of_key(v[i].r);
    contains_end.insert(v[i].r);
  }
 
  ordered_multiset contained_end;
  for (int32_t i = 0; i < n; ++i) {
    contained[v[i].i] =
        contained_end.size() - contained_end.order_of_key(v[i].r);
    contained_end.insert(v[i].r);
  }
 
  for (auto x : contains) {
    cout << x << " ";
  }
  cout << endl;
 
  for (auto x : contained) {
    cout << x << " ";
  }
  cout << endl;
 
  return 0;
}
