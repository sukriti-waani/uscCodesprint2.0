/*                Find the k-th Character in a Special Doubling String
You are given an integer k.
Consider a string-building process that starts with:
s = "a"
At each step, the string doubles in size by appending a transformed copy:
s = s + transform(s)
where transform(s) means each character of s is replaced by its next character in the English alphabet (with 'z' wrapping around to 'a').

For example:
Step 0: s = a
Step 1: s = a + b = ab
Step 2: s = ab + bc = abbc
Step 3: s = abbc + bccd = abbcbccd
... and so on.
Your task is to find the character at position k (1-based index) in this infinite process, without generating the entire string.

Input
An integer k (1 ≤ k ≤ 10^9) — the position of the character you want to find.
Output
Output the character at the k-th position.

Example
5
Output:
b
💡 Explanation
The string grows as:
Step 0: s = a               → length 1
Step 1: s = ab              → length 2
Step 2: s = abbc            → length 4
Step 3: s = abbcbccd        → length 8
...
The 5th character corresponds to the 1st character of the transformed part of the length-4 string, so it is 'b'.
*/

#include <iostream>
using namespace std;

char getChar(int k)
{
  char res = 'a';

  while (k > 1)
  {
    int len = 1;

    while (2 * len < k)
    {
      len *= 2;
    }

    if (k > len)
    {
      k -= len;

      res = (res == 'z') ? 'a' : res + 1;
    }
  }

  return res;
}

int main()
{
  int k;
  cout << "Enter the position : ";
  cin >> k;

  cout << getChar(k) << endl;
  return 0;
}