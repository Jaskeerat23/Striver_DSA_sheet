#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
class Solution{
public:
    static int shipWithDays(std :: vector<int>& weights, int days){
        int low = INT_MIN, high = 0;
        for(const int& i : weights){
            high+=i;
            low = std :: max(low, i);
        }
        while(low <= high){
            std :: cout << "High is " << high << "Low is " << low << std :: endl;
            int mid = high - (high - low)/2;
            if(check(weights, days, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    static bool check(std :: vector<int>& weights, int& days, int& wtAllowed){
        int sum = 0, daysNeeded = 1, i = 0;
        while(i < weights.size()){
            if(sum + weights[i] > wtAllowed){
                sum = 0;
                daysNeeded++;
            }
            else{
                sum+=weights[i];
                i++;
            }
        }
        if(daysNeeded <= days)
            std :: cout << "Conditioned passed for wt " << wtAllowed << std :: endl;
        std :: cout << "Days needed is " << daysNeeded << std :: endl;
        return daysNeeded <= days;
    }
};
int main(){
    int h = 0, range;
    std :: vector<int> weights;
    std :: cout << "Enter range : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        std :: cin >> num;
        weights.push_back(num);
    }
    std :: cout << "Enter days : ";
    std :: cin >> h;
    int k = Solution :: shipWithDays(weights, h);
    std :: cout << "Min weight needed is " << k << std :: endl;
}