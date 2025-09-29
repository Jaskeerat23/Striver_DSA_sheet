/*
We will be using traditional sliding window approach because
since it asks EXACTLY K, but we don't have to count no. of subarrays
so we can use traditional sliding window approach here
*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static int longestKSubstr(string& s, int k){
        int i = 0, j = 0, uniqueChars = 0, ans = -1;
        vector<int> mapp(52, 0);
        while(j < s.length()){
            
            if(mapp[s[j] - 'a'] == 0){
                
                uniqueChars+=1;
                
                while(uniqueChars > k){
                    mapp[s[i] - 'a']-=1;
                    if(mapp[s[i] - 'a'] == 0) uniqueChars-=1;
                    i++;
                }
            }
            
            mapp[s[j] - 'a']+=1;
            (uniqueChars >= k)? ans = max(ans, (j - i + 1)) : INT_MIN;
            j++;

        }
        return ans;
    }
};
int main() {
    string s;
    int k;
    cout << "Enter string : ";
    cin >> s;
    cout << "Enter k : ";
    cin >> k;
    cout << Solution :: longestKSubstr(s, k);
}