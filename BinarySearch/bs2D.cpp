#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
class Solution{
public:
    static bool searchMatrix(std :: vector< std :: vector<int>>& matrix, int target){
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(matrix[mid][0] <= target && matrix[mid][n - 1] >= target)
                return applyBS(matrix[mid], target);
            else if(matrix[mid][0] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    static bool applyBS(std :: vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};
int main(){
    int r, c, num, target;
    std :: vector< std :: vector <int>> nums;
    std :: cout << "Enter rows : ";
    std :: cin >> r;
    std :: cout << "Enter columns : ";
    std :: cin >> c;
    for(int i = 0; i<r; i++) {
        std :: vector<int> temp;
        for(int j = 0; j<c; j++) {
            std :: cin >> num;
            temp.push_back(num);
        }
        nums.push_back(temp);
    }
    std :: cout << "Enter target : ";
    std :: cin >> target;
    bool ans = Solution :: searchMatrix(nums, target);
    std :: cout << "Answer is " << ans << std :: endl;
}