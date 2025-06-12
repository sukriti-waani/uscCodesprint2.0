/*      Bag of Tokens
You are given an integer array tokens where tokens[i] represents the power cost of the i-th token, and you are given an initial integer power.
Your goal is to maximize your total score by playing the tokens in the following way:
If your current power is at least tokens[i], you may spend tokens[i] power to gain +1 score.
If you have at least 1 score, you may sacrifice -1 score to regain tokens[i] power.
You can play each token at most once in any order.
Return the maximum score you can achieve.

Input:
An integer n representing the number of tokens.
An array tokens of size n, where 1 ≤ tokens[i] ≤ 10000.
An integer power, where 0 ≤ power ≤ 10000.
Output:
Return a single integer representing the maximum score achievable.
Constraints:
You can play any token at most once.
You may decide which tokens to play or skip.
You may flip between spending power or sacrificing score as many times as you like.

Example
Input:
Enter the number of tokens: 4
Enter the token values: 100 200 300 400
Enter the power: 200
Output:
Maximum Score: 2
Explanation:
Play token 100 (power 200 -> 100, score 0 -> 1)
Play token 200 (power 100 -> -100 invalid, so skip)
Use score -1 to gain power from token 400 (power 100 + 400 = 500, score 1 -> 0)
Play token 200 (power 500 -> 300, score 0 -> 1)
Play token 300 (power 300 -> 0, score 1 -> 2)
Maximum score is 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int> &tokens, int power)
{
  sort(tokens.begin(), tokens.end());
  int score = 0, maxScore = 0;
  int currPower = power;
  int left = 0, right = tokens.size() - 1;

  while (left <= right)
  {
    if (currPower >= tokens[left])
    {
      currPower -= tokens[left];
      score++;
      maxScore = max(maxScore, score);
      left++;
    }
    else if (score >= 1 && left < right)
    {
      currPower += tokens[right];
      score--;
      right--;
    }
    else
    {
      break;
    }
  }
  return maxScore;
}

int main()
{
  int n;
  cout << "Enter the number of tokens: ";
  cin >> n;

  vector<int> tokens(n);
  cout << "Enter the token values: ";
  for (int i = 0; i < n; i++)
  {
    cin >> tokens[i];
  }

  int power;
  cout << "Enter the power: ";
  cin >> power;

  int res = maxScore(tokens, power);
  cout << "Maximum Score: " << res << endl;

  return 0;
}