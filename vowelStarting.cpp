/*   Vowel-Starting Unique Patient Names
Write a program that reads n names and outputs the number of unique names that start with a lowercase vowel (a, e, i, o, u). Also print those names in the order they appeared in the input.
Input Format:
First line: An integer n (number of names)
Next n lines: Each line contains one name
Output Format:
First line: Count of unique names starting with a vowel
Second line: Names separated by a space

Sample Input:
6
amit
anil
anil
om
uma
ankit
Sample Output:
4
amit anil om uma
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool startsWithVowel(string &name)
{
  if (name.empty())
  {
    return false;
  }
  char c = name[0];
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
  int n;
  cout << "Enter the number: " << endl;
  cin >> n;

  unordered_set<string> mp;
  vector<string> ans;
  string name;

  cout << "Enter names: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> name;
    if (startsWithVowel(name) && mp.insert(name).second)
    {
      ans.push_back(name);
    }
  }

  cout << "Count = " << ans.size() << endl;

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}