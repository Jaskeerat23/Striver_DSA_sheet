#include<iostream>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    /* BRUTE FORCE METHOD : TIME COMPLEXITY O(N) SPACE COMPLEXITY O(N) */
    static int removeDuplicates(vector<int>& nums){
        vector<int> temp;
        temp.push_back(nums[0]);
        int key = nums[0], j = 1;
        cout << "Size is " << nums.size() << endl;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]!=key){
                temp.push_back(nums[i]);
                key = nums[i];
            }
        }
        for(int i=0; i<temp.size(); i++)
            nums[i] = temp[i];
        cout << "Temp size is " << temp.size() <<  endl;
        return temp.size();
    }
    /* OPTIMAL METHOD : TIME COMPLEXITY O(N) SPACE COMPLEXITY O(1) */
    static int removeDuplicates(vector<int>& nums){
        int key = nums[0], j = 1;
        for(int i = 1; i<nums.size(); i++)
            if(nums[i]!=key){
                nums[j] = nums[i];
                key = nums[i];
                j++;
            }
        return j;
    }
};
int main(){
    vector<int> nums;
    int range;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0 ; i < range; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << "Provided array is : " << endl;
    for(int i : nums){ cout << i << " "; }
    int size = Solution :: removeDuplicates(nums);
    for(int i = 0; i<size; i++)
        cout << nums[i] << " ";
}