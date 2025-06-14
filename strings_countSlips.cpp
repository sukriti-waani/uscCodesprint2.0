/*        Counting Slips While Walking
You are walking on a 2D infinite grid. Your starting position is at coordinate (0, 0). You are given a string S that consists of characters:
'L' → Move left (decrease x by 1)
'R' → Move right (increase x by 1)
'U' → Move up (increase y by 1)
'D' → Move down (decrease y by 1)
Each move changes your current position accordingly.
However, if you step on any position which you have already visited before, you slip.
Your task is to count how many times you slip during the entire walk.
Input
A string S of length n (1 ≤ n ≤ 10⁵), consisting only of characters 'L', 'R', 'U', and 'D'.
Output
Print a single integer: the total number of slips.

Example
Input
LLRRUUDDLL

Output
6
Constraints:
String length: up to 10⁵
No invalid characters
Initial position always starts at (0,0)
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

int countSlips(string &s)
{
  int x = 0, y = 0;
  set<string> visited;
  visited.insert("0,0");
  int slips = 0;

  for (char mv : s)
  {
    if (mv == 'L')
      x--;
    else if (mv == 'R')
      x++;
    else if (mv == 'U')
      y++;
    else if (mv == 'D')
      y--;

    string posKey = to_string(x) + "," + to_string(y);

    if (visited.count(posKey))
    {
      slips++;
    }
    else
    {
      visited.insert(posKey);
    }
  }
  return slips;
}

int main()
{
  string s;
  cout << " Enter characters 'L', 'R' , 'U' or 'D': ";
  cin >> s;

  cout << countSlips(s) << endl;

  return 0;
}