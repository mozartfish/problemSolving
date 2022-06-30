// Maximum Sum Subarray of Size K(easy)
// Problem : Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.
static int findMaxSumSubArray(int k, const vector<int> &arr)
{
    int maxSum = 0;
    int windowStart = 0;
    int windowSum = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd];
        if (windowEnd >= k - 1)
        {
            maxSum = max(maxSum, windowSum);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }
    // TODO: Write your code here
    return maxSum;
}

// Smallest Subarray With a Greater Sum(easy)
// Given an array of positive integers and a number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.
static int findMinSubArray(int S, const vector<int> &arr)
{
    int windowStart = 0;
    int minLen = numeric_limits<int>::max();
    int windowSum = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd];
        while (windowSum >= S)
        {
            minLen = min(minLen, windowEnd - windowStart + 1);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }
    // TODO: Write your code here
    return minLen == numeric_limits<int>::max() ? 0 : minLen;
}

// Longest Substring with maximum K Distinct Characters(medium)
// Given a string, find the length of the longest substring in it with no more than K distinct characters.
static int findLength(const string &str, int k)
{
    int windowStart = 0;
    int maxLen = 0;
    unordered_map<char, int> charCount;
    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        charCount[rightChar]++;
        while (charCount.size() > k)
        {
            char leftChar = str[windowStart];
            charCount[leftChar]--;
            if (charCount[leftChar] == 0)
            {
                charCount.erase(leftChar);
            }
            windowStart++;
        }
        maxLen = max(maxLen, windowEnd - windowStart + 1);
    }
    // TODO: Write your code here
    return maxLen;
}
// Fruits into Baskets(medium)
// Problem : You are visiting a farm to collect fruits.The farm has a single row of fruit trees.You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.You will be given an array of characters where each character represents a fruit tree.The farm has following restrictions:
// Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
// You can start with any tree, but you can’t skip a tree once you have started.
// You will pick exactly one fruit from every tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
static int findLength(const vector<char> &arr)
{
    int windowStart = 0;
    int maxFruit = 0;
    unordered_map<char, int> fruitCount;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        char rightFruit = arr[windowEnd];
        fruitCount[rightFruit]++;
        while (fruitCount.size() > 2)
        {
            char leftFruit = arr[windowStart];
            fruitCount[leftFruit]--;
            if (fruitCount[leftFruit] == 0)
            {
                fruitCount.erase(leftFruit);
            }
            windowStart++;
        }
        maxFruit = max(maxFruit, windowEnd - windowStart + 1);
    }
    // TODO: Write your code here
    return maxFruit;
}

// Longest Substring with Distinct Characters(hard)
// Problem : Given a string, find the length of the longest substring, which has all distinct characters.
static int findLength(const string &str)
{
    int maxLen = 0;
    int windowStart = 0;
    unordered_map<char, int> charCount;
    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        if (charCount.find(rightChar) != charCount.end())
        {
            windowStart = max(windowStart, charCount[rightChar] + 1);
        }
        charCount[rightChar] = windowEnd;
        maxLen = max(maxLen, windowEnd - windowStart + 1);
    }
    // TODO: Write your code here
    return maxLen;
}

// Longest Substring with Same Letters after Replacement(hard)
// Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter, find the length of the longest substring having the same letters after replacement.
static int findLength(const string &str, int k)
{
    int maxLength = 0;
    int windowStart = 0;
    int maxRepeat = 0;
    unordered_map<char, int> charCount;
    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        charCount[rightChar]++;
        maxRepeat = max(maxRepeat, charCount[rightChar]);
        if (windowEnd - windowStart + 1 - maxRepeat > k)
        {
            char leftChar = str[windowStart];
            charCount[leftChar]--;
            windowStart++;
        }

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    // TODO: Write your code here
    return maxLength;
}

// Longest Subarray with Ones after Replacement(hard)
// Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.
static int findLength(const vector<int> &arr, int k)
{
    int maxLength = 0;
    int maxOnes = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        if (arr[windowEnd] == 1)
        {
            maxOnes++;
        }

        if (windowEnd - windowStart + 1 - maxOnes > k)
        {
            if (arr[windowStart] == 1)
            {
                maxOnes--;
            }
            windowStart++;
        }

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    // TODO: Write your code here
    return maxLength;
}

// Permutation in a String(hard)
// Given a string and a pattern, find out if the string contains any permutation of the pattern.
static bool findPermutation(const string &str, const string &pattern)
{
    int windowStart = 0;
    int matched = 0;
    unordered_map<char, int> charCount;
    for (auto chr : pattern)
    {
        charCount[chr]++;
    }

    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        if (charCount.find(rightChar) != charCount.end())
        {
            charCount[rightChar]--;
            if (charCount[rightChar] == 0)
            {
                matched++;
            }
        }

        if (matched == charCount.size())
        {
            return true;
        }

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
    // TODO: Write your code here
    return false;
}

// String Anagrams(hard)
// Given a string and a pattern, find all anagrams of the pattern in the given string.
static vector<int> findStringAnagrams(const string &str, const string &pattern)
{
    vector<int> resultIndices;
    int windowStart = 0;
    int matched = 0;
    unordered_map<char, int> charCount;

    // populate all the characters
    for (auto chr : pattern)
    {
        charCount[chr]++;
    }

    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        if (charCount.find(rightChar) != charCount.end())
        {
            charCount[rightChar]--;
            if (charCount[rightChar] == 0)
            {
                matched++;
            }
        }

        if (matched == charCount.size())
        {
            resultIndices.push_back(windowStart);
        }

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
    // TODO: Write your code here
    return resultIndices;
}
