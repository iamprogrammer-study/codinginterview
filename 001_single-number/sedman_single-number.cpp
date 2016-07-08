#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>
#include <random>
#include <cassert>
#include <climits>

class Solution_nlogn{
public:
    int singleNumber(std::vector<int>& nums) {
      std::sort(nums.begin(), nums.end()); //quick sort
      for(int idx = 0; idx < nums.size(); idx += 2)
      {
        if(nums[idx] != nums[idx + 1])
        {
          return nums[idx];
        }  
      }
      return nums[nums.size() - 1];
    }
};

class Solution_n
{
public:
  int singleNumber(std::vector<int>& nums) {
    std::unordered_map<int, int> check_point;//hash table
    for(auto num : nums)
    {
      check_point[num] += 1;
    }
    
    for(auto point : check_point)
    {
      if(point.second == 1)
      {
        return point.first;
      }
    }
    return -1;//not gonna happen. to prevent build error.
  }  
};

class Solution_n_xor
{
public:
  int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for(auto num : nums)
    {
      result ^= num;
    }
    return result;
  }
};

int main(void)
{
  std::vector<int> nums;
  for(int i = -1000000; i < 1000000; ++i)
  {
    nums.push_back(i+1);
    nums.push_back(i+1);
  }
  nums.push_back(INT_MAX);

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(nums.begin(), nums.end(), g);

  Solution_n s;
  assert(s.singleNumber(nums) == INT_MAX);
  std::cout<<"passed\n";
  return 0;
}
