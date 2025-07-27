#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct hashFunction{
    size_t operator()(const vector<int>& vec) const{
        hash<int> hasher;
        size_t answer = 0;
        for(const auto it : vec){
            answer^=hasher(it) + 0x9e3779b9 + (answer << 6) + (answer >> 3);
        }
        return answer;
    }
};
class Solution{
public:
    static void traversePath(vector<vector<char>>& matrix, vector<vector<bool>>& currPath, string str, int idx, int i, int j, bool& doesExist){
        if(idx == str.length()) {
            doesExist = true;
            return;
        }
        cout << "In the checking function\n";
        //Checking the RIGHT neighbour
        if(!doesExist && i<matrix.size() && j + 1<matrix[0].size() && currPath[i][j + 1] == 0 && matrix[i][j + 1] == str[idx]){
            cout << "i is : " << i << endl;
            cout << "j is : " << j << endl;
            cout << "LEFT NEIGHBOUR FOUND" << matrix[i][j + 1] << endl;
            currPath[i][j + 1] = true;
            traversePath(matrix, currPath, str, idx+1, i, j + 1, doesExist);
            currPath[i][j + 1] = false;
        }

        //Checking the LEFT neighbour
        if(!doesExist && i<matrix.size() && j-1>=0 && currPath[i][j - 1] == false && matrix[i][j - 1] == str[idx]){
            cout << "i is : " << i << endl;
            cout << "j is : " << j << endl;
            cout << "LEFT NEIGHBOUR FOUND" << matrix[i][j - 1] << endl;
            currPath[i][j - 1] = true;
            traversePath(matrix, currPath, str, idx+1, i, j - 1, doesExist);
            currPath[i][j - 1] = false;
        }

        //Checking the UPPER neighbour
        if(!doesExist && i-1>=0 && j<matrix[0].size() && currPath[i - 1][j] == false && matrix[i - 1][j] == str[idx]){
            cout << "i is : " << i << endl;
            cout << "j is : " << j << endl;
            cout << "UPPER NEIGHBOUR FOUND" << matrix[i - 1][j] << endl;
            currPath[i - 1][j] = true;
            traversePath(matrix, currPath, str, idx+1, i - 1, j, doesExist);
            currPath[i - 1][j] = false;
        }

        //Checking the BELOW neighbour
        if(!doesExist && i + 1<matrix.size() && j<matrix[0].size() && currPath[i + 1][j] == false && matrix[i + 1][j] == str[idx]){
            cout << "i is : " << i << endl;
            cout << "j is : " << j << endl;
            cout << "BELOW NEIGHBOUR FOUND" << matrix[i + 1][j] << endl;
            currPath[i + 1][j] = true;
            traversePath(matrix, currPath, str, idx+1, i + 1, j, doesExist);
            currPath[i + 1][j] = false;
        }
    }
    static bool exist(vector<vector<char>>& matrix, string str){
        bool doesExist = false;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<bool>> currPath(r, vector<bool>(c, false));
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == str[0]){
                    currPath[i][j] = true;
                    traversePath(matrix, currPath, str, 1, i, j, doesExist);
                    currPath[i][j] = false;
                }
                if(doesExist) return doesExist;
            }
        }
        return doesExist;
    }
};
int main(){
    vector<vector<char>> matrix;
    string word;
    int r, c;
    cout << "Enter r : ";
    cin >> r;
    cout << "Enter c : ";
    cin >> c;
    for(int i = 0; i < r; i++){
        vector<char> temp;
        for(int j = 0; j<c; j++){
            char charT;
            cin >> charT;
            temp.push_back(charT);
        }
        matrix.push_back(temp);
    }
    cout << "Enter word : ";
    cin >> word;
    bool ans = Solution :: exist(matrix, word);
    cout << "Answer is " << boolalpha << ans << endl;
}