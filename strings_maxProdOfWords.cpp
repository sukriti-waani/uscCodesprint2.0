/*                    Maximum Product of Word Lengths Without Common Letters
Given a list of strings words[], return the maximum value of length(word[i]) * length(word[j]) where the two words do not share any common letters.
You must write an efficient solution that doesn't explicitly compare characters of each pair.
Your Task:
Write a function:
int maxProd(vector<string> &words);
That returns the maximum product of the lengths of two words that do not share any common letters. Use bit manipulation to optimize comparisons.

Example 1:
Input:
5
abcw
baz
foo
bar
xtfn
Output:
16
Explanation:
"abcw" and "xtfn" do not share any characters.
Product = 4 * 4 = 16 (maximum among all valid pairs).
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getCharMask(string &w)
{
  int mask = 0;
  for (char c : w)
  {
    mask |= 1 << (c - 'a');
  }
  return mask;
}

int maxProd(vector<string> &w)
{
  int n = w.size();
  vector<int> masks(n);
  vector<int> len(n);

  for (int i = 0; i < n; i++)
  {
    masks[i] = getCharMask(w[i]);
    len[i] = w[i].size();
  }

  int maxP = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if ((masks[i] & masks[j]) == 0)
      {
        int prod = len[i] * len[j];
        maxP = max(maxP, prod);
      }
    }
  }
  return maxP;
}

int main()
{
  int n;
  cin >> n;
  vector<string> w(n);

  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }

  cout << maxProd(w) << endl;

  return 0;
}