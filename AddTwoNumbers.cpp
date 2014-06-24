#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};

ListNode * reverse(ListNode *l, int *len);
ListNode * addTwoNumbers(ListNode *l1, ListNode *l2);

int main()
{
  ListNode *l1(0), *l2(0), *l3(0);
  l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  
  l3 = addTwoNumbers(l1, l2);
  
  while(l3)
    {
      cout << l3->val;
      l3 = l3->next;
    }
    cout <<endl;

}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode * result = NULL;
  ListNode * p1 = l1, *p2 = l2, *q = NULL;

  int sum = 0, carry = 0;

  while(p1 && p2)
    {
      sum = p1->val + p2->val + carry;
      carry = sum/10;
      sum %= 10;

      if (q)
	{
	  q->next = new ListNode(sum);
	  q = q->next;
	}
      else
	{
	  q = new ListNode(sum);
	  result = q;
	}
      p1 = p1->next;
      p2 = p2->next;
    }

  if (p2)
    p1 = p2;

  while(p1)
    {
      sum = p1->val + carry;
      carry = sum/10;
      sum %= 10;

      q->next = new ListNode(sum);

      q = q->next;
      p1 = p1->next;
    }

  if (carry)
    {
      q->next = new ListNode(carry);
    }

  return result;
}
