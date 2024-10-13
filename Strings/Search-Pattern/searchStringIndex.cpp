/*
 * Algorithm: KMP Pattern Matching
 *
 * 1. **Input:** Two strings:
 *    - `text`: The string where we are searching for the pattern.
 *    - `pattern`: The string we want to find in the text.
 *
 * 2. **LPS Array Calculation:**
 *    - The LPS (Longest Prefix Suffix) array stores, for each index `i` in the pattern, the length of the longest proper prefix of the pattern
 *      which is also a suffix ending at that index.
 *    - We initialize the first value of LPS as 0.
 *    - We then iterate through the pattern using two pointers `i` (current index) and `j` (tracks the length of matching prefix-suffix).
 *    - If `pattern[i] == pattern[j]`, we increment both `i` and `j` and update `lps[i] = j`.
 *    - If they do not match and `j != 0`, we backtrack using `j = lps[j-1]`.
 *    - If `j == 0`, we set `lps[i] = 0` and increment `i`.
 *
 * 3. **Pattern Search Using LPS:**
 *    - Using the computed LPS array, we iterate through the `text` and compare it with the `pattern`.
 *    - We initialize `i = 0` for the text and `j = 0` for the pattern.
 *    - If `text[i] == pattern[j]`, we increment both `i` and `j`.
 *    - If `j` reaches the length of the pattern, we found a match, and we store the index of the match as `i - patLen`.
 *      Then we backtrack using `j = lps[j-1]`.
 *    - If `text[i] != pattern[j]` and `j != 0`, we backtrack `j = lps[j-1]` without incrementing `i`.
 *    - If `j == 0`, we increment `i` and continue the search.
 *
 * 4. **Return the Results:**
 *    - If no match is found, we return `-1`.
 *    - Otherwise, we return the indices of all matches found in the text.
 *
 * **Time Complexity:** O(n + m), where n is the length of the text and m is the length of the pattern.
 * **Space Complexity:** O(m) due to the LPS array.
 */

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