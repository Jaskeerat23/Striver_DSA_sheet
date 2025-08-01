#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCnt = 0, tenCnt = 0, twentyCnt = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) fiveCnt++;
            if(bills[i] == 10){
                if(fiveCnt) {
                    tenCnt++;
                    fiveCnt--;
                }
                else return false;
            }
            if(bills[i] == 20) {
                if(tenCnt && fiveCnt)
                    tenCnt--, fiveCnt--;
                else if(fiveCnt >= 3)
                    fiveCnt-=3;  
                else return false;
            }
        }  
        return true;
    }
};
int main(){
    //SOLVED DIRECTLY ON LEETCODE
}