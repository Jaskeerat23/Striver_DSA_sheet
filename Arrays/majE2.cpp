#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static vector<int> majorityElement(vector<int>& nums) {
        int sum1=1, sum2=0, i = 1, brk = -1;
        int maj1=nums[0], maj2=INT_MIN;
        for(i = 1; i<nums.size(); i++){
            if(nums[i] != maj1){
                maj2 = nums[i];
                brk = i;
                sum2 = 1;
                break;
            }
        }
        cout << "Maj 1 " << maj1 << " maj 2 " << maj2 << endl;
        cout << "brk is " << brk << endl;
        for(int j = 1; j < nums.size(); j++){
            if(brk == j)
                continue;
            if(nums[j] == maj1)
                sum1++;
            else if(nums[j] == maj2)
                sum2++;
            else{
                if(sum1 <= 0){
                    sum1 = 1;
                    maj1 = nums[j];
                }
                else if(sum2 <= 0){
                    sum2 = 1;
                    maj2 = nums[j];
                }
                else{
                    sum1--;
                    sum2--;
                }
            }
        }
        int count1 = 0, count2 = 0, threshold = floor(nums.size()/3);
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == maj1)
                count1++;
            else if(nums[i] == maj2)
                count2++;
        }
        cout << "Maj 1 " << maj1 << " maj 2 " << maj2 << endl;
        if(count1 > threshold && count2 > threshold)
            return {maj1, maj2};
        else if(count1 > threshold)
            return {maj1};
        else if(count2 > threshold)
            return {maj2};
        return {};
    }
};
int main(){
    int range, num;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        nums.push_back(num);
    }
    vector<int> answer = Solution :: majorityElement(nums);
    cout << answer[0] << " " << answer[1] << endl;
}