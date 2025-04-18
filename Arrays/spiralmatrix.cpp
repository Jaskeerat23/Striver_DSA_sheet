#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_min = 0, col_min = 0, row_max = matrix.size(), col_max = matrix[0].size();
        int dir = 0, i = 0, j = 0, idx = 0, m = row_max, n = col_max;
        vector<int> result;
        while(idx != n*m){
            //Loop for horizontal traversing (l->r or r->l)
            while((dir == 0 && j < col_max) || (dir == 2 && j >= col_min)){
                result.push_back(matrix[i][j]);
                j = (dir == 0) ? j+1 : j-1;
                idx+=1;
            }
            // cout << "After horizontal traversing j is : " << j << endl;
            if(dir == 0)
                j-=1, i+=1;
            else if(dir == 2)
                j+=1, i-=1;
            //Loop for vertical traversing (b->up or up->bottom)
            while((dir == 1 && i < row_max) || (dir == 3 && i > row_min)){
                result.push_back(matrix[i][j]);
                i = (dir == 1) ? i+1 : i-1;
                idx+=1;
            }
            // cout << "After vertical traversing i is : " << i << endl;
            if(dir == 1)
                i-=1, j-=1;
            else if(dir == 3)
                i+=1, j+=1;
            switch(dir) {
                case 0 : dir = 1, col_max-=1; break;
                case 1 : dir = 2, row_max-=1; break;
                case 2 : dir = 3, col_min+=1; break;
                case 3 : dir = 0, row_min+=1; break;
            }
        }
        return result;
    }
};
int main() {
    int r, c;
    vector<vector<int>> matrix;
    cout << "Enter rows : ";
    cin >> r;
    cout << "Enter columns : ";
    cin >> c;
    for(int i = 0; i<r; i++){
        vector<int> row;
        for(int j = 0; j<c; j++){
            int num;
            cin >> num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    cout << "Provided matrix is : " << endl;
    for(vector<int> i : matrix) {
        for(int j : i)
            cout << j << "\t";
        cout << endl;
    }
    vector<int> result = Solution :: spiralOrder(matrix);
    cout << "Matrix in sprial manner is : " << endl;
    for(int i : result) { cout << i << "\t"; }
}