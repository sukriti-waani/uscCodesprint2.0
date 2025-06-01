/*    Convert Postfix to Prefix Expression
Problem Statement:
Write a program to convert a postfix expression (also known as Reverse Polish Notation) into a prefix expression (Polish Notation). A postfix expression is a mathematical notation in which every operator follows all of its operands. In contrast, a prefix expression places the operator before the operands.
You must use a stack to perform the conversion.

Input:
A string containing a valid postfix expression with single-character operands and operators +, -, *, /.
Output:
A string representing the equivalent prefix expression.
Constraints:
Expression length: 1 to 100 characters
Operands are single alphabetic characters (e.g., A, B, C)
No spaces in the expression
The postfix expression is always valid

Example 1
Input:
AB+
Output:
+AB
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

string postfixToPrefix(string &postfix)
{
  stack<string> s;

  for (int i = 0; i < postfix.length(); i++)
  {
    char c = postfix[i];

    if (isOperator(c))
    {
      string op2 = s.top();
      s.pop();
      string op1 = s.top();
      s.pop();

      string expr = c + op1 + op2;
      s.push(expr);
    }
    else
    {
      s.push(string(1, c));
    }
  }
  return s.top();
}

int main()
{
  string postfixExpr;
  cout << "Enter a postfix expression: " << endl;
  cin >> postfixExpr;

  string prefixExpr = postfixToPrefix(postfixExpr);
  cout << "Prefix Expression: " << prefixExpr << endl;

  return 0;
}