#include <vector>
#include <iostream>

class Solution {
private:
  std::vector<std::vector<int>> result;
  std::vector<bool> visited;
  void recursive(const std::vector<int> &nums, std::vector<int>& list)
  {
    if(list.size() == visited.size())
    {
      result.push_back(list);
      return;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
      if(visited[i] == true)
        continue;
      visited[i] = true;
      list.push_back(nums[i]);
      recursive(nums, list);
      list.pop_back();
      visited[i] = false;
    }
  }

public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<int> list;
    visited.resize(nums.size(), false);
    recursive(nums, list);
    return result;
  }
};

int main(void)
{
  Solution s;
  std::vector<int> test {1, 2, 3};
  for(auto list : s.permute(test))
  {
    for(auto item : list)
    {
      std::cout<<item<<" ";
    }
    std::cout<<"\n";
  }
}
