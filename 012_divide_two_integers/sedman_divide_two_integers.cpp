#include <cassert>
#include <limits.h>

/*
처음에는 divide_too_slow처럼 단순하게 분모에서 분자를 계속 빼는 방법으로 구현했는데,
2147483646 / 1 이런 경우가 있어서 leetcode에서 타임 아웃이 납니다.

그래서 구글링한 솔루션을 참조해서 PASS 한 방법은 다음과 같습니다.
분모가 11이고 분자가 3라고 가정하면
3을 왼쪽으로 하나씩 시프트 하면서  11과 가장 가까운 수를 만듭니다.
즉, 6이 되는데,  시프트 한 값이 2가 되는데 6/3의 몫이 됩니다. 이는 숫자 11 중 6을 분자 3으로 나눈 부분 나눗셈 몫이 됩니다.
그리고 나머지 5(11-6)를 같은 과정으로 계산합니다.
마찬가지로 3을 왼쪽으로 하나씩 시프트 하면서 5와 가장 가까운 수를 만드는데,
3이 제일 가까운 수이므로 1 입니다. 그러면 나머지는 2가 되는데,  
2는 분자보다 작으므로 계산을 중단하고 2+1 해서 3이 나오는거죠.
*/

class Solution {
  private:
    long abs(long num)
    {
      return num < 0 ? -num : num;
    }
    
    int get_sign(int num1, int num2)
    {
      if(num1 < 0 && num2 < 0)
        return 1;
      if(num1 < 0 || num2 < 0)
        return -1;
      return 1;
    }

  public:
    int divide_too_slow(int dividend, int divisor) {
      if(dividend == INT_MIN && divisor == 1)
        return INT_MIN;
      if(dividend == INT_MIN && divisor == -1)
        return INT_MAX; 
      if(divisor == 0) 
        return INT_MAX; 
      if(dividend == 0)
        return 0; 
      
      long abs_dividend = abs(static_cast<long>(dividend));
      long abs_divisor = abs(static_cast<long>(divisor));
      int result = 0;
      int add = get_sign(dividend, divisor);
      while(abs_dividend >= abs_divisor)
      {
        result += add;
        abs_dividend -= abs_divisor;
      } 
      return result;
    }
    
    int divide(int dividend, int divisor) 
    {
      if(divisor == 0) return INT_MAX;
      if(divisor == -1 && dividend == INT_MIN)
        return INT_MAX;
      
      long abs_dividend = abs(static_cast<long>(dividend));
      long abs_divisor = abs(static_cast<long>(divisor));
      int result = 0;
      while(abs_dividend >= abs_divisor)
      {
        int num_shift = 0;
        while(abs_dividend >= (abs_divisor << num_shift))
          num_shift++;
        result += 1<<(num_shift - 1);
        abs_dividend -= (abs_divisor << (num_shift - 1));
      }

      if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        return result;
      else
        return -result;
    }  
  };

int main(void)
{
  Solution s;
  assert(s.divide(10, 5) == 2); 
  assert(s.divide(10, 1) == 10); 
  assert(s.divide(10, 3) == 3); 
  assert(s.divide(10, -1) == -10); 
  assert(s.divide(-10, 3) == -3); 
  assert(s.divide(10, 0) == INT_MAX); 
  assert(s.divide(0, 0) == INT_MAX); 
  assert(s.divide(0, 10) ==  0); 
  assert(s.divide(-10, -10) == 1); 
  assert(s.divide(-100, -3) == 33); 
  assert(s.divide(-3, -100) == 0); 
  assert(s.divide(3, -100) == 0); 
  assert(s.divide(3, 100) == 0); 
  assert(s.divide(-2147483648, 2) == -1073741824); 
  assert(s.divide(-2147483648, 1) == -2147483648); 
  assert(s.divide(-2147483648, -1) == 2147483647); 
  return 0;
}
