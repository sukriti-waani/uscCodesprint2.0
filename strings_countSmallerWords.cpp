/*          Count Lexicographically Smaller Words Before Each Word
Problem Statement:
You are given a list of N words (strings).
For each word (from left to right), you need to calculate how many words before it are lexicographically smaller than the current word.

In simple words:
For each word, print how many previous words (that appeared earlier in the input) are lexicographically smaller than it.

Input Format:
The first line contains an integer N — the total number of words.
The second line contains N space-separated words.
Output Format:
Print N lines.
The i-th line contains the count of words that are lexicographically smaller than the i-th word and have appeared before it.
Constraints:
1 ≤ N ≤ 10^5
Each word consists of lowercase English letters.
The length of each word is up to 20 characters.

Example Input:
5
apple banana apple cherry banana
Example Output:
0
1
0
3
1
Explanation:
We process the words one by one:
"apple" → No previous words → Output 0
"banana" → Only "apple" is before it and "apple" < "banana" → Output 1
"apple" → No previous word smaller than "apple" → Output 0
"cherry" → "apple", "banana", "apple" before it, and all three are smaller than "cherry" → Output 3
"banana" → "apple", "banana", "apple", "cherry" before it → Only "apple" is smaller → Output 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXN = 100005;
int BIT[MAXN];

void update(int idx, int val, int size)
{
  while (idx <= size)
  {
    BIT[idx] += val;
    idx += idx & -idx;
  }
}

int query(int idx)
{
  int sum = 0;
  while (idx > 0)
  {
    sum += BIT[idx];
    idx -= idx & -idx;
  }
  return sum;
}

int main()
{
  int n;
  cout << "Enter number: ";
  cin >> n;

  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }

  vector<string> w = words;
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());

  unordered_map<string, int> wordIdx;
  for (int i = 0; i < w.size(); i++)
  {
    wordIdx[w[i]] = i + 1;
  }

  int size = w.size();

  for (int i = 0; i < n; i++)
  {
    int idx = wordIdx[words[i]];
    int niceness = query(idx - 1);
    cout << niceness << "\n";
    update(idx, 1, size);
  }
  return 0;
}