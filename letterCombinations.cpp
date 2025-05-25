/*    Classic Keypad Letter Combinations Generator Markdown
Given a string containing digits from 2 to 9 inclusive, return all possible letter combinations that the number could represent based on the mapping of digits to letters on a phone keypad.
The mapping is as follows:
Copy code
2 -> "abc"
3 -> "def"
4 -> "ghi"
5 -> "jkl"
6 -> "mno"
7 -> "pqrs"
8 -> "tuv"
9 -> "wxyz"
Return all possible letter combinations in any order.
Input Format:
A single line containing a string digits consisting of digits 2 through 9.
Output Format:
Print all possible letter combinations separated by space on a single line.

Example 1:
Input:
23
Output:
ad ae af bd be bf cd ce cf
Example 2:
Input:
9
Output:
w x y z
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    if (digits.empty())
      return {};

    vector<string> keypad = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

    vector<string> res;
    res.push_back("");

    for (int i = 0; i < digits.size(); i++)
    {
      vector<string> temp;
      int digit = digits[i] - '0';
      string letters = keypad[digit];

      for (int j = 0; j < res.size(); j++)
      {
        for (int k = 0; k < letters.size(); k++)
        {
          temp.push_back(res[j] + letters[k]);
        }
      }
      res = temp;
    }
    return res;
  }
};

int main()
{
  Solution sol;
  string input;
  cout << "Enter digits (2-9): " << endl;
  cin >> input;

  vector<string> comb = sol.letterCombinations(input);
  cout << "Possible combinations: " << endl;
  for (int i = 0; i < comb.size(); i++)
  {
    cout << comb[i] << " ";
  }
  cout << endl;
}