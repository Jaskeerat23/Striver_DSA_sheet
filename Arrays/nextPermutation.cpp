#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static void nextPermutation(vector<int>& nums) {
        int brkIdx = nums.size()-1, max = brkIdx, size = nums.size()-1;

        //Finding the Brakpoint
        for(int i = nums.size()-2; i>-1; i--)
            if(nums[i] < nums[i+1]){
                brkIdx = i;
                break;
            }
        
        //If BreakPoint does not exist such that array is sorted
        if(brkIdx == size){
            reverse(nums.begin(), nums.end());
            return;
        }

        //Finding the smallest grater element
        for(int i = brkIdx+1; i <= size; i++){
            if(nums[i] > nums[brkIdx])
                max = i;
            if(nums[i] > nums[brkIdx] && nums[i] < nums[max])
                max = i;
        }

        //Swapping BreakPoint and smallest greater element
        swap(nums[brkIdx], nums[max]);

        //Reversing rest of the array from BreakPoint + 1 to end
        reverse(nums.begin()+brkIdx+1, nums.end());
    }
};
int main() {
    int range;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    Solution :: nextPermutation(nums);
    for(int i : nums) { cout << i << "\t"; }
    cout << endl;
}