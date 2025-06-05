/*    Reveal Cards in Increasing Order
You are given a deck of n unique integers representing cards. The deck will be revealed one by one using the following process:
Reveal the top card and remove it from the deck.
If there are still cards in the deck, move the next top card to the bottom of the deck.
Repeat steps 1 and 2 until all cards are revealed.
Your task is to reorder the input deck such that the revealed card sequence is in increasing order.

Input Format
First line: An integer n (number of cards)
Second line: n space-separated integers (values of the cards)
Output Format
First line: Initial deck order to achieve increasing reveal
Second line: The revealed card sequence

Sample Input
3
5 12 9
Sample Output
Initial deck order to reveal increasing: 5 12 9
Revealed sequence: 5 9 12
Sample Input 2
7
17 13 11 2 3 5 7
Sample Output 2
Initial deck order to reveal increasing: 2 13 3 11 5 17 7
Revealed sequence: 2 3 5 7 11 13 17

Explanation
You are not supposed to just sort the deck.
You must arrange the deck before the reveal so that when the above process is run, the sequence of revealed cards is sorted.
Your solution calculates and prints:
The deck in the required order
The actual reveal order to verify correctness

*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> deckInc(vector<int> &deck)
{
  sort(deck.begin(), deck.end());
  deque<int> dq;

  for (int i = deck.size() - 1; i >= 0; i--)
  {
    if (!dq.empty())
    {
      dq.push_front(dq.back());
      dq.pop_back();
    }
    dq.push_front(deck[i]);
  }
  return {dq.begin(), dq.end()};
}

vector<int> reveal(vector<int> &deck)
{
  deque<int> dq(deck.begin(), deck.end());
  vector<int> revealed;

  while (!dq.empty())
  {
    revealed.push_back(dq.front());
    dq.pop_front();

    if (!dq.empty())
    {
      dq.push_back(dq.front());
      dq.pop_front();
    }
  }
  return revealed;
}

int main()
{
  int n;
  cout << "Enter number of cards: ";
  cin >> n;

  vector<int> deck(n);
  cout << "Enter the card values: \n";
  for (int &card : deck)
  {
    cin >> card;
  }

  vector<int> res = deckInc(deck);

  cout << "Initial deck order to reveal increasing: ";
  for (int card : res)
  {
    cout << card << " ";
  }
  cout << endl;

  vector<int> revealSeq = reveal(res);
  cout << "Sequence: ";
  for (int card : revealSeq)
  {
    cout << card << " ";
  }
  cout << endl;

  return 0;
}