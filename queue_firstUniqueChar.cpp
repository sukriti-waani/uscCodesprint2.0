/*      First Non-Repeating Character in a Stream
Given a stream of lowercase characters (i.e., a string), for each character added to the stream, find the first non-repeating character in the stream so far. If no such character exists, append '#' instead.
You need to return a string where each character represents the first non-repeating character at that point in the stream.
Input:
A single string s of length 1 ≤ s.length() ≤ 10^5, consisting of lowercase English letters.
Output:
Return a string of the same length, where each character is the first non-repeating character in the stream up to that index, or '#' if none exists.
Example 1:
Input:
s = "aabc"
Output:
" a#bb "
Explanation:
Step 1: 'a' → first non-repeating: 'a'
Step 2: 'a' again → no unique character: '#'
Step 3: 'b' → first non-repeating: 'b'
Step 4: 'c' → 'b' still unique → 'b'
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string firstUniqueChar(string &s)
{
  unordered_map<char, int> freq;
  queue<char> q;
  string res;

  for (char ch : s)
  {
    freq[ch]++;
    q.push(ch);

    while (!q.empty() && freq[q.front()] > 1)
    {
      q.pop();
    }

    if (q.empty())
    {
      res += '#';
    }
    else
    {
      res += q.front();
    }
  }
  return res;
}

int main()
{
  string s;
  cout << "Enter the string stream: ";
  cin >> s;

  string ans = firstUniqueChar(s);
  cout << "Result: " << ans << endl;
  return 0;
}