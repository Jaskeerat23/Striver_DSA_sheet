#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static vector<int> rearrangeArray(vector<int>& nums) {
        //BRUTE FORCE APPROACH
        vector<int> pos, neg, res;
        for(int i : nums)
            (i<0) ? neg.push_back(i) : pos.push_back(i);
        for(int i = 0; i<nums.size()/2; i++){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
    static vector<int> rearrangeArray2(vector<int>& nums) {
        vector<int> res(nums.size());
        int pos=0, neg=1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0){
                res[neg] = nums[i];
                neg+=2;
            }
            else{
                res[pos] = nums[i];
                pos+=2;
            }
        }
        return res;
    }
};
int main(){
    vector<int> arr;
    int range;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    vector<int> ans = Solution :: rearrangeArray2(arr);
    for(int i : ans) { cout << i << " "; }
    cout << endl;
}