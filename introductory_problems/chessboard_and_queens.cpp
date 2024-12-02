#include <cstdint>
#include <string>
#include <vector>
#ifndef _LOCAL_DEBUG
#include <bits/stdc++.h>
#endif
#include <iostream>

using namespace std;

string board[8];
int32_t cols[8] = {0};
int32_t diag1[15] = {0};
int32_t diag2[15] = {0};
int32_t ans = 0;

void solve(int32_t n) {
  if (n == 8) {
    ++ans;
    return;
  }
  for (int32_t i = 0; i < 8; ++i) {
    if (cols[i] == 0 && diag1[n + i] == 0 && diag2[i + 7 - n] == 0 && board[n][i] != '*') {
      cols[i] = 1;
      diag1[n + i] = 1;
      diag2[i + 7 - n] = 1;
      solve(n + 1);
      cols[i] = 0;
      diag1[n + i] = 0;
      diag2[i + 7 - n] = 0;
    }
  }
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

  for (int32_t i = 0; i < 8; ++i) {
    cin >> board[i];
  }

  solve(0);

  cout << ans << endl;

  return 0;
}
