#include<iostream>
#include<vector>
#include<bits/stdc++.h>
class Solution{
public:
    static int minEatingSpeed(std::vector<int>& piles, int h){
        int high = INT_MIN, low = 1, k=-1, ans, sum = 0;
        for(const int& i : piles){
            high = std::max(i, high);
            // sum+=i;
        }
        while(low <= high){
            k = high - (high - low)/2;
            bool ch = check(piles, h, k);
            if(ch){
                ans = k;
                high = k - 1;
            }
            else
                low = k + 1;
            std :: cout << "High is " << high << " low is " << low << std :: endl;
        }
        return ans;
    }
    static bool check(std::vector<int>& piles, const int& h, const int& k){
        long long time = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > k)
                time+=ceil(piles[i]/(double)k);
            else    
                time+=1;
        }
        return time <= h;
    }
};
int main(){
    int h = 0, range;
    std :: vector<int> piles;
    std :: cout << "Enter range of piles : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        std :: cin >> num;
        piles.push_back(num);
    }
    std :: cout << "Enter hours : ";
    std :: cin >> h;
    int k = Solution :: minEatingSpeed(piles, h);
    std :: cout << "Min Speed is " << k << " banana/hr" << std :: endl;
}