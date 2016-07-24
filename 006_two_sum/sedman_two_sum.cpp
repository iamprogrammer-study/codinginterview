#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <algorithm>

/*
time complexity : N
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int> cache; //hash table

      for(int idx = 0; idx < nums.size(); ++idx)
      {
        cache.insert({nums[idx], idx});
      }

      std::vector<int> result;
      for(int idx = 0; idx < nums.size(); ++idx)
      {
        auto iter = cache.find(target - nums[idx]);
        if(iter != cache.end() && iter->second != idx)
        {
          result.push_back(iter->second);
          result.push_back(idx);
          return result;
        }
      }

      return std::vector<int>();
    }
};

void test_assert(std::vector<int> test_data, int target,  std::vector<int> expected)
{
  static int tc = 0;
  Solution s;

  auto result  = s.twoSum(test_data, target);
  if(result.size() != expected.size())
  {
    assert(false&&"failed, different size");
  }
  std::sort(result.begin(), result.end());
  for(int idx = 0; idx < result.size(); ++idx)
  {
    if(expected[idx] != result[idx])
    {
      assert(false&&"failed, different value");
    }
  }
  std::cout<<tc++<<") passed\n";
}

int main(void)
{
  test_assert({2, 7, 11, 15}, 9, {0, 1}); 
  test_assert({-5, 11, 234, -1}, -6, {0, 3}); 
  test_assert({-5, 11, -233, -2, 234, -1}, 1, {2, 4}); 
}

