#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low<high){
            int mid = high - (high - low)/2;
            if(nums[high] > nums[mid] && nums[mid] < nums[low]){
                low++, high--;
                continue;
            }
            
            /*The 'equals to' sign (=) while comparing with mid is for
            handling edge cases since in this question there are unique values
            so if nums[low] <= nums[mid] or vice versa means that either mid == low
            or mid == high*/

            else if(nums[low] <= nums[mid] && nums[low] < nums[high])
                high = mid - 1;
            else if(nums[high] <= nums[mid] && nums[high] < nums[low])
                low = mid + 1;
        }
        return nums[high];
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
    cout << endl;
    int ans = Solution :: findMin(arr);
    cout << "Ans is : " << ans << endl;
}