#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::vector<int> res;
        std::unordered_map<int, int> check;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            int index = std::distance(nums.begin(), it);
            check.insert({*it, index});
        }
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            bool del = false;
            int index = std::distance(nums.begin(), it);
            auto tempIndex = (check.find(*it))->second;
            if (index == tempIndex)
            {
                check.erase(*it);
                del = true;
            }
            int checkVal = target - *it;
            auto itCheck = check.find(checkVal);
            if (itCheck != check.end())
            {
                res.push_back(index);
                res.push_back(itCheck->second);
                return res;
            }
            if (del)
                check.insert({*it, tempIndex});
        }
        return res;
    }
};
