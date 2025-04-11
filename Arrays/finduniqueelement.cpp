#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
using namespace std;
class Solution {
public:
    //BRUTE FORCE METHOD:
    static int singleNumber(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for(int& i : nums)
            counts[i]+=1;
        for(int i = 0; i<nums.size(); i++)
            if(counts[nums[i]]==1)
                return nums[i];
        return 0;
    }
    //OPTIMAL METHOD:
    /*We will use concept of XOR gate since we know
    every element appears twice so that means XOR of
    them must be 0 and we know 0 XOR any bits = any bits
    So we can use this concept to solve this problem.*/
    static int singleNumber2(vector<int>& nums) {
        int ans = 0;
        for(int& i : nums)
            ans^=i;
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
    int ans = Solution :: singleNumber2(nums);
    cout << "Ans is " << ans << endl;
}