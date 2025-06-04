/*    Remove Outermost Parentheses
A valid parentheses string is a non-empty string that is well-formed and balanced, consisting only of '(' and ')'. A primitive valid parentheses string is a non-empty valid string that cannot be divided into two smaller non-empty valid parentheses strings.
Your task is to remove the outermost parentheses from each primitive valid substring in the input string.
Write a function:
string removeOutermostParentheses(string s);
That takes a valid parentheses string s and returns the string after removing the outermost parentheses of every primitive substring.

Example :
Input:
(()())(())()
Output:
()()()
Explanation:
(()()) → remove outermost ( and ) → ()()
(()) → remove outermost ( and ) → ()
() → remove outermost → empty
So the final output is: ()()()

*/

#include <iostream>
#include <string>
using namespace std;

string removeOutermostParentheses(string s)
{
  string res;
  int openCnt = 0;

  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];

    if (c == '(')
    {
      if (openCnt > 0)
      {
        res += c;
      }
      openCnt++;
    }
    else
    {
      openCnt--;
      if (openCnt > 0)
      {
        res += c;
      }
    }
  }
  return res;
}

int main()
{
  string s;
  cout << "Enter a valid parentheses string: " << endl;
  cin >> s;

  string rem = removeOutermostParentheses(s);

  cout << "After removing outermost parentheses: " << rem << endl;
  return 0;
}