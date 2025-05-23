#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:


//APPROACH 1(BRUTE-FORCE) : Linear Search T.C. = (max - min) * O(n)
    static int findMin(vector<int>& bloomday, int m, int k){
        int high = INT_MIN, low = INT_MAX, size = bloomday.size();
        if(size < m*k) return -1;
        for(int i : bloomday){
            high = max(i, high);
            low = min(i, low);
        }
        cout << "Min is : " << low << endl;
        cout << "Max is : " << high << endl;
        for(int i = low; i <= high; i++){
            int bouquets = 0, count = 0;
            for(int j = 0; j<size; j++){
                if(bloomday[j] <= i)
                count++;
                else{
                    bouquets+=count/k;
                    count = 0;
                }
            }
            bouquets+=count/k;
            cout << "Bouquets are : " << bouquets << endl;
            if(bouquets >= m)
            return i;
        }
        return -1;
    }
    
    //APPROACH 2(OPTIMIZED) : Binary Search
    static int findMin2(vector<int>& bloomday, int m, int k){
        int high = INT_MIN, low = INT_MAX, size = bloomday.size(), ans = -1;
        if(size < m*k) return -1;
        for(int i : bloomday){
            high = max(i, high);
            low = min(i, low);
        }
        while(low <= high){
            int mid = high - (high - low)/2;
            if(possible(bloomday, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else
            low = mid + 1;
        }
        return ans;
    }
    //HELPER FUNCTION to find if it is possible at this day
    static bool possible(vector<int>& bloomday, int m, int k, int day){
        int bouquets = 0, count = 0;
            for(int j = 0; j<bloomday.size(); j++){
                if(bloomday[j] <= day)
                    count++;
                else{
                    bouquets+=count/k;
                    count = 0;
                }
            }
            bouquets+=count/k;
            return bouquets >= m;
    }
};
int main(){
    int range, m, k;
    vector<int> bloomday;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        bloomday.push_back(num);
    }
    cout << "Provivded array is : " << endl;
    for(int i : bloomday)
        cout << i << " ";
    cout << endl;
    cout << "Enter m bouquets : ";
    cin >> m;
    cout << "Enter k adjacent flowers : ";
    cin >> k;
    int ans = Solution :: findMin2(bloomday, m, k);
    cout << "Ans is : " << ans << endl;
}