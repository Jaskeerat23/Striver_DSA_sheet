#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<vector<int>> meetings;
        for(int i = 0; i<start.size(); i++){
            meetings.push_back({end[i], start[i]});
        }
        // cout << "printing sorted meetings : " << endl;
        // for(const auto& it : meetings){
        //     for(const auto& i : it) cout << i << " ";
        //     cout << endl;
        // }
        sort(meetings.begin(), meetings.end());
        int l = INT_MAX, r = meetings[0][0], n = 1;
        for(int i = 1; i<start.size(); i++){
            //If ending range is greater than the start time of another meeting
            //Meeting cannot be conducted
            if(r < meetings[i][1]){
                n++;
                r = max(r, meetings[i][0]);
            }
        }
        return n;
    }
};
