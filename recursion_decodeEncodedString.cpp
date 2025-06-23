/*              Decode a Nested Encoded String
You are given an encoded string s. The encoding rule is:
k[encoded_string]
where the encoded_string inside square brackets is repeated exactly k times.
The k is a positive integer (can be multiple digits).
The encoding patterns can be nested.
Your task is to write a function that decodes the string and returns the expanded string.

Input
A single encoded string s containing digits 0-9, lowercase English letters a-z, and square brackets [ and ].
It is guaranteed that s is a valid encoding (well-formed brackets, valid format).
Output
The decoded string after expanding all encoded patterns.

Example 1
Input:
3[a]2[bc]
Output:
aaabcbc
Explanation:
3[a] → aaa, 2[bc] → bcbc. Combine → aaabcbc.
*/

#include <iostream>
#include <string>
using namespace std;

string helper(string &s, int &i)
{
  string res = "";
  int n = s.size();

  while (i < n && s[i] != ']')
  {
    if (isdigit(s[i]))
    {
      int num = 0;

      while (i < n && isdigit(s[i]))
      {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      i++;

      string decoded = helper(s, i);

      for (int j = 0; j < num; j++)
      {
        res += decoded;
      }
      i++;
    }
    else
    {
      res += s[i];
      i++;
    }
  }
  return res;
}

string decode(string &s)
{
  int i = 0;
  return helper(s, i);
}

int main()
{
  string s;

  cout << "Enter the encoded message: ";
  getline(cin, s);

  string res = decode(s);

  cout << "Decoded Message: " << res << endl;

  return 0;
}