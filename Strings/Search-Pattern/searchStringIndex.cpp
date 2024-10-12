#include <iostream>
#include <string>
#include <vector>
using namespace std;
// above mentions are only for sake of VS Code intellisense

class Solution
{
    // Function to compute the LPS array
    void computeLPS(const string &pattern, vector<int> &lps)
    {
        int n = pattern.length();

        // Initialize the first value of LPS to 0 as it is always 0
        lps[0] = 0;

        // Actual computation of LPS
        for (int i = 1, j = 0; i < n;)
        {
            if (pattern[i] == pattern[j])
            {
                lps[i] = j + 1;
                i++;
                j++;
            }
            else if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Function to search the all indexes of the pattern in the text
    vector<int> searchStringIndex(const string &text, const string &pattern)
    {
        int txtLen = text.length();
        int patLen = pattern.length();

        vector<int> lps(patLen);
        vector<int> indexes;

        computeLPS(pattern, lps);

        for (int i = 0, j = 0; i < txtLen;)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;

                if (j == patLen)
                {
                    indexes.push_back(i - patLen); // Pattern found at index i-patternLength
                    j = lps[j - 1];
                }
            }
            else if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (indexes.empty())
        {
            indexes.push_back(-1);
        }
        for (int idx : indexes)
        {
            cout << idx << " ";
        }
    }
};