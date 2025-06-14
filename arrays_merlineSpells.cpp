/*        Merlin's Spell Enhancement
Merlin is preparing for a magical duel. He has a list of spells, each with a certain power level. However, his opponent Morgana has discovered the maximum power level among all of Merlin's spells.
To guarantee victory, Merlin wants every one of his spells to have strictly greater power than Morgana's strongest spell.
Merlin can spend mana to increase the power of any spell. Increasing the power of a spell by 1 unit costs 1 mana.
Your task is to calculate the minimum total amount of mana Merlin needs to spend so that all of his spells become strictly stronger than Morgana's strongest spell.

Input
The first line contains an integer n — the number of Merlin's spells.
The second line contains n integers — the power levels of Merlin's spells.
Output
Output a single integer — the minimum total mana Merlin needs to spend.

Constraints
1 ≤ n ≤ 10^5
0 ≤ spell power ≤ 10^9

Explanation
Since Morgana already knows Merlin's strongest spell, you can assume Morgana’s strongest spell is the maximum spell power from Merlin's list itself.
For every spell whose power is less than or equal to this maximum, Merlin needs to increase it by (max power - spell power + 1) to make it strictly greater.

Example
Input
5
3 5 2 5 1
Explanation:
The maximum power Morgana knows is 5.

Spell Power	Required New Power	Mana Needed
3	6	6-3 = 3
5	6	6-5 = 1
2	6	6-2 = 4
5	6	6-5 = 1
1	6	6-1 = 5
Total mana required: 3 + 1 + 4 + 1 + 5 = 14

Output
14

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long func(vector<long long> &merlinSp, long long maxMor)
{
  long long res = 0;
  for (auto spell : merlinSp)
  {
    if (spell <= maxMor)
    {
      res += (maxMor - spell + 1);
    }
  }

  return res;
}

int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;
  vector<long long> merlinSp;
  vector<long long> spells;
  spells.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> spells[i];
  }

  long long maxMor = *max_element(spells.begin(), spells.end());

  long long res = func(spells, maxMor);

  cout << res << endl;

  return 0;
}