#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void sort_0_1_2(vector<int>& nums){
        int low=0, mid=1, high=nums.size()-1;
        while(mid <= high){
            cout << low << mid << high << endl;
            if(nums[low]==2){
                cout << "High decremented" << endl;
                swap(nums[low], nums[high]);
                high--;
            }
            else if(nums[low]==1){
                cout << "mid incremented" << endl;
                if(nums[mid]!=1)
                    swap(nums[low], nums[mid]);
                mid++;
            }
            if(nums[low]==0){
                cout << "Mid and low both inc" << endl;
                if(nums[mid]!=2)
                    low++, mid++;
                else
                    low++;
            }
        }
    }
};
int main(){
    vector<int> nums;
    int range;
    cout << "Enter range of the element : ";
    cin >> range;
    for(int i=0; i<range; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    Solution sol;
    sol.sort_0_1_2(nums);
    for(int i : nums){ cout << i << "\t"; }
    cout << endl;
}