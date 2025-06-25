#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
class Solution{
public:
    static std :: vector<int> searchRange(std :: vector<int>& nums, int target){
        return {lowerBound(nums, target), upperBound(nums, target)};
    }
    static int lowerBound(std :: vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int lBound = -1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(nums[mid] == target){
                lBound = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return lBound;
    }
    static int upperBound(std :: vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int uBound = -1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(nums[mid] == target){
                uBound = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return uBound;
    }
};
int main(){
    int h = 0, range;
    std :: vector<int> piles;
    std :: cout << "Enter range of array : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        std :: cin >> num;
        piles.push_back(num);
    }
    std :: cout << "Enter target : ";
    std :: cin >> h;
    std :: vector<int> k = Solution :: searchRange(piles, h);
    std :: cout << "Ans is : {" << k[0] << ", " << k[1] << "}" << std :: endl; 
}