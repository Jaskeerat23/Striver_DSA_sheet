#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using  namespace std;
class Solution{
public:
    static int lowerbound(vector<int>& nums, int target){
        int high = nums.size()-1, low = 0, lbound = nums.size();
        while(low<=high){
            int mid = high - (high - low)/2;
            if(nums[mid] == target){
                high = mid - 1;
                lbound = mid;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else if(nums[mid] > target){
                high = mid - 1;
                lbound = mid;
            }
        }
        return lbound;
    }
};
int main(){
    vector<int> arr;
    int range, target;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        // cout << num << "\t";
        arr.push_back(num);
    }
    cout << endl;
    cout << "Enter target : ";
    cin >> target; 
    int ans = Solution :: lowerbound(arr, target);
    cout << "Ans is : " << ans << endl;
}