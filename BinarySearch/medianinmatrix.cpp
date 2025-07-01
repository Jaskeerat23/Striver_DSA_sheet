#include<iostream>
#include<vector>
#include<bits/stdc++.h>
class Solution{
public:
    static int median(std :: vector< std :: vector<int>>& mat){
        int m = mat.size(), n = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        int threshold = (m * n)/2;
        std :: cout << "m = " << m << " n = " << n << std :: endl;
        for(int i = 0; i<n; i++){
            low = std :: min(mat[0][i], low);
            high = std :: max(mat[n - 1][i], high);
        }
        std :: cout << "Threshold is " << threshold << std :: endl;
        std :: cout << "low is " << low << std :: endl;
        std :: cout << "high is " << high << std :: endl;
        while(low <= high){
            int mid = high - (high - low)/2;
            int lessThanMid = applyUpperBoundRows(mat, mid);
            if(lessThanMid > threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    static int applyUpperBoundRows(std :: vector< std :: vector<int>>& mat, int k){
        int lessThank = 0;
        for(int i = 0; i<mat.size(); i++){
            lessThank+=applyUpperBound(mat[i], k);
        }
        return lessThank;
    }
    static int applyUpperBound(std :: vector<int>& arr, int k){
        int low = 0, high = arr.size() - 1, ans = -1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(arr[mid] > k){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return (ans == -1)? arr.size() : ans;
    }
};
int main(){
    std :: vector< std :: vector<int>> mat;
    int r, c, num;
    std :: cout << "Enter rows : ";
    std :: cin >> r;
    std :: cout << "Enter columns : ";
    std :: cin >> c;
    for(int i = 0; i<r; i++){
        std :: vector<int> temp;
        for(int j = 0; j<c; j++){
            std :: cin >> num;
            temp.push_back(num);
        }
        mat.push_back(temp);
    }
    int median = Solution :: median(mat);
    std :: cout << "Median is " << median << std :: endl;
}