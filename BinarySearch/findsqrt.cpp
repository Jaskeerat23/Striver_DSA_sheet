#include<iostream>
class Solution{
public:
    static int sqrt(int n){
        if(n == 0 || n == 1) return n;
        int low = 0, high = n, ans = -1;
        long long mid = -1;
        while(low<=high){
            long long mid = high - (high - low)/2;
            long long val = mid * mid;
            if(val <= (long long)n){
                ans = mid;
                low = mid + 1;
            }
            else if(mid * mid > n)
                high = mid - 1;
        }
        return ans;
    }
};
int main(){
    int n;
    std :: cout << "Enter n : ";
    std :: cin >> n;
    int ans = Solution :: sqrt(n);
    std :: cout << "Ans is : " << ans << std :: endl;
}