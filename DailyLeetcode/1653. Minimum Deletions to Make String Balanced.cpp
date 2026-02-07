#include <iostream>
#include <string>
using namespace std;
int minimumDeletions(string s) {
  // b ke baad a ayega to 2 options hai either delete a or delete all b's
  // before a
  int count_b = 0;
  int deletions = 0;
  for (auto &ch : s) {
    if (ch == 'b') {
      count_b += 1;
    } else {
      deletions = min(deletions + 1, count_b);
    }
  }
  return deletions;
}
int main() {}