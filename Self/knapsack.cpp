#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static int knapsack(int W, vector<int>& val, vector<int>& wt){
        vector<vector<double>> p_w;
        double maxProfit = 0;
        for(int i = 0; i<val.size(); i++)
            p_w.push_back({(double)val[i]/wt[i], (double)val[i], (double)wt[i]});
        sort(p_w.begin(), p_w.end());
        reverse(p_w.begin(), p_w.end());
        cout << "profit weight ratio\tprofit\tweight" << endl;
        for(int i = 0; i<p_w.size(); i++){
            cout << p_w[i][0] << "\t\t\t" << p_w[i][1] << "\t" << p_w[i][2] << endl;
        }
        for(int i = 0; i<p_w.size(); i++){
            if(W < p_w[i][2]){   // If weight left is less than weight of the current obj then break
                maxProfit+=p_w[i][1]/p_w[i][2] * W;
                break;
            }
            else{
                maxProfit+=p_w[i][1];
                W-=p_w[i][2];    //Subtract the weigth of current selected obj from max capacity
            }
            cout << "Weight left " << W << endl;
        }
        return maxProfit;
    }
};
int main(){
    int range, W;
    vector<int> val, wt;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int weight;
        cout << "Enter weight : ";
        cin >> weight;
        wt.push_back(weight);
    }
    for(int i = 0; i<range; i++){
        int profit;
        cout << "Enter profit : ";
        cin >> profit;
        val.push_back(profit);
    }
    cout << "Enter max weight of knapsack : ";
    cin >> W;
    int profit = Solution :: knapsack(W, val, wt);
    cout << "profit is : " << profit << endl;
}