/*    Evaluate a postfix (Reverse Polish Notation) expression

Write a program that takes a postfix expression as input — where operands and operators are space-separated — and evaluates it using a stack. The expression may contain positive and negative integers and the operators +, -, *, and /.
Input:
A single line containing a valid postfix expression, tokens separated by spaces.
Tokens are either integers (like 2, -5, 10) or operators (+, -, *, /).
Output:
Print the integer result of the evaluated expression.
Constraints:
Division should be integer division (truncate toward zero).
Assume the input expression is valid and will not cause division by zero.
Result fits in 32-bit integer.

Sample Input 1:
2 1 + 3 *
Sample Output 1:
9
Explanation:
First, add 2 + 1 = 3, then multiply 3 * 3 = 9.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(string &op)
{
  return op == "+" || op == "-" || op == "*" || op == "/";
}

int postfixExpr(string s)
{
  stack<long long> st;
  string token = "";

  for (int i = 0; i <= s.length(); i++)
  {
    if (i == s.length() || s[i] == ' ')
    {
      if (token.empty())
        continue;

      if (isOperator(token))
      {
        long long b = st.top();
        st.pop();
        long long a = st.top();
        st.pop();

        if (token == "+")
          st.push(a + b);
        else if (token == "-")
          st.push(a - b);
        else if (token == "*")
          st.push(a * b);
        else if (token == "/")
          st.push(a / b);
      }
      else
      {
        st.push(stoll(token));
      }
      token = "";
    }
    else
    {
      token += s[i];
    }
  }
  return st.top();
}

int main()
{
  string s;
  cout << "Enter expression: " << endl;
  getline(cin, s);

  int ans = postfixExpr(s);
  cout << ans << endl;

  return 0;
}