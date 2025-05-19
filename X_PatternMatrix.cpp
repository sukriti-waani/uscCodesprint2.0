/*   X - Pattern Matrix Puzzle
 Program that takes an odd integer n (3 ≤ n ≤ 1000) as input and prints an n x n pattern where:
The main diagonal (top-left to bottom-right) contains numbers starting from 1 to n.
The secondary diagonal (top-right to bottom-left) contains numbers starting from n to 1.
All other positions contain a dash - 
input: n = 5 
Output : 
        1 - - - 5
        - 2 - 4 -
        - - 3 - -
        - 2 - 4 -
        1 - - - 5
*/

#include <iostream>
using namespace std;

void printPattern(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        cout << i + 1;
      }
      else if (i + j == n - 1)
      {
        cout << n - i;
      }
      else
      {
        cout << '-';
      }
      if (j != n - 1)
      {
        cout << " ";
      }
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cout << "Enter the number: " << endl;
  cin >> n;

  if (n >= 3 && n <= 1000 && n % 2 == 1)
  {
    printPattern(n);
  }
  else
  {
    cout << "Invalid Input. Enter an odd number between 3 and 1000." << endl;
  }
  return 0;
}