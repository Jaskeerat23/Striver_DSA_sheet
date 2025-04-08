#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution{
public:
    static int longestSubarray(vector<int>& arr, int k){
        vector<int> prefixSum;
        unordered_map<int, int> indices;
        int length = INT_MIN, sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];
            prefixSum.push_back(sum);
            if(indices[sum]==0)
                indices[sum] = i+1;
        }
        for(int i : prefixSum) { cout << i << " "; }
        cout << endl;
        for(int i  = 0; i<arr.size(); i++) { cout << indices[prefixSum[i]] << " "; }
        cout << endl;
        for(int i = 0; i<arr.size(); i++){
            int diff = prefixSum[i] - k;
            if(indices[diff]!=0){
                length = (i - (indices[diff]-1) > length) ? i - (indices[diff]-1) : length;
            }
            else if(diff==0){
                length = (i > length) ? i : length;
            }
        }
        if(length == INT_MIN)
            return 0;
        return length+1;
    }
};
int main(){
    vector<int> arr;
    int range, k;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << "Enter k : ";
    cin >> k;
    int ans = Solution :: longestSubarray(arr, k);
    cout << "Length is " << ans;
}
