#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low = 0, high = nums.size() - 1, ans = INT_MAX;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                ans = min(ans, nums[mid]);
                high--, low++;
                continue;
            }

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> arr;
    int range;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << endl;
    int ans = Solution :: findMin(arr);
    cout << "Ans is : " << ans << endl;
}