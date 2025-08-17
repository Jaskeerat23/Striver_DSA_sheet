#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static int countPrimes(int n){
        if(n == 0 || n == 1) return 0;
        vector<int> primes(n, 1);
        primes[0] = 0;
        primes[1] = 0;
        cout << "Size is " << primes.size() << endl;
        for(int i = 2; i <= sqrt(n); i++){
            if(primes[i]){
                for(int j = i * i; j < n; j+=i) primes[j] = 0;
            }
        }
        int cnt = 0;
        for(const auto& it : primes)
            if(it) cnt++;
        return cnt;
    }
};
int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    int ans = Solution :: countPrimes(n);
    cout << ans << endl;
}