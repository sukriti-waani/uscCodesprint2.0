/*    Anagram Detection in Log Stream
Given a string logStream and a string pattern, find all starting indices in logStream where the substring is an anagram of the pattern.
Input:
The first line contains the string logStream.
The second line contains the string pattern.
Both strings consist of lowercase English letters only.
Output:
Print all starting indices where an anagram of pattern occurs in logStream.
Indices should be printed in ascending order.
Separate the indices with commas and spaces (, ).
If no anagram is found, print nothing.
Constraints:
1 ≤ length of pattern ≤ length of logStream ≤ 10^5

Example:
Input:
cbaebabacd
abc
Output:
0, 6
Explanation:
The substrings "cba" at index 0 and "bac" at index 6 are anagrams of "abc".


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string a, string b)
{
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  return a == b;
}

vector<int> findAnagrams(string logStream, string pattern)
{
  vector<int> ans;
  int n = logStream.length();
  int m = pattern.length();

  for (int i = 0; i <= n - m; i++)
  {
    string sub = logStream.substr(i, m);
    if (isAnagram(sub, pattern))
    {
      ans.push_back(i);
    }
  }
  return ans;
}

int main()
{
  string logStream, pattern;
  cout << "Enter logStream: " << endl;
  cin >> logStream;
  cout << "Enter pattern: " << endl;
  cin >> pattern;

  vector<int> ans = findAnagrams(logStream, pattern);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
    if (i != ans.size() - 1)
      cout << ", ";
  }
  return 0;
}