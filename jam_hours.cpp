//  Critical Jam Hours DEtection: Count the number of hours where vehicle count is at least 50 and greater than the previous hour.
// Input: 7
//     45 52 49 61 62 58 70
// Output: 4

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cout << "Enter the total number of hours" << endl;
  cin >> n;

  vector<int> vehicles(n);

  cout << "Enter the number of vehicles" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> vehicles[i];
  }

  int cnt = 0;
  for (int i = 1; i < n; i++)
  {
    if (vehicles[i] >= 50 && vehicles[i] > vehicles[i - 1])
    {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}