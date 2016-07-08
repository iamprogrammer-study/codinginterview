#include <stack>
#include <iostream>
 
class Solution
{
private:
  bool IsWrongOrder(const char open, const char close) const
  {
    return (open == '(' && close != ')')
        || (open == '[' && close != ']')
        || (open == '{' && close != '}');
  }

public:
  bool isValid(std::string s)
  {
    if(s.size() == 1)
    {
      return false;
    }

    std::stack<char> stack;
    for(auto ch : s)
    {
      if(ch == '('
      || ch == '['
      || ch == '{')
      {
        stack.push(ch);
      }
      else
      {
        if( stack.empty() == true
        || IsWrongOrder(stack.top(), ch) == true)
        {
          return false;
        }
        else
        {
          stack.pop();
        }
      }
    }
    return stack.size() == 0;
  }
};

int main(void)
{
  std::string input;
  std::cin>>input; 
  Solution s;
  std::cout<<(s.isValid(input) == true ? "true" : "false")<<"\n";
}
