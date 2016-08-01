#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
  void nextPermutation(std::vector<int> &array)
  {
    if(array.size() == 1)
    {
      return;
    }

    int i = -1;
    bool flag_break = false;
    for(i = (array.size() - 2); i >= 0; --i)
    {
      for(int j = (array.size() - 1); j > i; --j)
      {
        if(array[i] < array[j])
        {
          std::swap(array[i], array[j]);
          flag_break = true;
          break;
        }
      }
      if(flag_break == true)
        break;
    }

    std::sort(array.begin() + i + 1, array.end()); //quick sort
  }
};

void test(std::vector<int> test_set)
{
  static int seq = 1;
  auto test_set2 = test_set;
  std::next_permutation(test_set2.begin(), test_set2.end());
  Solution s;
  s.next_permutation(test_set);

  for(int i = 0; i < test_set.size(); ++i)
  {
    if(test_set2[i] != test_set[i])
    {
      std::cout<<seq<<" test failed\n";
      assert(false);
    }
  }

  ++seq;
}

int main(void)
{
  test({1, 4, 3, 2, 1});
  test({1, 4, 0, 5, 1});
  test({1});
  test({1, 2});
  test({1, 1});
  test({5, 4, 3, 2, 1});
  
  std::cout<<"passed\n";
  return 0;      
}

