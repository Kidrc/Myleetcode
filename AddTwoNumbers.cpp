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
  
  cout << l3->val << l3->next->val << l3->next->next->val << endl;
}

ListNode *reverse(ListNode *l, int *len)
{
  *len = 1;
  ListNode *pb = l, *pm = l->next, *pf;

  if (pm)
    {
      pf = pm->next;
      pb->next = NULL;

      while(pm)
	{
	  ++(*len);
	  pm->next = pb;

	  pb = pm;
	  pm = pf;
	  
	  if (pf)
	    pf = pf->next;
	}
	  
      return pb;
    }
  else
    {
      *len = 1;
      return l;
    }
  
  
}  

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int len1 = 0, len2 = 0;
  ListNode *result = NULL;

  l1 = reverse(l1, &len1);
  l2 = reverse(l2, &len2);

  ListNode *p, *q, *r = result;
  int diff;
  if (len1 < len2)
    {
      p = l2;
      q = l1;
      diff = len2-len1;
    }
  else
    {
      p = l1;
      q = l2;
      diff = len1-len2;
    }

  for (int i = 0; i < diff; ++i)
    {
      if (r)
	{
	  r->next = new ListNode(p->val);
	  r = r->next;
	}
      else
	{
	  r = new ListNode(p->val);
	  result = r;
	}
      p = p->next;
    }

  int sum = 0;
  int carry = 0;

    while(p)
    {
      sum = p->val + q->val;
      carry = sum/10;
      sum %= 10;

      if (r)
	{
	  r->next = new ListNode(p->val+q->val);
	  r = r->next;
	}
      else
	{
	  r = new ListNode(p->val+q->val);
	  result = r;
	}
      p = p->next;
      q = q->next;
    }
    return result;
}
