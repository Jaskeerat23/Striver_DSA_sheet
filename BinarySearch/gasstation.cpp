#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double low = 0, high = FLT_MIN, ans = -1;
        for(int i = 1; i<stations.size(); i++){
            high = std :: max(high, (double)stations[i] - stations[i-1]);
        }
        while(high - low > 1e-6){
            double mid = high - (high - low)/2;
            int stationsPlaced = check(stations, k, mid);
            if(stationsPlaced <= k){
                ans = mid;
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return high;
    }
    static int check(std :: vector<int>& stations, int k, double maxPosDist){
        int stationsPlaced = 0, i = 1;
        while(i < stations.size()){
            int inbetween = (stations[i] - stations[i - 1])/maxPosDist;
            if((stations[i] - stations[i - 1]) == (maxPosDist * inbetween))
                inbetween--;
            stationsPlaced+=inbetween;
            i++;
            }
            return stationsPlaced;
        }
};
int main(){
    std :: vector<int> stalls;
    int range, num, k;
    std :: cout << "Enter range of stations : ";
    std :: cin >> range;
    for(int i = 0; i<range; i++){
        std :: cin >> num;
        stalls.push_back(num);
    }
    std :: cout << "Enter new stations : ";
    std :: cin >> k;
    double ans = Solution :: findSmallestMaxDist(stalls, k);
    std :: cout << "Ans is " << ans << std :: endl;
}