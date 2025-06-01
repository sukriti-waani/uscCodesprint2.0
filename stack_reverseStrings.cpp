/*    Reverse a String Using Stack
Write a C++ program to reverse a string using the Stack data structure.
You must read a full line of text (which may include spaces).
Then, push each character of the string onto a stack.
Finally, pop characters from the stack to form and print the reversed string.
Input Format:
A single line of input containing any string, possibly including spaces.
Output Format:
A single line containing the reversed string.
Constraints:
The string length will be between 1 and 1000 characters.
The string may contain uppercase and lowercase English letters, digits, punctuation, and spaces.

Sample Input:
Hello Stack
Sample Output:
kcatS olleH
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  string s;
  cout << "Enter a string: " << endl;
  getline(cin, s);

  stack<char> stack;

  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];
    stack.push(c);
  }

  string reversed;
  int pos = 0;
  while (!stack.empty())
  {
    char tchar = stack.top();
    reversed += tchar;
    stack.pop();
    pos++;
  }

  cout << "Reversed string is : " << reversed << endl;
  return 0;
}