#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int largestRectangle(vector<int>& heights){
    int n = heights.size();
    stack<pair<int, int>> s1, s2;
    vector<int> left(n), right(n);

    for(int i = 0; i<heights.size(); i++){
        int cnt = 0;
        while(!s1.empty() && s1.top().first > heights[i]){
            cnt+=s1.top().second;
            s1.pop();
        }
        cnt++;
        s1.push({heights[i], cnt});
        left[i] = cnt;
    }


    for(int i = n - 1; i >= 0; i--){
        int cnt = 0;
        while(!s2.empty() && s2.top().first >= heights[i]){
            cnt+=s2.top().second;
            s2.pop();
        }
        cnt++;
        s2.push({heights[i], cnt});
        right[i] = cnt;
    }

    int maxA = INT_MIN;
    for(int i = 0; i<n ; i++){
        int cand = heights[i] * (left[i] + right[i] - 1);
        maxA = max(maxA, cand);
    }
    return maxA;
}
int main(){
    int range, num;
    vector<int> heights;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        heights.push_back(num);
    }
    int ans = largestRectangle(heights);
    cout << "ans is : " << ans;
}
