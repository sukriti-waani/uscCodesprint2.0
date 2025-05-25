/*    Sorted Linked List Duplication
You are given a sorted singly linked list containing integer elements. Your task is to remove all duplicate elements from the list so that each element appears only once.
Maintain the original order of elements and output the updated linked list without any extra trailing symbols (like arrows).
Input Format
First line: An integer n (1 ≤ n ≤ 1000) — the number of nodes in the linked list.
Second line: n space-separated integers — the elements of the sorted linked list.
Output Format
First line: Print the original linked list (with "->" between elements, no arrow at the end).
Second line: Print the updated list after removing duplicates (same format).

Example Input
7
1 1 2 3 3 4 4
Example Output
Original list:
1 -> 1 -> 2 -> 3 -> 3 -> 4 -> 4
List after removing duplicates:
1 -> 2 -> 3 -> 4
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

Node *removeDuplicates(Node *head)
{
  Node *curr = head;

  while (curr != NULL && curr->next != NULL)
  {
    if (curr->data == curr->next->data)
    {
      Node *temp = curr->next;
      curr->next = temp->next;
      delete temp;
    }
    else
    {
      curr = curr->next;
    }
  }
  return head;
}

void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data;
    if (temp->next != NULL)
      cout << " -> ";
    temp = temp->next;
  }
  cout << "\n";
}

int main()
{
  int n;
  cout << "Enter the number of elements in the sorted linked list: " << endl;
  cin >> n;

  if (n <= 0)
  {
    cout << "Empty list. \n";
    return 0;
  }

  cout << "Enter sorted elements: \n";
  int data;
  cin >> data;
  Node *head = new Node(data);
  Node *tail = head;

  for (int i = 1; i < n; i++)
  {
    cin >> data;
    tail->next = new Node(data);
    tail = tail->next;
  }

  cout << "Original list: " << endl;
  printList(head);

  head = removeDuplicates(head);

  cout << "List after removing duplicates: " << endl;
  printList(head);

  return 0;
}
