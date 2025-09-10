#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
    //Brute force
    static int numberOfSubstrings(string s){
        int cnt = 0;
        for(int i = 0; i<s.length(); i++){
            int j = i;
            bool a = false, b = false, c = false;
            for(j; j<s.length(); j++){
                if(s[j] == 'a') a = true;
                if(s[j] == 'b') b = true;
                if(s[j] == 'c') c = true;
                if(a && b && c){
                    // cnt++;
                    cout << "inner for broke at " << j << endl;
                    break;
                }
            }
            int subArrayRem = (s.length() - j);
            cout << "After " << j << " adding " << subArrayRem << " remaining subarrays\n";
            cnt+=subArrayRem;
        }
        return cnt;
    }
    //Optimal
    static int numberOfSubStrings2(string s){
        class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, ans = 0, n = s.length();
        vector<int> cnts = {0, 0, 0};
        while(j < n){
            cnts[s[j] - 'a']+=1;
            if(i < j && cnts[0] > 0 && cnts[1] > 0 && cnts[2] > 0){
                while(cnts[0] > 0 && cnts[1] > 0 && cnts[2] > 0){
                    ans+=(n - j);
                    cnts[s[i] - 'a']-=1;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
    }
};
int main(){
    string s;
    cout << "Enter string : ";
    cin >> s;
    int ans = Solution :: numberOfSubStrings2(s);
    cout << ans << endl;
}