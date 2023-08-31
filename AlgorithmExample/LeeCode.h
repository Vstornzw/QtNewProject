#ifndef LEECODE_H
#define LEECODE_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> _1_twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
}

void LeeCode()
{


    {
        vector<int> numsVec = {2,7,8,9,10};
        vector<int> nums = _1_twoSum(numsVec, 9);
        int a = 0;
    } //NO.1


    {

        int a = 0;
    } //NO.2
}
#endif // LEECODE_H
