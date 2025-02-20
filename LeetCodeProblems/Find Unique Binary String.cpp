// Problem Link
// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20

// Source Code
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string res;

    bool helper(const unordered_set<string>& s, string curr, int n) {
        if (curr.length() == n) {
            if (s.find(curr) == s.end()) { 
                res = curr;  
                return true; 
            }
            return false;
        }

        if (helper(s, curr + '0', n)) return true;
        if (helper(s, curr + '1', n)) return true;

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end()); 
        res = "";  

        helper(st, "", nums.size());  
        return res;  
    }
};
