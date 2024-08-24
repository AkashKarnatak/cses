#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  char curr = s[0];
  int32_t curr_len = 1;
  int32_t best = 1;

  int32_t n = s.length();
  for (int32_t i = 1; i < n; ++i) {
    if (s[i] == curr) {
      ++curr_len;
    } else {
      curr = s[i];
      curr_len = 1;
    }
    if (curr_len > best) {
      best = curr_len;
    }
  }

  cout << best << endl;
  return 0;
}
