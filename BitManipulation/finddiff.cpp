#include<string>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static char findDifference(string s, string t){
        long ex1 = 0, ex2 = 0;
        for(int i = 0; i<s.length(); i++)
            ex1^=s[i];
        for(int i = 0; i<t.length(); i++)
            ex2^=t[i];
        return ex1^ex2;
    }
};
int main(){
    string s, t;
    cout << "Enter string s : ";
    cin >> s;
    cout << "Enter string t : ";
    cin >> t;
    char a = Solution :: findDifference(s, t);
    cout << a;
}