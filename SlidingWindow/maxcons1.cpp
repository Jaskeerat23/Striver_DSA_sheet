#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int longestOnes(vector<int>& nums, int k) {
        int ans = INT_MIN, n = nums.size();
        int i = 0, j = 0, cnt = 0;
        while(j < n){
            if(nums[j] == 0) cnt++;
            while(k < cnt){
                if(nums[i] == 0) cnt--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
int main(){
    int range, num, k;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        nums.push_back(num);
    }
    cout << "Ener k : ";
    cin >> k;
    cout << Solution :: longestOnes(nums, k);
}