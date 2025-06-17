/*          Check if At Least k Unique Themes Exist
You are given a list of N themes (integers), where some themes may repeat. Your task is to determine whether the list contains at least k unique themes.
Input Format:
The first line contains an integer N — total number of themes.
The second line contains an integer k.
The next line contains N integers — the theme IDs.
Output Format:
Print "Yes" if there are at least k unique themes.
Print "No" otherwise.

Example:
Input:
Enter total themes: 5
Enter value of k: 2
Enter themes:
2 3 2 1 3
Output:
Yes
Explanation:
Unique themes = {1, 2, 3} → count = 3
Since 3 ≥ 2 → Output is "Yes"
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool uniqueThemes(vector<int> &themes, int k)
{
  unordered_set<int> ut(themes.begin(), themes.end());

  return ut.size() >= k;
}

int main()
{
  int n, k;
  cout << "Enter total themes: ";
  cin >> n;

  cout << "Enter vale of k: ";
  cin >> k;

  vector<int> themes(n);

  cout << "Enter themes: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> themes[i];
  }

  if (uniqueThemes(themes, k))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}