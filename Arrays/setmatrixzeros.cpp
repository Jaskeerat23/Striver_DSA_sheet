#include<iostream>
#include<unordered_map>
#include<vector>
#include<iterator>
using namespace std;
class Solution {
public:
    //APPROACH 1 : BRUTE-FORCE T.C. - O(N X M) | S.C. - O(N X M)
    static void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> r, c;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i<matrix.size(); i++)
            for(int j = 0; j<matrix[i].size(); j++)
                if(matrix[i][j] == 0){
                    r.insert({i, 1});
                    c.insert({j, 1});
                }
        for(auto it = r.begin(); it!=r.end(); it++)
            for(int i = 0; i<cols; i++)
                matrix[it->first][i] = 0;
        for(auto it = c.begin(); it!=c.end(); it++)
            for(int i = 0; i<rows; i++)
                matrix[i][it->first] = 0;
    }
    //APPROACH 2 : BETTER : T.C. O(N X M) | S.C(N x M)
    static void setZeroes_1(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(rows[i] || cols[j])
                    matrix[i][j] = 0;
    }
};
int main(){
    int rows, cols;
    vector<vector<int>> matrix;
    cout << "Enter rows : ";
    cin >> rows;
    cout << "Enter columns : ";
    cin >> cols;
    for(int i = 0; i<rows; i++){
        vector<int> temp;
        for(int j = 0; j<cols; j++){
            int num;
            cin >> num;
            temp.push_back(num);
        }
        matrix.push_back(temp);
    }
    cout << "Provided matrix is : " << endl;
    for(vector<int> i : matrix){
        for(int j : i){
            cout << j << "\t";
        }
        cout << endl;
    }
    Solution :: setZeroes_1(matrix);
    cout << "Modified matrix is : " << endl;
    for(vector<int> i : matrix){
        for(int j : i){
            cout << j << "\t";
        }
        cout << endl;
    }
}