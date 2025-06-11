/*      Relative Ranks
You are given an array of integers score where score[i] represents the score of the i-th participant in a competition.
You need to assign ranks to all participants:
The participant with the highest score gets "Gold Medal".
The participant with the second highest score gets "Silver Medal".
The participant with the third highest score gets "Bronze Medal".
For all remaining participants, assign their numerical rank (starting from "4" for the fourth place, "5" for the fifth place, and so on).
Return a list of strings where the i-th string represents the rank of the i-th participant according to their score.

Example
Input:
Enter number of participants: 5
Enter scores:
45 89 12 67 23
Output:
Relative Ranks:
3 Gold Medal 5 Silver Medal 4
Explanation:
Highest score is 89 → Gold Medal.
Second highest is 67 → Silver Medal.
Third highest is 45 → Bronze Medal.
Others get rank numbers "4", "5" based on their position after sorting.
Constraints:
1 <= score.length <= 10^4
0 <= score[i] <= 10^6
All scores are unique.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> ranks(vector<int> &score)
{
  int n = score.size();

  sort(score.begin(), score.end(), greater<int>());
  unordered_map<int, string> mp;

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      mp[score[i]] = "Gold Medal ";
    }
    else if (i == 1)
    {
      mp[score[i]] = "Silver Medal ";
    }
    else if (i == 2)
    {
      mp[score[i]] = "Bronze Medal ";
    }
    else
    {
      mp[score[i]] = to_string(i + 1);
    }
  }

  vector<string> res(n);
  for (int i = 0; i < n; i++)
  {
    res[i] = mp[score[i]];
  }

  return res;
}

int main()
{
  int n;
  cout << "Enter number of participants: ";
  cin >> n;

  vector<int> score(n);

  cout << "Enter scores: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> score[i];
  }

  vector<string> res = ranks(score);

  cout << "Relative Ranks: \n";
  for (auto &rank : res)
  {
    cout << rank << " ";
  }
  cout << endl;
  return 0;
}