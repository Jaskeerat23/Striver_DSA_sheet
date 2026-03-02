#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    //Cost represent the cost it took to reach i-th index
    void DP(vector<int>& heights, int i, int cost){

        //if the current cost is greater than previously
        //found then no need to go ahead and check for 
        //possibilities we can simply return    
        if(cost >= dp[i]) return;

        dp[i] = min(cost, dp[i]);

        DP(heights, i + 1, dp[i] + abs(heights[i] - heights[i + 1]));
        DP(heights, i + 2, dp[i] + abs(heights[i] - heights[i + 2]));

    }
    

    //Space Optimization
    // int DPSO(vector<int>& height) {
    //     int cost1 = 0;
    //     int minC = -1;
    //     pair<int, int> cost2 = {0, 0};

    //     for(int i = 0; i < height.size() - 1; i++) {
    //         if(i > 1)
    //             minC = min(cost1, cost2.first);
    //         else minC = cost1;


    //         int diff1 = abs(height[i] - height[i + 1]);

    //         int diff2 = (i + 2 >= height.size()) ? 0 : abs(height[i] - height[i + 2]);

    //         cost1 = minC + diff1;
    //         cost2.first = cost2.second;
    //         cost2.second = minC + diff2;

    //     }

    //     return min(cost1, cost2.first);
    // }

    int DPSO(vector<int>& height) {
        
        int prev1 = 0, prev2 = 0;
        
        for(int i = 1; i < height.size(); i++) {
            
            int j1 = prev1 + abs(height[i] - height[i - 1]);
            int j2 = (i > 1) ? prev2 + abs(height[i] - height[i - 2]) : INT_MAX;
            
            int minC = min(j1, j2);
            
            prev2 = prev1;
            prev1 = minC;
            
        }
        return prev1;
    }

    int minCost(vector<int>& height) {
        dp.resize(height.size(), INT_MAX);

        return DPSO(height);
    }
};
int main() {
    vector<int> heights = {30, 20, 50, 10, 40};

    Solution sol;

    cout << "Min Cost is " << sol.minCost(heights) << endl;
    return 0;
}