/*     Double a Number Represented by a Linked List
Problem Statement:
You are given a non-negative integer represented as a singly linked list, where each node contains a single digit. The most significant digit comes first (i.e., the head of the list). Your task is to write a program that doubles the number and returns the result as a new linked list in the same format.

Input:
First, an integer n representing the number of digits in the number.
Then, n space-separated digits, each representing a digit of the number in left-to-right order.
Constraints:
1 <= n <= 1000
Each digit is between 0 and 9.
Output:
A linked list representing the doubled number, printed without spaces between digits.

Example:
Input:
Enter the number of elements:
3
Enter elements:
1 2 3
Output:
Doubled number:
246
Explanation:
The number 123 is represented as a linked list: 1 -> 2 -> 3.
Doubling 123 gives 246, so the output linked list is 2 -> 4 -> 6.
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

Node *reverseList(Node *head)
{
  Node *prev = NULL;
  Node *curr = head;

  while (curr)
  {
    Node *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  return prev;
}

Node *doubleNumber(Node *head)
{
  head = reverseList(head);
  Node *curr = head;
  int carry = 0;

  while (curr)
  {
    int sum = curr->data * 2 + carry;
    curr->data = sum % 10;
    carry = sum / 10;

    if (curr->next == NULL && carry > 0)
    {
      curr->next = new Node(carry);
      carry = 0;
    }
    curr = curr->next;
  }
  return reverseList(head);
}

void print(Node *head)
{
  while (head)
  {
    cout << head->data << "  ";
    head = head->next;
  }
  cout << endl;
}

Node *createList(int n)
{
  if (n <= 0)
    return NULL;

  int val;
  cout << "Enter elements: " << endl;
  cin >> val;
  Node *head = new Node(val);
  Node *tail = head;

  for (int i = 1; i < n; i++)
  {
    cin >> val;
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
  }
  return head;
}

int main()
{
  int n;
  cout << "Enter the number of elements: " << endl;
  cin >> n;

  Node *head = createList(n);

  head = doubleNumber(head);

  cout << "Doubled number: " << endl;
  print(head);

  return 0;
}