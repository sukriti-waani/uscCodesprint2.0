/*    Zig-Zag Appointment Reordering
You are given a singly linked list containing n integers. Your task is to reorder the list in a zigzag fashion, such that:
The 1st element is followed by the last element,
Then the 2nd element is followed by the second-last element,
Then the 3rd element (if exists), and so on.
This process continues until all nodes are rearranged in the following pattern:

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
✨ Example:
Input:
Number of nodes: 5
Values: 1 2 3 4 5
Original List: 1 → 2 → 3 → 4 → 5
Zigzag Reordered List: 1 → 5 → 2 → 4 → 3
*/

#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(NULL) {}
};

void append(Node*& head, int val) {
  Node* newNode = new Node(val);
  if(!head) {
    head = newNode;
    return;
  }
  Node* temp = head;
  while(temp->next) {
    temp = temp->next;
  }
  temp->next = newNode;
}

Node* reverseList(Node* head) {
  Node* prev = NULL;
  Node* curr = head;

  while(curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

Node* findMiddle(Node* head) {
  Node* slow = head;
  Node* fast = head;

  while(fast && fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

void zigZagReorder(Node*& head) {
  if(!head || !head->next) return;

  Node* mid = findMiddle(head);

  Node* second = reverseList(mid->next);
  mid->next = NULL;

  Node* first = head;
  while(second) {
    Node* temp1 = first->next;
    Node* temp2 = second->next;

    first->next = second;
    second->next = temp1;

    first = temp1;
    second = temp2;
  }
}

void printList(Node* head) {
  Node* temp = head;
  while(temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node* head = NULL;
  int n;
  cout << "Enter number of nodes: " << endl;
  cin >> n;

  cout << "Enter node values: " << endl;
  for(int i = 0; i < n; i++) {
    int val;
    cin >> val;
    append(head, val);
  }
  zigZagReorder(head);
  cout << "Zigzag reordered list: " << endl;
  printList(head);

  return 0;
}