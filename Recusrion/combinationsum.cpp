#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static void generateCombinations(vector<int>& nums, vector<int>& currArr, vector<vector<int>>& res, int n, int tarRem){
        if(tarRem == 0){
            res.push_back(currArr);
            return;
        }
        else if(tarRem < 0){
            return;
        }
        for(int i = n; i<nums.size(); i++){
            currArr.push_back(nums[i]);
            generateCombinations(nums, currArr, res, i, tarRem - nums[i]);
            currArr.pop_back();
        }
    }
    static vector<vector<int>> combinationSum(vector<int>& nums, int target){
        vector<int> currArr;
        vector<vector<int>> res;
        generateCombinations(nums, currArr, res, 0, target);
        return res;
    }
};
int main(){
    int range, target, num;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter target : ";
    cin >> target;
    vector<vector<int>> res =  Solution :: combinationSum(nums, target);
    for(const auto& it1 : res){
        for(const auto& it2 : it1)
            cout << it2 << " ";
        cout << endl;
    }
}
