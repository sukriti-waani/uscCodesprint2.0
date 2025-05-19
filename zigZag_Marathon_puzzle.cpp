/* Zig-Zag Marathon Pattern : 
program that, given a number of days (between 1 and 20), prints a pyramid pattern of numbers.
Odd-numbered rows should display numbers in increasing order from 1.
Even-numbered rows should display numbers in decreasing order from the row number.
The pattern should be center aligned.
At the end, print the total count of numbers printed.

Input:
Enter the number of days
5
 Output:
        1
      2   1
    1   2   3
  4   3   2   1
1   2   3   4   5
Total numbers printed: 15
*/

#include <iostream>
using namespace std;

int main()
{
  int days;
  cout << "Enter the number of days" << endl;
  cin >> days;

  if (days < 1 || days > 20)
  {
    cout << "Please enter a number between 1 and 20" << endl;
    return 0;
  }

  if (days > 10)
  {
    cout << "Let's see the Abhik's marathon journey progress: " << endl;
  }

  int total = 0;

  for (int i = 1; i <= days; i++)
  {
    int spaces = (days - i) * 2;

    for (int s = 1; s <= spaces; s++)
    {
      cout << " ";
    }

    if (i % 2 == 1)
    {
      for (int j = 1; j <= i; j++)
      {
        cout << j;
        if (j != i)
          cout << "   ";
      }
    }
    else
    {
      for (int j = i; j >= 1; j--)
      {
        cout << j;
        if (j != 1)
          cout << "   ";
      }
    }
    cout << endl;
    total += i;
  }

  cout << "Total numbers printed: " << total << endl;
  return 0;
}