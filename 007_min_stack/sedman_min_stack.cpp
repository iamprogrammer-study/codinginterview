#include <cassert>
#include <stack>
#include <iostream>

class MinStack {
private:
  int min;
  std::stack<int> stack;
  std::stack<int> min_stack;

public:
  MinStack() 
  {
  }

  void push(int x) {
    if(min_stack.empty() == true || min_stack.top() >= x)
    {
      min_stack.push(x);
    }
    stack.push(x);
  }

  void pop() {
    if(stack.empty() == true)
    {
      throw std::underflow_error("empty");
    }
    int top = stack.top();
    stack.pop(); 
    if(top == min_stack.top())
    {
      min_stack.pop();
    }
  }
  
  int top() {
    if(stack.empty() == false)
    {
      return stack.top();
    }
    throw std::underflow_error("empty");
  }

  int getMin() {
    if(min_stack.empty() == false)
    {
      return min_stack.top();
    }
    throw std::underflow_error("empty");
  }
};

void test1(void)
{
  MinStack stack;
  stack.push(2147483646);
  stack.push(2147483646);
  stack.push(2147483647);
  assert(stack.top() == 2147483647);
  stack.pop();
  assert(stack.getMin() == 2147483646 && "failed");
  stack.pop();
  assert(stack.getMin() == 2147483646 && "failed");
  stack.pop();  
  stack.push(2147483647);
  assert(stack.top() == 2147483647);
  assert(stack.getMin() == 2147483647 && "failed");
  stack.push(-2147483648);
  assert(stack.top() == -2147483648);
  assert(stack.getMin() == -2147483648 && "failed");
  stack.pop();
  assert(stack.getMin() == 2147483647 && "failed");
  std::cout<<"passed\n";
}

int main(void)
{
  test1();
  return 0;
}
