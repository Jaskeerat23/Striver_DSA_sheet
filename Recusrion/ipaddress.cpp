#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string integerInBW){
    if(integerInBW.front() == '0' && integerInBW.length() > 1 || integerInBW.length() > 3) return false;
        return stoi(integerInBW) <= 255;
    }
    void traversePossiblePaths(string s, string currIp, vector<string>& validIPs, int start, int dots){
        if(!dots){
            string str = s.substr(start);
            if(str.length() && isValid(str)) {
                currIp+=str;
                validIPs.push_back(currIp);
                cout << currIp << endl;
            }
            return;
        }
        int end = start + 3;
        string integerInBW = "";
        for(int i = start; i < s.length() && i < end; i++){
            integerInBW+=s[i];
            if(isValid(integerInBW)){
                int len = currIp.length();
                currIp+=integerInBW + ".";
                traversePossiblePaths(s, currIp, validIPs, i + 1, dots - 1);
                currIp.resize(len);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() < 4) return {};
        string currIp;
        vector<string> validIPs;
        traversePossiblePaths(s, currIp, validIPs, 0, 3);
        return validIPs;
    }
};
int main(){
    string s;
    cout << "Enter IP string : ";
    cin >> s;
    Solution sol;
    sol.restoreIpAddresses(s);
}