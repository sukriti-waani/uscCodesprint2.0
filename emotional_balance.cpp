/* Emotional Balance in a String 
"Given a string, check if all characters appear the same number of times."
If yes, print:    Aashriya smiles: Emotional balance found.
If no, print:     Aashriya wonders: These thoughts were scattered

Example 1:
Input: aabbcc
All letters appear 2 times.
Output: Aashriya smiles: Emotional balance found.

Example 2:
Input: aabbbc
Frequencies: a→2, b→3, c→1
Output:  Aashriya wonders: These thoughts were scattered
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isEmotionallyBalanced(string &s)
{
  unordered_map<char, int> freq;

  for (int i = 0; i < s.length(); i++)
  {
    freq[s[i]]++;
  }

  int targetFreq = -1;
  for (auto it = freq.begin(); it != freq.end(); it++)
  {
    if (targetFreq == -1)
    {
      targetFreq = it->second;
    }
    else if (it->second != targetFreq)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  string s;
  cout << "Enter the character: " << endl;
  cin >> s;

  if (isEmotionallyBalanced(s))
  {
    cout << "Aashriya smiles: Emotional balance found." << endl;
  }
  else
  {
    cout << "Aashriya wonders: These thoughts were scattered" << endl;
  }
  return 0;
}