#include <cstdint>
#include <queue>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <algorithm>
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

class Time {
public:
  int32_t a;
  int32_t d;
  int32_t i;

  Time(int32_t a, int32_t d, int32_t i) : a(a), d(d), i(i) {}

  bool operator<(const Time &other) const {
    if (this->d == other.d)
      return this->a > other.a;
    return this->d > other.d;
  }
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

  vector<Time> v;
  for (int32_t i = 0; i < n; ++i) {
    int32_t a, d;
    cin >> a >> d;
    v.emplace_back(a, d, i);
  }

  sort(v.begin(), v.end(), [](Time &a, struct Time &b) -> bool {
    if (a.a == b.a)
      return a.d < b.d;
    return a.a < b.a;
  });

  int32_t rooms[n];

  priority_queue<Time> q;
  priority_queue<int32_t, vector<int32_t>, greater<int32_t>> available_rooms;
  for (int32_t i = 1; i <= n; ++i) {
    available_rooms.push(i);
  }

  int32_t ans = 0;
  for (int32_t i = 0; i < n; ++i) {
    while (!q.empty() && q.top().d < v[i].a) {
      int32_t room = rooms[q.top().i];
      available_rooms.push(room);
      q.pop();
    }
    rooms[v[i].i] = available_rooms.top();
    available_rooms.pop();
    ans = max(ans, rooms[v[i].i]);
    q.push(v[i]);
  }

  // for (int32_t i = 0; i < n; ++i) {
  //   auto x = v[i];
  //   cout << x.a << ", " << x.d << ", " << x.i << ", " << rooms[v[i].i] << endl;
  // }
  cout << ans << endl;
  for (auto x : rooms) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
