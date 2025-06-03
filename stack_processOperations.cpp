/*    Implement a Stack with Minimum Element Retrieval
You need to implement a stack that supports the following operations:
PUSH x: Push the integer x onto the stack.
POP: Remove the top element from the stack. If the stack is empty, do nothing.
MIN: Print the minimum element currently in the stack. If the stack is empty, print "Empty".

Input Format
The first line contains an integer n — the number of operations.
The next n lines contain one of the following operations:
PUSH x (where x is a 64-bit integer)
POP
MIN

Output Format
For every MIN operation, print the minimum element of the stack at that moment.
If the stack is empty during a MIN operation, print "Empty".

Example
Input:
8
PUSH 10
PUSH 5
MIN
POP
MIN
POP
MIN
POP
Output:
5
10

Explanation
After PUSH 10, stack is: [10] — min is 10
After PUSH 5, stack is: [10, 5] — min is 5
MIN: print 5
POP: removes 5, stack is now [10]
MIN: print 10
POP: removes 10, stack is now empty
MIN: stack empty, print Empty
POP: stack empty, do nothing
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void pushEle(stack<long long> &s, stack<long long> &minStack, long long x)
{
  s.push(x);
  if (minStack.empty() || x <= minStack.top())
  {
    minStack.push(x);
  }
  else
  {
    minStack.push(minStack.top());
  }
}

void popEle(stack<long long> &s, stack<long long> &minStack)
{
  if (!s.empty())
  {
    s.pop();
    minStack.pop();
  }
}

string getMin(stack<long long> &minStack)
{
  if (minStack.empty())
  {
    return "Empty";
  }
  else
  {
    return to_string(minStack.top());
  }
}

void processOp(int n)
{
  stack<long long> s;
  stack<long long> minStack;
  vector<string> res;

  cout << "Enter operations: " << endl;
  for (int i = 0; i < n; i++)
  {
    string op;
    cin >> op;

    if (op == "PUSH")
    {
      long long x;
      cout << "Enter element x: \n";
      cin >> x;
      pushEle(s, minStack, x);
    }
    else if (op == "POP")
    {
      popEle(s, minStack);
    }
    else if (op == "MIN")
    {
      res.push_back(getMin(minStack));
    }
  }

  for (string &results : res)
  {
    cout << results << endl;
  }
}

int main()
{
  int n;
  cout << "Enter number of operations: " << endl;
  cin >> n;

  cout << "Enter operations(PUSH x / POP / MIN): \n ";
  processOp(n);

  return 0;
}