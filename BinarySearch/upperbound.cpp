#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    static int upperbound(vector<int>& nums, int target){
        if(*(nums.end()-1) < target)
            return nums.size();
        int low = 0, high = nums.size() - 1, ubound = 0;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(nums[mid] > target){
                ubound = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target || nums[mid] == target)
                low = mid + 1;
        }
        return ubound;
    }
};
int main(){
    vector<int> arr;
    int range, target;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << endl;
    cout << "Enter target : ";
    cin >> target; 
    int ans = Solution :: upperbound(arr, target);
    cout << "Ans is : " << ans << endl;
}