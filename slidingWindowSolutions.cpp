// Maximum Sum Subarray of Size K(easy)
// Problem : Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.
// Example 1
// Input: [2, 1, 5, 1, 3, 2], k=3
// Output: 9
// Explanation: Subarray with maximum sum is [5, 1, 3].
// Example 2
// Input: [2, 3, 4, 1, 5], k=2
// Output: 7
// Explanation: Subarray with maximum sum is [3, 4].

// Runtime - O(n)
// FIXED WINDOW EXAMPLE
static int findMaxSumSubArray(int k, int[] arr)
{
    int windowStart = 0;
    int windowSum = 0;
    int maxSum = 0;
    for (int windowEnd = 0; windowEnd < arr.length; windowEnd++)
    {
        // add element to rolling sum
        windowSum += arr[windowEnd];
        // slide window of size k if windowEnd = size k
        if (windowEnd >= k - 1)
        {
            maxSum = max(maxSum, windowSum);
            // remove the element leaving the window of size k
            windowSum -= arr[windowStart];
            // update the index of the start of the window
            windowStart++;
        }
    }
    return maxSum;
}

// Smallest Subarray With a Greater Sum(easy)
// Problem: Given an array of positive integers and a number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’.Return 0 if no such subarray exists.
// Example 1
// Input: [2, 1, 5, 2, 3, 2], S=7
// Output: 2
// Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [5, 2].
// Example 2
// Input: [2, 1, 5, 2, 8], S=7
// Output: 1
// Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [8].
// Example 3
// Input: [3, 4, 1, 1, 6], S=8
// Output: 3
// Explanation: Smallest subarrays with a sum greater than or equal to ‘8’ are [3, 4, 1] or [1, 1, 6].

// Runtime - O(n)
// DYNAMIC WINDOW EXAMPLE
static int findMinSubArray(int S, const vector<int> &arr)
{
    int minLen = numeric_limits<int>::max();
    int windowSum = 0;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd];
        // Shrink window until window sum is smaller than S
        while (windowSum >= S)
        {
            minLen = min(minLen, windowEnd - windowStart + 1);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    return minLen == numeric_limits<int>::max() ? 0 : minLen;
}

// Longest Substring with maximum K Distinct Characters(medium)
// Problem : Given a string, find the length of the longest substring in it with no more than K distinct characters.
// Example 1
// Input: String="araaci", K=2
// Output: 4
// Explanation: The longest substring with no more than '2' distinct characters is "araa".
// Example 2
// Input: String="araaci", K=1
// Output: 2
// Explanation: The longest substring with no more than '1' distinct characters is "aa".
// Example 3
// Input: String="cbbebi", K=3
// Output: 5
// Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
// Example 4
// Input: String="cbbebi", K=10
// Output: 6
// Explanation: The longest substring with no more than '10' distinct characters is "cbbebi".
static int findLength(const string &str, int k)
{
    int windowStart = 0;
    int maxLen = 0;
    unordered_map<char, int> charCount;
    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        charCount[rightChar]++;
        // shrink window until have k distinct characters in map
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

    return maxLen;
}

// Fruits into Baskets(medium)
// Problem : You are visiting a farm to collect fruits.The farm has a single row of fruit trees.You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.You will be given an array of characters where each character represents a fruit tree.The farm has following restrictions:
// Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
// You can start with any tree, but you can’t skip a tree once you have started.
// You will pick exactly one fruit from every tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
// Example 1
// Input: Fruit=['A', 'B', 'C', 'A', 'C']
// Output: 3
// Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
// Example 2
// Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
// Output: 5
// Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
// This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
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

    return maxFruit;
}

// Longest Substring with Distinct Characters(hard)
// Problem : Given a string, find the length of the longest substring, which has all distinct characters.
// Example 1
// Input: String="aabccbb"
// Output: 3
// Explanation: The longest substring with distinct characters is "abc".
// Example 2
// Input: String="abbbb"
// Output: 2
// Explanation: The longest substring with distinct characters is "ab".
// Example 3
// Input: String="abccde"
// Output: 3
// Explanation: Longest substrings with distinct characters are "abc" & "cde".
static int findLength(const string &str)
{
    int windowStart = 0;
    int maxLen = 0;
    unordered_map<char, int> charCount;
    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        // search for the next character
        if (charCount.find(rightChar) != charCount.end())
        {
            windowStart = max(windowStart, charCount[rightChar] + 1);
        }
        charCount[rightChar] = windowEnd;
        maxLen = max(maxLen, windowEnd - windowStart + 1);
    }

    return maxLen;
}