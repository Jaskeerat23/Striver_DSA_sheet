#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
using namespace std;
class Solution {
public:
    static int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> isExist;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            int diff = sum - k;
            if(isExist.find(diff) != isExist.end())
                count+=isExist[diff];
            if(diff == 0)
                count+=1;
            isExist[sum]+=1;
        }
        return count;
    }
};
int main() {
    int range, k;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter k : ";
    cin >> k;
    int ans = Solution :: subarraySum(nums, k);
    cout << "Ans is : " << ans << endl;
    cout << endl;
}