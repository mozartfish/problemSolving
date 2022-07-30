class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // result
        vector<int> result(2);

        // map for storing difference
        unordered_map<int, int> intMap;

        // size
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int diff = nums[i] - target;
            if (intMap.find(diff) != intMap.end())
            {
                result.push_back(intMap[diff]);
                result.push_back(i);
                return result;
            }
            else
            {
                intMap.insert({nums[i], i});
            }
        }

        return result;
    }
};