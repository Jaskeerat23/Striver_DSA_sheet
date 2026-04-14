#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int minDistance(string word1, string word2) {
        vector<int> dp(word2.length() + 1, 0);
        for(int i = 1; i <= word1.length(); i++) {
            vector<int> temp(word2.length() + 1, 0);
            for(int j = 1; j <= word2.length(); j++) {
                if(word1[i - 1] == word2[j - 1]) temp[j] = 1 + dp[j - 1];
                else temp[j] = max(dp[j], temp[j - 1]);
            }
            dp = temp;
        }
        return (word1.length() - dp.back()) + (word2.length() - dp.back());
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution :: minDistance(s1, s2); 
}