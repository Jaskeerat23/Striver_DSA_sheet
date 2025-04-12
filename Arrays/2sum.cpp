#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    static vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> indices;
        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(indices.find(diff)!=indices.end()){
                return { i, indices.find(diff)->second };
            }
            indices.insert({nums[i], i});
        }
        return {};
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
    vector<int> ans = Solution :: twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
}