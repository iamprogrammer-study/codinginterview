#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> matrix_t;
class Solution {
  private:
    int rows, cols;
    std::vector<int> result;
    int update_cols(matrix_t &matrix, int start, int adder, int size)
    {
      result.push_back(matrix[start / cols][start % cols]);
      return update_rows(matrix, start, adder, size);
    }
    
    int update_rows(matrix_t &matrix, int start, int adder, int size)
    {
      for(int i = 0; i < size - 1; ++i)
      {
        start += adder;
        result.push_back(matrix[start / cols][start % cols]);
      }
      return start;
    }

  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
      if(matrix.empty() == true)
      {
        return {};
      }
      
      rows = matrix.size();
      cols = matrix[0].size();
      int sign = 1;
      int idx = -1;
      int cnt = 0;
      while(cols - cnt <= 0 || rows - cnt <= 0)
      {
        int cols_idx = update_cols(matrix, idx + 1 * sign, 1 * sign, cols - cnt);
        idx = update_rows(matrix, cols_idx, cols * sign, rows - cnt);
        sign *= -1;
        ++cnt;
      }
      return result;
    }
};

int main(void)
{
  Solution s;
  matrix_t matrix = {{2, 5, 0}, {4, 0, -1}};
  for(auto item : s.spiralOrder(matrix))
  {
    std::cout<<item<<" ";
  }
  std::cout<<"\n";
}

