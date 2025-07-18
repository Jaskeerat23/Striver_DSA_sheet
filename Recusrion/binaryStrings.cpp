#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static void generate(vector<string>& res, string currBin, int n){
        // cout << "Entered function" << endl;
        if(n >= currBin.length()){
            res.push_back(currBin);
            return;
        }
        if(n==0 || (n - 1 >= 0 && currBin[n-1] != '0')){
            currBin[n] = '0';
            generate(res, currBin, n + 1);
        }
        currBin[n] = '1';
        generate(res, currBin, n + 1);
    }

    static vector<string> generateBinaryStrings(int num){
        vector<string> res, finalRes;
        string currBin(num, '0');
        // for(int i = 0; i<num; i++) currBin;
        cout << "initial string : " << currBin << endl;
        generate(res, currBin, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    int range;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    vector<string> ans = Solution :: generateBinaryStrings(range);
    for(const auto& it1 : ans){
        cout << it1;
        cout << endl;
    }
}