#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static bool checkValidString(string s){
        int minR = 0, maxR = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                minR++, maxR++;
            }
            else if(s[i] == ')'){
                minR--; maxR--;
            }
            else{
                minR--;
                maxR++;
            }
            if(minR < 0) minR = 0;
            if(maxR < 0) return false;
        }
        if(minR > 0) return false;
        return true;
    }
};
int main(){
    string s;
    cout << "Enter string : ";
    cin >> s;
    bool sol = Solution :: checkValidString(s);
    cout << sol << endl;
}