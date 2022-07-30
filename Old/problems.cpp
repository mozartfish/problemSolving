// Monday July 11
// Permutation in a String(hard)
// Given a string and a pattern, find out if the string contains any permutation of the pattern.
// Permutation is defined as the re-arranging of the characters of the string.

// Runtime: O(N + M) where N is the number of characters in the input, M is the number of characters in the pattern
static bool findPermutation(const string &str, const string &pattern)
{
    // TODO: Write your code here
    unordered_map<char, int> charCount;
    int matched = 0;
    int windowStart = 0;

    // store the pattern
    for (auto chr : pattern)
    {
        charCount[chr]++;
    }

    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        // get the current char
        char rightChar = str[windowEnd];
        if (charCount.find(rightChar) != charCount.end())
        {
            charCount[rightChar]--;
            if (charCount[rightChar] == 0)
            {
                matched++;
            }
        }

        // check if we have matched the pattern
        if (matched == charCount.size())
        {
            return true;
        }

        // check if the sliding window has gone past the pattern
        if (windowEnd >= pattern.size() - 1)
        {
            char leftChar = str[windowStart++];
            if (charCount.find(leftChar) != charCount.end())
            {
                if (charCount[leftChar] == 0)
                {
                    matched--;
                }
                charCount[leftChar]++;
            }
        }
    }
    return false;
}


