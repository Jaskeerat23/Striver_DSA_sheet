#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    static int atmostK(vector<int>& nums, int k){
        int i = 0, j = 0, cnt = 0, uniqueNums = 0;
        unordered_map<int, int> mapp;
        while(j < nums.size()){

            if(mapp[nums[j]] == 0)
                uniqueNums+=1;

            while(i < nums.size() && uniqueNums > k){
                mapp[nums[i]]-=1;
                if(mapp[nums[i]] == 0) uniqueNums-=1;
                i++;
            }
                
            mapp[nums[j]]+=1;

            (i <= j) ? cnt+=(j - i + 1) : cnt;
            j++;
        }
        return cnt;
    }
    static int kDiffInts(vector<int>& nums, int k) {
        return atmostK(nums, k) - atmostK(nums, k - 1);
    }
};
int main(){
    int range, num, k;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i < range; i++){
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter k : ";
    cin >> k;
    cout << Solution :: kDiffInts(nums, k);
}