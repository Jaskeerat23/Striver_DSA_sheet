#include<iostream>
#include<vector>
#include<deque>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        deque<pair<int, int>> dq;
        vector<int> ans;
        for(int i = 0; i<k && i<nums.size(); i++){
            while(!dq.empty() && dq.back().first < nums[i]) dq.pop_back();
            dq.push_back({nums[i], i});
        }
        ans.push_back(dq.front().first);
        for(int i = k; i < nums.size(); i++){
            if(dq.front().second <= i - k) dq.pop_front();
            while(!dq.empty() && dq.back().first < nums[i]) dq.pop_back();
            dq.push_back({nums[i], i});
            ans.push_back(dq.front().first);
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
    cout << "Enter k : ";
    cin >> k;
    vector<int> ans = Solution :: maxSlidingWindow(nums, k);
    for(const auto& it : ans) cout << it << " ";
    cout << endl;
}