/*    Sort Doubly Linked List 
Sort a Doubly Linked List 
You are given a list of integers. Your task is to:
Create a doubly linked list using these integers.
Sort the list in ascending order using the insertion sort algorithm (by rearranging node pointers, not swapping values).
Print the sorted doubly linked list in the format val1 -> val2 -> val3 -> ....

Example Input:
Enter the number of nodes: 
6
Enter the nodes: 
4 2 9 1 5 3
Expected Output:
1 -> 2 -> 3 -> 4 -> 5 -> 9
🔍 Explanation:
The original list created is:
4 <-> 2 <-> 9 <-> 1 <-> 5 <-> 3
After sorting using insertion sort, the list becomes:
1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 9
*/

#include<iostream>
using namespace std;

struct Node {
  int val;
  Node* prev;
  Node* next;
  Node(int x) : val(x) , prev(NULL), next(NULL) {}
};

Node* createNode(int val) {
  return new Node(val);
}

Node* append(Node* head, int val) {
  if(!head){
    head = createNode(val);
    return head;
  }
  
  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }

  Node* newNode = createNode(val);
  temp->next = newNode;
  newNode->prev = temp;
  return head;
}

void sortDoublyll(Node*& head) {
  if(!head || !head->next) return;

  Node* curr = head->next;
  while(curr != NULL) {
    Node* nxt = curr->next;
    Node* p = curr->prev;

    p->next = curr->next;
    if(curr->next)  
      curr->next->prev = p;

    while(p && p->val > curr->val) 
      p = p->prev;

        if(!p) {
          curr->next = head;
          head->prev = curr;
          curr->prev = NULL;
          head = curr;
        }
        else {
          curr->next = p->next;
          if(p->next) {
            p->next->prev = curr;
          }
          p->next = curr;
          curr->prev = p;
        }
        curr = nxt;
  }
}

void print(Node* head) {
  while(head) {
    cout << head->val;
    if(head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  int n, x;
  cout << "Enter the number of nodes: " << endl;
  cin >> n;
  Node* head = NULL;

  cout << "Enter the nodes: " << endl;
  for(int i = 0; i < n; i++) {
    cin >> x;
    head = append(head, x);
  }
  sortDoublyll(head);
  print(head);

  return 0;
}