#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int minTime(vector<int>& arr, int k) {
        int low = INT_MIN, high = 0;
        for(const auto& it : arr){
            low = max(low, it);
            high+=it;
        }
        while(low <= high){
            int mid = high - (high - low)/2;
            int paintersRequired = countPainters(arr, mid);
            if(paintersRequired <= k)
                high = mid - 1;
            else if(paintersRequired > k)
                low = mid + 1;
        }
        return low;
    }
    static int countPainters(vector<int>& arr, int timeAlloted){
        int sum = arr[0], painters = 1;
        for(int i = 1; i<arr.size(); i++){
            if(sum + arr[i] > timeAlloted){
                sum = arr[i];
                painters++;
            }
            else
                sum+=arr[i];
        }
        return painters;
    }
};
int main(){
    //Main is copied from aggressivecows.cpp

    std :: vector<int> stalls;
    int range, num, k;
    std :: cout << "Enter range of pages : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        std :: cin >> num;
        stalls.push_back(num);
    }
    std :: cout << "Enter children : ";
    std :: cin >> k;
    int ans = Solution :: minTime(stalls, k);
    std :: cout << "Ans is " << ans << std :: endl;
}
