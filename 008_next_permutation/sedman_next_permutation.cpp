#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

class Solution_N_Square
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

//reference solution : https://gist.github.com/Baekjoon/f8d9765ccde7262744b5
class Solution_N
{
private:
  void make_reverse(std::vector<int> &array, int from, int to)
  {
    while (from < to) {
        std::swap(array[from], array[to]);
        from += 1; 
        to -= 1;
    }
  }

public:
  void nextPermutation(std::vector<int> &array)
  {
    int idx = array.size() - 1;
    int last_idx = idx;
    while (idx > 0 && array[idx - 1] >= array[idx]) {
        idx -= 1;
    }

    if (idx <= 0) {
      make_reverse(array, 0, last_idx);  
      return; 
    }

    int r_idx = last_idx;
    while (array[idx - 1] >= array[r_idx]) {
        r_idx -= 1;
    }
    std::swap( array[idx - 1], array[r_idx]);
  
    make_reverse(array, idx, last_idx);  
  }
};

void test(std::vector<int> test_set)
{
  static int seq = 1;
  auto test_set2 = test_set;
  std::next_permutation(test_set2.begin(), test_set2.end());
  Solution_N s;
  s.nextPermutation(test_set);

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

