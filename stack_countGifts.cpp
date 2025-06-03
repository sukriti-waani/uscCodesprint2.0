/*    Stack Gift Tracker
Problem Statement:
You are managing a stack of gifts using the following operations:
PUSH <gift> – Push a gift onto the stack.
POP – Remove the top gift from the stack.
COUNT – Output how many times the top gift currently exists on the stack.
You are given n operations. Implement the operations and output the correct result for each COUNT.
Explanation of Operations:
PUSH <gift>: Add the gift on top of the stack. Keep a count of how many times each gift is currently in the stack.
POP: Remove the topmost gift from the stack. Update its count.
COUNT: Print how many times the current top gift appears in the stack.
If the stack is empty, print Empty.

Example Input:
Enter number of operations: 8
PUSH
Doll
PUSH
Doll
PUSH
Car
COUNT
POP
COUNT

Explanation:
Stack: Doll
Stack: Doll, Doll
Stack: Doll, Doll, Car
Top is Car → Count of Car is 1
POP → Remove Car
Stack: Doll, Doll
Top is Doll → Count of Doll is 2

✅ Expected Output:
Enter (PUSH / POP / COUNT):
Enter gift name: Enter gift name: Enter gift name:
1
2
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

void push(stack<string> &s, unordered_map<string, int> &mp, unordered_map<string, int> &topCntMp, string &gift)
{
  s.push(gift);
  mp[gift]++;
  topCntMp[gift]++;
}

void pop(stack<string> &s, unordered_map<string, int> &topCntMp)
{
  if (!s.empty())
  {
    string topGift = s.top();
    s.pop();
    topCntMp[topGift]--;
    if (topCntMp[topGift] == 0)
    {
      topCntMp.erase(topGift);
    }
  }
}

void countTop(stack<string> &s, unordered_map<string, int> &topCntMp)
{
  if (s.empty())
  {
    cout << "Empty \n";
  }
  else
  {
    string topGift = s.top();
    cout << topCntMp[topGift] << endl;
  }
}

void process(int n)
{
  stack<string> s;
  unordered_map<string, int> freqMp;
  unordered_map<string, int> topCntMp;

  cout << "Enter (PUSH / POP / COUNT): \n";
  for (int i = 0; i < n; i++)
  {
    string x;
    cin >> x;

    if (x == "PUSH")
    {
      string val;
      cout << "Enter gift name: ";
      cin >> val;
      push(s, freqMp, topCntMp, val);
    }
    else if (x == "POP")
    {
      pop(s, topCntMp);
    }
    else if (x == "COUNT")
    {
      countTop(s, topCntMp);
    }
    else
    {
      cout << "INVALID !!";
    }
  }
}

int main()
{
  int n;
  cout << "Enter number of operations: " << endl;
  cin >> n;

  process(n);
  return 0;
}