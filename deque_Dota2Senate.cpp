/*      Dota2 Senate Ban Simulation
The Dota2 Senate has two parties: Radiant ('R') and Dire ('D'). A senate string is given, where each character represents a senator from one of the parties. The game happens in rounds. In each round, the senator with the smaller index bans one member of the opposite party from participating in future rounds.
Once a senator bans an opponent, they will rejoin the queue at the end of the line with their index increased by the length of the senate string.
The process continues until only one party remains. Your task is to predict which party will win.

Input Format:
A string s representing the sequence of senators.
Each character of the string is either 'R' (Radiant) or 'D' (Dire).
Output Format:
Output "Radiant" if the Radiant party wins.
Output "Dire" if the Dire party wins.
Constraints:
1 <= s.length <= 10^4
s contains only the characters 'R' and 'D'.

Example 1:
Input:
RDD
Explanation:
Round 1: R bans D → remaining: D
Round 2: D has no opponent, Dire wins.
Output:
Dire

Example 2:
Input:
RRDDD
Explanation:
R bans D
R bans D
D bans R
Remaining: RRD
R bans D → Radiant wins
Output:
Radiant
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string predict(string s)
{
  queue<int> rad, dire;
  int n = s.size();

  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'R')
    {
      rad.push(i);
    }
    else if (s[i] == 'D')
    {
      dire.push(i);
    }
  }

  while (!rad.empty() && !dire.empty())
  {
    int ridx = rad.front();
    int didx = dire.front();

    rad.pop();
    dire.pop();

    if (ridx < didx)
    {
      rad.push(ridx + n);
    }
    else
    {
      dire.push(didx + n);
    }
  }
  return rad.empty() ? "Dire" : "Radiant";
}

int main()
{
  string s;
  cout << "Enter the senate sequence: ";
  cin >> s;

  string res = predict(s);
  cout << "Winning Party: " << res << endl;

  return 0;
}