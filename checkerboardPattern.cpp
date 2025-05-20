/*  Exam Seating Arrangement - Checkerboard Pattern
You are given a square hall with n × n seats. Students can only be seated at positions where the sum of the row and column indices is even (i.e., (i + j) % 2 == 0).
Write a program to:  Print the seating arrangement where:
1 represents a student seated,
0 represents an empty seat.
Count and print the total number of students seated.

*/

#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the number: " << endl;
  cin >> n;

  int count = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if ((i + j) % 2 == 0)
      {
        cout << "1 ";
        count++;
      }
      else
      {
        cout << "0 ";
      }
    }
    cout << endl;
  }

  cout << "Total students seated: " << count << endl;
  return 0;
}