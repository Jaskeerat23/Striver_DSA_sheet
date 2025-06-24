#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
class Solution{
public:
    static int aggressiveCows(std :: vector<int>& stalls, int k){
        std :: sort(stalls.begin(), stalls.end());
        int i = 1, ans = -1;
        while(i){
            std :: cout << "Checking for i : " << i << std :: endl;
            int cows = k - 1;
            int lastCow = stalls[0];
            for(int j = 1; j<stalls.size() && cows!=0; j++){
                if(stalls[j] - lastCow >= i){
                    std :: cout << "Condition got passed for j : " << j << std :: endl;
                    lastCow = stalls[j];
                    cows-=1;
                }
            }
            if(cows==0){
                ans = i;
            }
            else
                return ans;
            i++;
        }
        return 0;
    }
};
int main(){
    std :: vector<int> stalls;
    int range, num, k;
    std :: cout << "Enter range of stalls : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        std :: cin >> num;
        stalls.push_back(num);
    }
    std :: cout << "Enter cows : ";
    std :: cin >> k;
    int ans = Solution :: aggressiveCows(stalls, k);
    std :: cout << "Ans is " << ans << std :: endl;
}
