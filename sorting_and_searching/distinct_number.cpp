#include <cstdint>
#include <iostream>
#include <set>

using namespace std;

int main() {
  int32_t n;
  cin >> n;

  set<int32_t> nums;
  for (int32_t i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nums.insert(x);
  }

  cout << nums.size() << endl;

  return 0;
}
