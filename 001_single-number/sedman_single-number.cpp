#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
      std::sort(nums.begin(), nums.end()); //quick sort
      int n_pair = nums.size()/2;
      int num_idx;
      for(int i = 0; i < n_pair; ++i)
      {
        num_idx = i*2;
        if(nums[num_idx] != nums[num_idx + 1])
        {
          return nums[num_idx];
        }  
      }

      return nums[nums.size() - 1];
    }
};

int main(void)
{
  std::vector<int> nums {2,1,3,2,3,1};
  Solution s;
  std::cout<<s.singleNumber(nums)<<"\n";
  return 0;
}
