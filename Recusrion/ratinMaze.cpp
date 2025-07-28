#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void traversePathforRat(vector<vector<int>>& maze, vector<vector<bool>>& currPath, vector<string>& paths, string path, int i, int j){
        
        // cout << "checking function\n";

        if(i == maze.size() - 1 && j == maze.size() - 1){
            paths.push_back(path);
            return;
        }

        //Checking the Cell Below
        if(i + 1 < maze.size() && !currPath[i + 1][j] && maze[i + 1][j]){
            // cout << "Below Neighbour\n";
            path+='D';
            currPath[i + 1][j] = true;
            traversePathforRat(maze, currPath, paths, path, i + 1, j);
            path.pop_back();
            currPath[i + 1][j] = false;
        }
        
        //Checking the Left Cell
        if(j - 1 >= 0 && !currPath[i][j - 1] && maze[i][j - 1]){
            // cout << "Left Neighbour\n";
            path+='L';
            currPath[i][j - 1] = true;
            traversePathforRat(maze, currPath, paths, path, i, j - 1);
            path.pop_back();
            currPath[i][j - 1] = false;
        }
        
        //Checking the Right Cell
        if(j + 1 < maze.size() && !currPath[i][j + 1] && maze[i][j + 1]){
            // cout << "Right Neighbour\n";
            path+='R';
            currPath[i][j + 1] = true;
            traversePathforRat(maze, currPath, paths, path, i, j + 1);
            path.pop_back();
            currPath[i][j + 1] = false;
        }

        //Checking the Cell Above
        if(i-1 >= 0 && !currPath[i - 1][j] && maze[i - 1][j]){
            // cout << "Above Neighbour\n";
            path+='U';
            currPath[i - 1][j] = true;
            traversePathforRat(maze, currPath, paths, path, i - 1, j);
            path.pop_back();
            currPath[i - 1][j] = false;
        }
    }
    static vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<vector<bool>> currPath(n, vector<bool>(n, false));
        vector<string> paths;
        string path = "";
        currPath[0][0] = true;
        traversePathforRat(maze, currPath, paths, path, 0, 0);
        // sort(paths.begin(), paths.end());
        return paths;
    }
};
int main(){
    vector<vector<int>> matrix;
    int r, c;
    cout << "Enter r : ";
    cin >> r;
    cout << "Enter c : ";
    cin >> c;
    for(int i = 0; i < r; i++){
        vector<int> temp;
        for(int j = 0; j<c; j++){
            int charT;
            cin >> charT;
            temp.push_back(charT);
        }
        matrix.push_back(temp);
    }
    vector<string> ans = Solution :: ratInMaze(matrix);
    for(const auto& it : ans) cout << it << endl;
}