#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<size-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1, k = size-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(k > j && nums[k] == nums[k-1]) k--;
                    if(j >= k)
                        break;
                    j++, k--;
                }
                else if(sum > 0)
                    k--;
                else if(sum < 0)
                    j++;
            }
        }
        return ans;
    }
};
int main(){
    int range;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<vector<int>> ans = Solution :: threeSum(nums);
    for(vector<int> vec : ans){
        for(int i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
}       