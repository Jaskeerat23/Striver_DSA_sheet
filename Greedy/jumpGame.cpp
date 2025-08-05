#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool jumpGame(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int i = 0, farthest = INT_MIN;
        while(i < nums.size()){
            farthest = max(farthest, nums[i] + i);
            if(farthest >= nums.size() - 1) return true;
            if(!nums[i]){
                if(farthest > i) i+=1;
                else return false;
            }
            else 
                i++;
        }
        return true;
    }
};
int main(){
    int range, num;
    vector<int> jumps;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        jumps.push_back(num);
    }
    bool ans = Solution :: jumpGame(jumps);
    cout << boolalpha << ans << endl;
}