#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Solution{
public:
    static int exploreRect(vector<vector<char>>& matrix, int x, int y){
        int minOnesRows = INT_MAX, onesCols = 0, ans = 0;
        for(y; y < matrix[0].size(); y++){
            int cnt = 0;
            if(matrix[x][y] != '1') break;
            onesCols++;
            for(int i = x; i < matrix.size(); i++){
                if(matrix[i][y] != '1') break;
                cnt++;
            }
            minOnesRows = min(minOnesRows, cnt);
            ans = max(ans, onesCols * minOnesRows);
        }
        return ans;
    }
    static int maximalRectangle(vector<vector<char>>& matrix){
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1') {
                    ans = max(ans, exploreRect(matrix, i, j));
                }
            }
        }
        return ans;
    }
};
int main(){
    int r, c;
    vector<vector<char>> matrix;
    cout << "Enter r : ";
    cin >> r;
    cout << "Enter c : ";
    cin >> c;
    for(int i = 0; i<r; i++){
        vector<char> temp;
        char ch;
        for(int j = 0; j<c; j++){
            cin >> ch;
            temp.push_back(ch);
        }
        matrix.push_back(temp);
    }
    int ans = Solution :: maximalRectangle(matrix);
    cout << "ans is " << ans << endl;
}