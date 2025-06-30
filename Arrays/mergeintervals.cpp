#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        for(int i = 1; i<intervals.size(); i++){
            if(mergedIntervals.empty() || mergedIntervals.back()[1] < intervals[i][0]){
                mergedIntervals.push_back(intervals[i]);
            }
            else{
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
        return mergedIntervals;
    }
};
int main(){
    int activities;
    int start, end;
    vector<vector<int>> intervals;
    cout << "Enter range : ";
    cin >> activities;
    for(int i = 0; i<activities; i++){
        cout << "Enter start " << i + 1 << " : ";
        cin >> start;
        cout << "Enter end " << i + 1 << " : ";
        cin >> end;
        intervals.push_back({start, end});
    }   
    for(const auto& it : intervals){
        cout << it.at(0) << " " << it.at(1) << endl;
    }
    vector<vector<int>> result = Solution :: merge(intervals);
    cout << "Merged intervals are : " << endl;
    for(const auto& it : result){
        cout << it.at(0) << " " << it.at(1) << endl;
    }
    cout << "Result size is " << result.size() << endl;
}