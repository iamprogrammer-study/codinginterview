#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> table;
std::vector<std::vector<int>> track;

void update_track(const int idx1, const int idx2, const int track_num)
{
  track[idx1 - 1][idx2 - 1] = track_num;
}

int lcs(const std::string &str1, const std::string &str2)
{
  std::size_t str1_size = str1.size();
  std::size_t str2_size = str2.size();

  for(int idx1 = 1; idx1 <= str1_size; ++idx1)
  {
    for(int idx2 = 1; idx2 <= str2_size; ++idx2)
    {
      if(str1[idx1 - 1] == str2[idx2 - 1])
      {
        update_track(idx1, idx2, 1);
        table[idx1][idx2] = table[idx1 - 1][idx2 - 1] + 1;
      }
      else if(table[idx1][idx2 - 1] > table[idx1 - 1][idx2])
      {
        update_track(idx1, idx2, 2);
        table[idx1][idx2] = table[idx1][idx2 - 1];
      }
      else
      {
        update_track(idx1, idx2, 3);
        table[idx1][idx2] = table[idx1 - 1][idx2];
      }
    }
  }

  return table[str1_size][str2_size];
}

void print_lcs(const std::string &str, const int idx1, const int idx2)
{
  if(idx1 == -1 || idx2 == -1)
  {
    return;
  }

  int track_num = track[idx1][idx2];
  if(track_num == 1)
  {
    print_lcs(str, idx1 - 1, idx2 - 1);
    std::cout<<str[idx1];
  }
  else if(track_num == 2)
  {
    print_lcs(str, idx1, idx2 - 1);
  } 
  else if(track_num == 3)
  {
    print_lcs(str, idx1 - 1, idx2);
  } 

}

int main(void)
{
  std::string str1, str2;
  std::cin>>str1;
  std::cin>>str2;
 
  //size + 1 because of basis 
  table.resize(str1.size() + 1, std::vector<int>(str2.size() + 1));  
  
  track.resize(str1.size(), std::vector<int>(str2.size()));  

  std::cout<<lcs(str1, str2)<<"\n";
  print_lcs(str1, str1.size() - 1, str2.size() - 1); 
  return 0;
}
