/*              Super-Primes Up to N
A super-prime is a prime number whose position (1-based index) in the sequence of all prime numbers is also a prime number.
Write a program to find and print all super-primes that are less than or equal to a given number n.

Input:
A single integer n (2 ≤ n ≤ 10⁶), representing the upper limit.
Output:
Print all super-primes up to n in a single line, space-separated.

Example:
Input:
Enter input number: 30
All primes up to 30:
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
Their positions (1-based):
1   2   3  4   5    6    7    8    9   10
2   3   5  7  11   13   17   19   23   29
Prime indices:
Positions that are prime: 2, 3, 5, 7
So the primes at these positions are:
position 2 → 3
position 3 → 5
position 5 → 11
position 7 → 17
Output:
3 5 11 17
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> generateSieve(int maxN)
{
  vector<bool> isPrime(maxN + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= maxN; i++)
  {
    if (isPrime[i])
    {
      for (int j = i * i; j <= maxN; j += i)
      {
        isPrime[j] = false;
      }
    }
  }
  return isPrime;
}

vector<int> primes(vector<bool> &isPrime, int n)
{
  vector<int> prime;
  for (int i = 2; i <= n; i++)
  {
    if (isPrime[i])
    {
      prime.push_back(i);
    }
  }
  return prime;
}

int main()
{
  int n;
  cout << "Enter input number: ";
  cin >> n;

  vector<bool> isPrime = generateSieve(n);
  vector<int> prime = primes(isPrime, n);
  int size = prime.size();
  vector<bool> primeIdx = generateSieve(size);

  for (int i = 1; i <= size; i++)
  {
    if (primeIdx[i])
    {
      cout << prime[i - 1] << " ";
    }
  }
  return 0;
}