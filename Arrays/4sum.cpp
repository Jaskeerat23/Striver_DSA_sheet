#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class Solution {
public:
    static vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<size-3; i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j<size - 2; j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1, l = size-1;
                // cout << i << j << k << l;
                while(k < l){
                    // cout << nums[i] << nums[j] << nums[k] << nums[l] << endl;
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        if(k >= l)
                            break;
                        k++, l--;
                    }
                    else if(sum > target)
                        l--;
                    else if(sum < target)
                        k++;
                }
            }
        }
        return ans;
    }
};
int main(){
    int range, target;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter target : ";
    cin >> target;
    vector<vector<int>> ans = Solution :: fourSum(nums, target);
    for(vector<int> vec : ans){
        for(int i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
}       