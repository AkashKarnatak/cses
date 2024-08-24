#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t m = (int32_t)1e9 + 7;

int32_t large_fact(int32_t x) {
  int32_t ans = 1;
  for (int32_t i = 1; i <= x; ++i) {
    ans = (int64_t)ans * i % m;
    ans %= m;
  }
  return ans;
}

bool is_prime(int32_t x) {
  if (x % 2 == 0)
    return false;
  for (int32_t i = 3; i * i <= x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

pair<int32_t, int32_t> least_efficient_subarray_max(vector<int32_t> arr) {
  int32_t n = arr.size();
  int32_t ans = 0;
  int32_t steps = 0;
  for (int32_t beg = 0; beg < n; ++beg) {
    for (int32_t end = beg; end < n; ++end) {
      int64_t sum = 0;
      for (int32_t i = beg; i < end; ++i) {
        sum += arr[i];
        ++steps;
      }
      if (sum > ans) {
        ans = sum;
      }
    }
  }
  return make_pair(ans, steps);
}

pair<int32_t, int32_t> ok_subarray_max(vector<int32_t> arr) {
  int32_t n = arr.size();
  int32_t ans = 0;
  int32_t steps = 0;
  for (int32_t beg = 0; beg < n; ++beg) {
    int64_t sum = 0;
    for (int32_t i = beg; i < n; ++i) {
      sum += arr[i];
      ++steps;
      if (sum > ans) {
        ans = sum;
      }
    }
  }
  return make_pair(ans, steps);
}

pair<int32_t, int32_t> best_subarray_max(vector<int32_t> arr) {
  int32_t n = arr.size();
  int32_t ans = 0;
  int32_t steps = 0;
  int32_t sum = 0;
  for (int32_t i = 0; i < n; ++i) {
    sum = max(arr[i], sum + arr[i]);
    ++steps;
    if (sum > ans) {
      ans = sum;
    }
  }
  return make_pair(ans, steps);
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

  vector<int32_t> arr({-1, 2, 4, -3, 5, 2, -5, 2});

  {
    auto [ans, steps] = least_efficient_subarray_max(arr);
    cout << "Ans: " << ans << " Steps: " << steps << endl;
  }

  {
    auto [ans, steps] = ok_subarray_max(arr);
    cout << "Ans: " << ans << " Steps: " << steps << endl;
  }

  {
    auto [ans, steps] = best_subarray_max(arr);
    cout << "Ans: " << ans << " Steps: " << steps << endl;
  }

  return 0;
}
