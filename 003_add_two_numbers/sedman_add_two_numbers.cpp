#include <stack>
#include <iostream>
#include <cmath>
#include <cassert>

struct ListNode 
{
  int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
private:
  std::size_t get_number(ListNode *head)
  {
    std::size_t result = 0;
    std::size_t carry = 0;
    while(head != nullptr)
    {
      result += (head->val * pow(10, carry++));
      head = head->next;
    }
    return result;
  }

  ListNode* make_list(std::size_t number)
  {
    if(number == 0)
    {
      return new ListNode(0);
    }

    ListNode *head = nullptr;
    ListNode *node = nullptr;
    while(number > 0)
    {
      ListNode *now = new ListNode(number%10);
      if(head == nullptr)
      {
        head = node = now;
      }
      else
      {
        node->next = now;
        node = node->next; 
      }
      number = number/10;
    }

    return head;
  }

public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    return make_list(get_number(l1) + get_number(l2));
  }

  void test(void)
  {
    ListNode *node1 = new ListNode(10);
    ListNode *node2 = new ListNode(0);
    assert(get_number(node1) == 10);
    assert(get_number(node2) == 0);
    delete node1;
    delete node2;
 
    //Let's ignore the deallocation because it's just a test. 
    assert(make_list(0) != nullptr);
    assert(get_number(make_list(12345)) == 12345);
    assert(get_number(make_list(1)) == 1);
    assert(get_number(make_list(0)) == 0);
    assert(get_number(make_list(10000)) == 10000);
  }
};

int main(void)
{
  Solution s;
  s.test();
  std::cout<<"passed\n";
  return 0;
}
