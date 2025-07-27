#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool isPossible(vector<string>& currPlacements, vector<bool>& occCols, int idx, int n){
        //Checking for column overlap
        if(occCols[idx]) return false;
        int  i, j;
        //Checking if any left diagonal element is occupied
        i = currPlacements.size() - 1;
        j = idx - 1;
        for(i, j; i>=0 && j>=0; i--, j--){
            if(currPlacements[i][j] == 'Q') return false;
        }
        //Checking if any right diagonal element is occupied
        i = currPlacements.size() - 1;
        j = idx + 1;
        for(i, j; i>=0 && j < n; i--, j++){
            if(currPlacements[i][j] == 'Q') return false;
        }
        return true;
    }
    static void placeQueens(int& cnt, vector<string>& currPlacement, vector<bool>& occCols, int NthQueen, int n){
        if(NthQueen == n){
            cnt++;
            return;
        }
        string currStr(n, '.');
        for(int i = 0; i<n; i++){
            if(isPossible(currPlacement, occCols, i, n)){
                currStr[i] = 'Q';
                occCols[i] = true;
                currPlacement.push_back(currStr);
                placeQueens(cnt, currPlacement, occCols, NthQueen + 1, n);
                currStr[i] = '.';
                occCols[i] = false;
                currPlacement.pop_back();
            }
        }
    }
    static int solveNQueens(int n) {
        int res = 0;
        vector<string> currPlacement;
        vector<bool> occCols(n ,false);
        placeQueens(res, currPlacement, occCols, 0, n);
        return res;
    }
};
int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    int res = Solution :: solveNQueens(n);
    cout << "Ans is : " << res << endl;
}