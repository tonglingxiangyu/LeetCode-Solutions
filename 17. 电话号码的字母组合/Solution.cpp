#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phoneMap{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        if(digits.empty()) return res;
        string combination;
        backtrack(combination, 0, res, phoneMap, digits);
        return res;
    }

    void backtrack(string combination, int index, vector<string>& res, unordered_map<char, string> phoneMap, string digits){
        if(index == digits.length()){
            res.push_back(combination);
            return ;
        }
        char digit = digits[index];
        string letters = phoneMap.at(digit);
        for(char letter: letters){
            combination.push_back(letter);
            backtrack(combination, index + 1, res, phoneMap, digits);
            combination.pop_back();
        }
    }
};