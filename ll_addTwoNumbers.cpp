/*    Add Two Numbers Represented by Linked Lists
You are given two non-empty singly linked lists representing two non-negative integers.
The digits are stored in reverse order, and each node contains a single digit.
Add the two numbers and return the sum as a linked list (also in reverse order).

Note: You must not use arrays or classes. Only singly linked lists (as in the code you provided) should be used.

Input Format:
First line: an integer n1, the number of digits in the first number.
Second line: n1 integers separated by space (digits of the first number in reverse order).
Third line: an integer n2, the number of digits in the second number.
Fourth line: n2 integers separated by space (digits of the second number in reverse order).
Output Format:
Print the resulting sum as a linked list in reverse order, with -> between digits.

Example:
Input:
3
2 4 3
3
5 6 4
Explanation:
First number = 342 (reverse of 2->4->3)
Second number = 465 (reverse of 5->6->4)
Sum = 807 → Reverse = 7->0->8
Output:
7 -> 0 -> 8
*/

#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

Node *insert(Node *head, int val)
{
  Node *newNode = new Node(val);
  if (!head)
    return newNode;

  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

void print(Node *head)
{
  while (head)
  {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
  Node *dummy = new Node(0);
  Node *curr = dummy;
  int carry = 0;

  while (l1 || l2 || carry)
  {
    int sum = carry;
    if (l1)
    {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2)
    {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;
    curr->next = new Node(sum % 10);
    curr = curr->next;
  }
  return dummy->next;
}

int main()
{
  int n1, n2, val;
  Node *l1 = NULL, *l2 = NULL;

  cout << "Enter number of elements in first number: " << endl;
  cin >> n1;
  cout << "Enter elements (in reverse order): " << endl;
  for (int i = 0; i < n1; i++)
  {
    cin >> val;
    l1 = insert(l1, val);
  }
  cout << "Enter number of elements in second number: " << endl;
  cin >> n2;
  cout << "Enter elements (in reverse order): " << endl;
  for (int i = 0; i < n2; i++)
  {
    cin >> val;
    l2 = insert(l2, val);
  }
  Node *sum = addTwoNumbers(l1, l2);
  print(sum);

  return 0;
}