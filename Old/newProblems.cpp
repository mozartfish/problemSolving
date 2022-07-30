#include <iostream>
#include <unordered_map>
#include <vector>

// Two Sum - runtime O(n) single pass 
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> numMap;
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            int diff = target - nums[i];
            // check if have difference
            if (numMap.find(diff) != numMap.end())
            {
                result.push_back(numMap[diff]);
                result.push_back(i);
            }
            numMap.insert({nums[i], i});
        }

        return result;
    }
};

