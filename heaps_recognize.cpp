/*      Reorganize String (Heap Based)
You are given a string s. Your task is to rearrange the characters of the string so that no two adjacent characters are the same.
If it is possible to rearrange the string, return any one possible valid rearrangement.
If not possible, return an empty string.
You must use Heap (Priority Queue) to solve this problem.

Input:
A string s consisting of only lowercase or uppercase English letters.
1 <= s.length <= 10^5
Output:
A rearranged string such that no two adjacent characters are the same.
If it's not possible, return an empty string.
Constraints:
The rearranged string length must be exactly same as input length.
Characters are case sensitive (A and a are different).

Example 1:
Input:
aaabbc
Output:
ababac
Explanation:
One possible rearrangement is ababac.
No two same characters are adjacent.

Example 2:
Input:
aaab
Output:
""
Explanation:
No valid rearrangement is possible because character 'a' appears too many times.
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string recognize(string &s)
{
  unordered_map<char, int> freq;

  for (int i = 0; i < s.size(); i++)
  {
    char ch = s[i];
    if (freq.find(ch) != freq.end())
    {
      freq[ch]++;
    }
    else
    {
      freq[ch] = 1;
    }
  }

  priority_queue<pair<int, char>> maxHeap;

  for (auto it = freq.begin(); it != freq.end(); it++)
  {
    int count = it->second;
    char ch = it->first;
    maxHeap.push(make_pair(count, ch));
  }

  string res = "";

  pair<int, char> prev;
  prev.first = 0;
  prev.second = '#';

  while (!maxHeap.empty())
  {
    pair<int, char> curr = maxHeap.top();
    maxHeap.pop();

    int count = curr.first;
    char ch = curr.second;

    res += ch;
    count--;

    if (prev.first > 0)
    {
      maxHeap.push(prev);
    }
    prev.first = count;
    prev.second = ch;
  }

  if (res.length() != s.length())
  {
    return "";
  }
  return res;
}

int main()
{
  string s;
  cout << "Enter string: ";
  cin >> s;
  string res = recognize(s);
  if (res == "")
  {
    cout << "Not possible to recognize" << endl;
  }
  else
  {
    cout << res << endl;
  }
  return 0;
}