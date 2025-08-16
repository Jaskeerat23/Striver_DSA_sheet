#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static int traverseMoves(int n, int moves){
        if(n == 1) return moves;
        int mini = INT_MAX;
        if(!(n%2)){
            mini = traverseMoves(n/2, moves + 1);
        }
        else{
            int x1 = traverseMoves(n + 1, moves + 1);
            int x2 = traverseMoves(n - 1, moves + 1);
            mini = min(x1, x2);
        }
        return mini;
    }
    static int integerReplacement(int n){
        return traverseMoves(n, 0);
    }
    static int integerReplacement2(int n){
        int cnt = 0;
        while(n != 1){
            if(!(n & 1))
                n = n >> 1;
            else if(n != 3 && n & 3 == 3)
                n+=1;
            else n-=1;
            cnt++;
        }
        return cnt;
    }
};
int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    int ans = Solution :: integerReplacement(n);
    cout << ans << endl;
}