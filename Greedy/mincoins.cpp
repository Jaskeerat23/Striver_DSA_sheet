#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static vector<int> minPartition(int N) {
        // code here
        vector<int> ans, notes = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        int i = notes.size() - 1;
        while(N>0){
            int noOfNotes = floor(N/notes[i]);
            // cout << notes[i] << " " << noOfNotes << " is required\n";
            for(int j = 0; j<noOfNotes; j++)
                ans.push_back(notes[i]);
            N = N%notes[i];
            i--;
        }
        return ans;
    }
};
int main(){
    int N;
    cout << "Enter N : ";
    cin >> N;
    vector<int> ans = Solution :: minPartition(N);
    for(const auto& it : ans) cout << it << " ";
    cout << endl;
}