#include<iostream>
class Solution{
public:
    static int sqrt(int n){
        if(n == 0 || n == 1) return n;
        int low = 0, high = n, mid  = -1;
        while(low<=high){
            mid = high - (high - low)/2;
            if(mid * mid == n)
                return mid;
            else if(mid * mid > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return mid - 1;
    }
};
int main(){
    int n;
    std :: cout << "Enter n : ";
    std :: cin >> n;
    int ans = Solution :: sqrt(n);
    std :: cout << "Ans is : " << ans << std :: endl;
}