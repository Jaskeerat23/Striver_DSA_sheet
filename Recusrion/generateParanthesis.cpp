#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static void generate(vector<string>& res, string currStr, int openCount, int closeCount, int n){
        if(!openCount && !closeCount){
            res.push_back(currStr);
            return;
        }
        if(openCount){
            currStr[n] = '(';
            generate(res, currStr, openCount - 1, closeCount, n + 1);
        }
        if(closeCount && closeCount > openCount){
            currStr[n] = ')';
            generate(res, currStr, openCount, closeCount - 1, n + 1);
        }
    }

    static vector<string> generateParanthesis(int num){
        vector<string> res;
        string currStr(2 * num, 0);
        generate(res, currStr, num, num, 0);
        return res;
    }

};
int main(){
    int num;
    cout << "Enter num : ";
    cin >> num;
    vector<string> res = Solution :: generateParanthesis(num);
    for(const auto& it1 : res){
        cout << it1 << endl;
    }
}