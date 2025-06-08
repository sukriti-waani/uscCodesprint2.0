/*    Reverse a Queue
Given a queue of integers, your task is to reverse the queue using a stack.
Input Format:
First line contains an integer n (1 ≤ n ≤ 10⁵) — the number of elements in the queue.
Second line contains n space-separated integers — the elements of the queue in the order they were added (front to rear).
Output Format:
Output the elements of the reversed queue (front to rear), space-separated.
Example:
Input:
5
10 20 30 40 50
Output:
50 40 30 20 10
Explanation:
The original queue is: front → 10 20 30 40 50 → rear
After reversal: front → 50 40 30 20 10 → rear

Constraints:
Use only standard library containers (queue and stack).
Must use a stack to reverse the queue (no recursion).

*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
  stack<int> s;

  while (!q.empty())
  {
    s.push(q.front());
    q.pop();
  }

  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
  }
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  queue<int> q;
  cout << "Enter elements: " << endl;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    q.push(val);
  }

  reverseQueue(q);

  cout << "Reversed queue: ";
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}