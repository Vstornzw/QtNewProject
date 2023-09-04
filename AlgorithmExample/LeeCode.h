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
} // NO.1

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; // NO.2

ListNode* _2_tow_add(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val: 0;
        int n2 = l2 ? l2->val: 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = new ListNode(sum % 10);
        } else {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = new ListNode(carry);
    }
    return head;
} // NO.2

#include <unordered_set>
#include <algorithm>
int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
}//NO.3

void LeeCode()
{


    {
        vector<int> numsVec = {2,7,8,9,10};
        vector<int> nums = _1_twoSum(numsVec, 9);
        int a = 0;
    } //NO.1


    {
        // 制造数据
        ListNode* l1_2 = new ListNode(9);
        ListNode* l1_1 = new ListNode(4, l1_2);
        ListNode* l1 = new ListNode(2, l1_1);

        ListNode* l2_2 = new ListNode(5);
        ListNode* l2_1 = new ListNode(6, l2_2);
        ListNode* l2 = new ListNode(4, l2_1);

        //处理结果
        //942 + 564 = 1506
        ListNode *node = _2_tow_add(l1, l2);

        delete l1_2;
        delete l1_1;
        delete l1;
        delete l2_2;
        delete l2_1;
        delete l2;
        delete node;
    } //NO.2


    {
        string s = "abcdefabbbcccdddedfdfgfg";
        int nLen = lengthOfLongestSubstring(s);
        int a = nLen;
    }//NO.3


    {

    }
}
#endif // LEECODE_H
