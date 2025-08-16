#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long divid = dividend, divis = divisor, rem = divid;
        if(divisor == 1 || divisor == -1) {
            return ((long long)(divid * divis) < INT_MAX)? (long long)(divid * divis) : INT_MAX;
        }
        int f = 1, cnt = 0;
        if(rem < 0) {rem*=-1, f*=-1;}
        if(divis < 0) {divis*=-1, f*=-1;}
        while(rem >= divis){
            rem-=divis;
            cnt++;
        }
        cout << cnt << endl;
        return f * cnt;
    }
    static int divideBitManipulation(int dividend, int divisor){
        int f = 1;
        long long divid = dividend, divis = divisor, cnt = 0, quo = 0;
        if(divid >= 0 && divis < 0){ f*=-1; }
        if(divid < 0 && divis > 0) { f*=-1; }
        divid = abs(divid), divis = abs(divis);
        while(divid >= (divis << (cnt + 1))){
            cnt++;
        }
        quo+=(1 << cnt);
        divid-=(divis << cnt);
        while(divid >= divis){
            quo++;
            divid-=divis;
        }
        if(cnt > (INT_MAX)) return f * INT_MAX;

        return (f == -1)? -quo : quo;
    }
};
int main(){
    int dividend, divisor;
    cout << "Enter dividend : ";
    cin >> dividend;
    cout << "Enter divisor : ";
    cin >> divisor;
    int sol = Solution :: divideBitManipulation(dividend, divisor);
    cout << sol << endl;
}