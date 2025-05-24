/*    Pattern Match Detection using Hashing
Find all occurrences of a pattern string in a given text string using polynomial rolling hash.
You are given two strings, text and pattern. Your task is to find all starting indices in text where the substring equals pattern.
Input Format:
First line contains a string text.
Second line contains a string pattern.
Output Format:
Print all the zero-based starting indices where pattern is found in text, separated by spaces.
If no occurrence is found, print nothing.
Constraints:
1 ≤ length of pattern ≤ length of text ≤ 10^6
Strings consist of lowercase English letters only (a to z).

Sample Input 1:
thissearchworkisunique
search
Sample Output 1:
4
Explanation:
The substring "search" starts at index 4 in the text "thissearchworkisunique".

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const ll BASE = 31;
const ll MOD = 1e9 + 9;

vector<int> func(string &text, string &pattern)
{
  int n = text.size(), m = pattern.size();

  if (m > n)
    return {};

  vector<ll> powers(m);
  powers[0] = 1;
  for (int i = 1; i < m; i++)
  {
    powers[i] = (powers[i - 1] * BASE) % MOD;
  }
  ll patternHash = 0;
  for (int i = 0; i < m; i++)
  {
    patternHash = (patternHash + (pattern[i] - 'a' + 1) * powers[m - 1 - i]) % MOD;
  }
  ll textHash = 0;
  for (int i = 0; i < m; i++)
  {
    textHash = (textHash + (text[i] - 'a' + 1) * powers[m - 1 - i]) % MOD;
  }

  vector<int> res;
  if (textHash == patternHash && text.substr(0, m) == pattern)
  {
    res.push_back(0);
  }

  for (int i = 1; i <= n - m; i++)
  {
    textHash = (textHash - (text[i - 1] - 'a' + 1) * powers[m - 1] % MOD + MOD) % MOD;
    textHash = (textHash * BASE) % MOD;
    textHash = (textHash + (text[i + m - 1] - 'a' + 1)) % MOD;

    if (textHash == patternHash && text.substr(i, m) == pattern)
    {
      res.push_back(i);
    }
  }
  return res;
}

int main()
{
  string text, pattern;
  cout << "Enter the text and pattern: " << endl;
  cin >> text >> pattern;

  vector<int> matches = func(text, pattern);

  for (int idx : matches)
  {
    cout << idx << " ";
  }
  return 0;
}