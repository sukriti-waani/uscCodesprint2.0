/*                      Check If Two Strings Are Isomorphic
Given two strings s and t, determine if they are isomorphic.
Two strings are said to be isomorphic if the characters in s can be replaced to get t, with the following rules:
Every character in s must be mapped to a unique character in t.
A character from s cannot map to multiple characters in t.
The mapping must be one-to-one and order-preserving.
Return True if s and t are isomorphic, otherwise return False.

Example 1:
Input:
s = "egg"
t = "add"
Output:
True
Explanation:
e → a and g → d — mapping is consistent and one-to-one.

Example 2:
Input:
s = "foo"
t = "bar"
Output:
False
Explanation:
f → b, o → a, but second o → r breaks the consistency of the mapping.

Example 3:
Input:
s = "paper"
t = "title"
Output:
True
Explanation:
p → t, a → i, p → t, e → l, r → e — all mappings are valid and one-to-one.

Constraints:
1 <= s.length, t.length <= 10^4
s and t consist of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isValid(string &s, string &t)
{
  if (s.length() != t.length())
    return false;

  unordered_map<char, char> st;
  unordered_set<char> mp;

  for (size_t i = 0; i < s.length(); i++)
  {
    char sChar = s[i];
    char tChar = t[i];

    if (st.count(sChar))
    {
      if (st[sChar] != tChar)
      {
        return false;
      }
    }
    else
    {
      if (mp.count(tChar))
      {
        return false;
      }
      st[sChar] = tChar;
      mp.insert(tChar);
    }
  }
  return true;
}

int main()
{
  string s, t;
  getline(cin, s);
  getline(cin, t);

  if (isValid(s, t))
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  return 0;
}