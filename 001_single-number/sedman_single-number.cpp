#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>

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

int main(void)
{
  std::vector<int> nums;
  for(int i = 0; i < 5000000; ++i)
  {
    nums.push_back((i + 1)%9);
  }

  nums.push_back(9);
  
  Solution_n s;
  std::cout<<s.singleNumber(nums)<<"\n";
  return 0;
}
