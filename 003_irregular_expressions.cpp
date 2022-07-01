#include <iostream>
#include <vector>

using namespace std;

struct substr
{
  int i, len;
};

int isVowel(char c)
{
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isSpell(vector<substr> &words, string s)
{
  for (substr word : words)
  {
    int k = word.i + word.len;
    while (k < s.length() && !isVowel(s[k++]))
      ;

    for (int i = k; (i + word.len) <= s.length(); i++)
    {
      if (s.substr(word.i, word.len) == s.substr(i, word.len))
        return true;
    }
  }

  return false;
}

int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    vector<substr> words;
    vector<int> prefixSumNumVowels;
    string s;
    cin >> s;

    int numVowels = 0;
    for (char c : s)
    {
      if (isVowel(c))
        numVowels++;
      prefixSumNumVowels.push_back(numVowels);
    }

    for (int j = 0; j < s.length(); j++)
    {
      if (isVowel(s[j]))
      {
        int k = 1;
        while ((j + k) <= s.length())
        {
          numVowels = j > 0 ? prefixSumNumVowels[j + k - 1] - prefixSumNumVowels[j - 1]
                            : prefixSumNumVowels[j + k - 1];

          if (numVowels > 1)
            words.push_back((substr){j, k});
          k++;
        }
      }
    }

    cout << "Case #" << (i + 1) << ": " << (isSpell(words, s) ? "Spell!" : "Nothing.") << endl;
  }

  return 0;
}
