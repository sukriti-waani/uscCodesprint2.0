/*    Reverse and Clean the Speech Line
You are given a sentence as a string. The sentence may contain multiple spaces between words, as well as leading and trailing spaces. Your task is to reverse the order of words in the sentence and output the cleaned-up result.
Make sure to:
Remove extra spaces between words (use only a single space).
Remove leading and trailing spaces.
Keep the characters in each word in the same order.

Sample Input :
Enter a sentence:  
  hello    world   GPT  
Sample Output :
Reverse word: GPT world hello
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string& s) {
  int n = s.length();
  string ans = "";

  reverse(s.begin(), s.end());

  for(int i = 0; i < n; i++) {
    if(s[i] == ' ') continue;
    
    string word = "";
    while(i < n && s[i] != ' ') {
      word += s[i];
      i++;
    }

    reverse(word.begin(), word.end());

    if(!word.empty()) {
      if(!ans.empty()) {
        ans += " ";
      }
      ans += word;
    }
  }
    return ans;
}

int main() {
  string input;
  cout << "Enter a sentence: " << endl;
  getline(cin, input);

  string ans = reverseWords(input);
  cout << "Reverse word: " << ans << endl;
  
  return 0;
}