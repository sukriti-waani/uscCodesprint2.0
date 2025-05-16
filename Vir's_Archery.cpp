#include <iostream>
#include <vector>
using namespace std;

void countShots(vector<int> &scores, int &good, int &missed)
{
  good = 0;
  missed = 0;

  for (int i = 0; i < scores.size(); i++)
  {
    if (scores[i] >= 7)
    {
      good++;
    }
    else
    {
      missed++;
    }
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> scores(n);

  for (int i = 0; i < n; i++)
  {
    cin >> scores[i];
  }

  int goodS, missedS;

  countShots(scores, goodS, missedS);

  cout << goodS << " " << missedS << endl;

  return 0;
}
