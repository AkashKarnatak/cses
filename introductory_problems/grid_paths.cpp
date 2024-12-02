#include <cstdint>
#include <string>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

int32_t ans = 0;
int32_t num_visited = 0;
bool visited[7][7];
string s;

bool possible(int32_t i, int32_t j) {
  return i >= 0 && i < 7 && j >= 0 && j < 7 && !visited[i][j];
}

void solve(int32_t i, int32_t j, int32_t n) {
  if (i == 6 && j == 0) {
    if (n == 48) {
      ++ans;
    }
    return;
  }
  if (n == 48) {
    return;
  }
  if (possible(i - 1, j) && possible(i + 1, j) && !possible(i, j - 1) && !possible(i, j + 1)) return;
  if (!possible(i - 1, j) && !possible(i + 1, j) && possible(i, j - 1) && possible(i, j + 1)) return;
  visited[i][j] = true;
  ++num_visited;
  if (s[n] == '?') {
    if (possible(i + 1, j)) {
      solve(i + 1, j, n + 1);
    }
    if (possible(i - 1, j)) {
      solve(i - 1, j, n + 1);
    }
    if (possible(i, j + 1)) {
      solve(i, j + 1, n + 1);
    }
    if (possible(i, j - 1)) {
      solve(i, j - 1, n + 1);
    }
  } else if (s[n] == 'R') {
    if (possible(i, j + 1)) {
      solve(i, j + 1, n + 1);
    }
  } else if (s[n] == 'L') {
    if (possible(i, j - 1)) {
      solve(i, j - 1, n + 1);
    }
  } else if (s[n] == 'U') {
    if (possible(i - 1, j)) {
      solve(i - 1, j, n + 1);
    }
  } else if (s[n] == 'D') {
    if (possible(i + 1, j)) {
      solve(i + 1, j, n + 1);
    }
  }
  visited[i][j] = false;
  --num_visited;
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

  cin >> s;

  for (int32_t i = 0; i < 7; ++i) {
    for (int32_t j = 0; j < 7; ++j) {
      visited[i][j] = false;
    }
  }

  solve(0, 0, 0);
  cout << ans << endl;

  return 0;
}
