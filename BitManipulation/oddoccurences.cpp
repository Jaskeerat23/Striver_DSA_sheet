#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static vector<int> twoOddNum(vector<int>& arr){
        int exorSeries = 0, ex1 = 0, ex2 = 0;
        for(const auto& it : arr) exorSeries^=it;

        vector<int> bucket1, bucket2;
        int diffBit = (exorSeries & (exorSeries - 1)) ^ exorSeries;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] & diffBit)
                ex1^=arr[i];
            else ex2^=arr[i];
        }
        return {ex1, ex2};
    }
};
int main(){
    int range, num;
    vector<int> arr;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        arr.push_back(num);
    }
    vector<int> ans = Solution :: twoOddNum(arr);
    cout << ans[0] << " " << ans[1] << endl;
}