#include<iostream>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static vector<vector<int>> pascalTriangle(int numRows){
        vector<vector<int>> res;
        for(int i = 0; i<numRows; i++){
            vector<int> ans;
            ans.push_back(1);
            for(int j = 1; j<=i-1; j++){
                ans.push_back(res[i-1][j] + res[i-1][j-1]);
            }
            if(i>0)
                ans.push_back(1);
            res.push_back(ans);
        }
        return res;
    }
};
int main(){
    int numRows;
    cout << "Enter range : ";
    cin >> numRows;
    vector<vector<int>> res = Solution :: pascalTriangle(numRows);
    for(vector<int> vec : res){
        for(int i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
}