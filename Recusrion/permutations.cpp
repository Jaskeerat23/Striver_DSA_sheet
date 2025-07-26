#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void generatePermutations(vector<int>& nums, vector<vector<int>>& res, int src){
        if(src == nums.size()){
            // for(const auto)
            res.push_back(nums);
            return;
        }
        for(int i = src; i<nums.size(); i++){
            swap(nums[src], nums[i]);
            generatePermutations(nums, res, src + 1);
            swap(nums[src], nums[i]);
        }
    }
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        generatePermutations(nums, res, 0);
        return res;
    }
};
int main(){
    int range;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<vector<int>> ans = Solution :: permute(nums);
    // for(const auto& it1 : ans){
    //     for(const auto& it2 : it1)
    //         cout << it2 << " ";
    //     cout << endl;
    // }
}