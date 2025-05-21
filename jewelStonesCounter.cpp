/*  Jewel Stones Counter
You are given two strings:
jewels: a string representing the types of stones that are jewels.
stones: a string representing the stones you have.
Each character in stones is a type of stone.
Your task is to count how many stones are also jewels.
Input Format:
Two strings:
1st line → jewels
2nd line → stones
Example:
Input:
aA
aAAbbbb
Output:
3
Explanation:
Jewels: a and A
Stones: a A A b b b b
Matching jewels in stones: a, A, A → 3 matches
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int countJewels(string &jewels, string &stones)
{
  unordered_set<char> jewelSet;

  for (int i = 0; i < jewels.size(); i++)
  {
    jewelSet.insert(jewels[i]);
  }

  int count = 0;

  for (int i = 0; i < stones.size(); i++)
  {
    if (jewelSet.count(stones[i]))
    { // if the current stone is in the jewel set, increment the cont
      count++;
    }
  }
  return count;
}

int main()
{
  string jewels, stones;

  cout << "Enter the jewels and stones: " << endl;
  cin >> jewels;
  cin >> stones;

  cout << countJewels(jewels, stones);

  return 0;
}