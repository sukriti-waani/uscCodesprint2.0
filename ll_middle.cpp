/*      Find the Middle of a Linked List and Print From There
You are given a singly linked list containing n integer elements. Your task is to:
Construct the linked list from user input.
Find the middle node of the linked list.
If the number of nodes is odd, return the exact middle.
If the number of nodes is even, return the second middle (i.e., the later of the two middle nodes).
Print the list starting from the middle node to the end.

Input Format:
First line: an integer n representing the number of elements in the list.
Next line: n integers representing the values of the list.
Output Format:
A line printing the values starting from the middle node to the end of the list, separated by commas.

Example 1:
Input:
5
1 2 3 4 5
Output:
3 , 4 , 5
Explanation:
The list is: 1 → 2 → 3 → 4 → 5
Middle element (odd-length): 3
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

Node *createList(int n)
{
  if (n <= 0)
    return NULL;

  int val;
  cout << "Enter values: " << endl;
  cin >> val;

  Node *head = new Node(val);
  Node *tail = head;

  for (int i = 2; i <= n; i++)
  {
    cin >> val;
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
  }
  return head;
}

Node *findMiddle(Node *head)
{
  Node *slow = head, *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

void print(Node *head)
{
  while (head)
  {
    cout << head->val;
    if (head->next)
      cout << " , ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter the number of elements: " << endl;
  cin >> n;

  Node *head = createList(n);
  Node *mid = findMiddle(head);

  cout << "List from middle to end: " << endl;
  print(mid);

  return 0;
}