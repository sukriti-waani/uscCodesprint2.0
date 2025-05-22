/*    Movement Segment Counter  
You are given a binary string representing a robot's movement log, where:
'1' means the robot is moving.
'0' means the robot is not moving.
Each continuous block of '1's is counted as one movement segment.
Count how many movement segments are in the string.

intput : log = "001100111010"
output : 3
*/

#include <iostream>
using namespace std;

int countSegments(string log)
{
  int count = 0;

  for (int i = 0; i < log.length(); i++)
  {
    if (log[i] == '1' && (i == 0 || log[i - 1] == '0'))
    {
      count++;
    }
  }
  return count;
}

int main()
{
  string log;

  cout << "Enter binary movement log: " << endl;
  cin >> log;

  int segments = countSegments(log);
  cout << "Total movement segments: " << segments << endl;

  return 0;
}