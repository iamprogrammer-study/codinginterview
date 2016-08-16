#include <cassert>
#include <iostream>

class Solution {
  public:
    int getSum(int a, int b) {
      
      while(b != 0)
      {
          int carry = a & b;
          a = a ^ b;
          b = carry << 1;
      }
      return a;
    }
};

int main(void)
{
  Solution s;
  assert(s.getSum(0, 0) == 0);
  assert(s.getSum(0, 1) == 1);
  assert(s.getSum(1, 0) == 1);
  assert(s.getSum(10, 10) == 20);
  assert(s.getSum(10, -10) == 0);
  assert(s.getSum(-10, -10) == -20);
  assert(s.getSum(-10, -10) == -20);
  assert(s.getSum(-2147483648, -1) == 2147483647);
  return 0;
}
