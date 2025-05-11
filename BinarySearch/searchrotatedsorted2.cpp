#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static bool search(vector<int>& nums, int target) {
        int high = nums.size()-1, low = 0;
        while(low<=high){
            int mid = high - (high - low)/2;
            if(nums[mid] == target)
                return true;
            if(nums[low] < nums[mid]){
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[high] > nums[mid]){
                if(target <= nums[high] && target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else if(nums[low] == nums[mid] || nums[high] == nums[mid]){
                int i = low;
                while(mid!=i && nums[i] == nums[mid]) i++;
                if(i == mid)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
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
    int ans = Solution :: search(arr, target);
    cout << "Ans is : " << ans << endl;
}