#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
class Solution{
public:
    //Brute Force O(N^2) S.C. O(1)
    static int maxProduct1(std :: vector<int>& nums){
        int res = INT_MIN, runningProd = INT_MIN, negProd = INT_MIN;
        int ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            int currMax = INT_MIN, prod = 1;
            for(int j = i; j<nums.size(); j++){
                prod*=nums[j];
                currMax = std :: max(currMax, prod);
            }
            ans = std :: max(ans, currMax);
        }
        return ans;
    }
    //Optimal Solution O(N), S.C. O(1)
    static int maxProduct2(std :: vector<int>& nums){
        int pre = 1, suff = 1;
        int maxProd = INT_MIN;
        for(int i = 0, j = nums.size() - 1; i<nums.size() && j>=0; i++, j--){
            if(!pre) pre = 1;
            if(!suff) suff = 1;
            pre*=nums[i];
            suff*=nums[j];
            maxProd = std :: max({pre, suff, maxProd});
        }
        return maxProd;
    }
};
int main(){
    int range, num;
    std :: vector<int> nums;
    std :: cout << "Enter range : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        std :: cin >> num;
        nums.push_back(num);
    }
    int ans = Solution :: maxProduct2(nums);
    std :: cout << "Ans is " << ans << std :: endl;
}