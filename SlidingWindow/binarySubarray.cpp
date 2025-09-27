/*
This Question will be solved using At-most k elements approach 
since we want the exact counts of subarrays whose sum will yield 
sum equal to k, so why not first count subarrays whose sum <= k
then count subarrays whose sum <= (k - 1), then finally subtracting both the sums
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static int atmostK(vector<int>& nums, int k){
        int n = nums.size(), i = 0, j = 0, subSum = 0, cnt = 0;
        while(j < n){
            subSum+=nums[j];

            while(i <= j && subSum > k) { subSum-=nums[i], i++; }

            cnt+=(j - i + 1);
            j++;
        }
        return cnt;
    }
    static int numSubarrayWithSum(vector<int>& nums, int goal){
        return abs(atmostK(nums, goal) - atmostK(nums, goal - 1));
    }
};
int main(){
    int range, num, goal;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter goal : ";
    cin >> goal;
    int ans = Solution :: numSubarrayWithSum(nums, goal);
    cout << ans << endl;
}
