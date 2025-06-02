/*    Check if the brackets in a string are balanced

Write a program that takes a string containing only the characters '(', ')', '{', '}', '[', and ']'. Your task is to determine if the input string has valid and balanced brackets.
Every opening bracket must be closed by the same type of bracket.
Opening brackets must be closed in the correct order.
Input:
A single line containing a string consisting only of '(', ')', '{', '}', '[', and ']'.
Output:
Print true if the brackets are balanced and valid, otherwise print false.
Constraints:
The length of the string can be from 0 up to 10^4.

Sample Input 1:
()[]{}
Sample Output 1:
true

Sample Input 2:
([)]
Sample Output 2:
false
*/

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string &s)
{
  stack<char> st;

  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];

    if (c == '(' || c == '{' || c == '[')
    {
      st.push(c);
    }
    else if (c == ')' || c == '}' || c == ']')
    {
      if (st.empty())
        return false;

      char top = st.top();
      st.pop();

      if ((c == ')' && top != '(') ||
          (c == '}' && top != '{') ||
          (c == ']' && top != '['))
      {
        return false;
      }
    }
  }
  return st.empty();
}

int main()
{
  string s;
  cout << "Enter brackets string: " << endl;
  cin >> s;

  if (isValid(s))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}