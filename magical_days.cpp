// Magical Days in the coding Marathon :  Count how many days have a score greater than both the previous and next day's scores.
// Input: n = 7
//        scores = [10, 20, 15, 18, 17, 19, 14]
// Output: 3

#include <iostream>
using namespace std;

int cntMagicalDays(int scores[], int n)
{
  int cnt = 0;
  for (int i = 1; i < n - 1; i++)
  {
    if (scores[i] > scores[i - 1] && scores[i] > scores[i + 1])
    {
      cnt++;
    }
  }
  return cnt;
}

int main()
{
  int n;
  cout << "Enter the number of days " << endl;
  cin >> n;

  int scores[100];
  cout << "Enter the scores" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> scores[i];
  }
  cout << cntMagicalDays(scores, n) << endl;

  return 0;
}