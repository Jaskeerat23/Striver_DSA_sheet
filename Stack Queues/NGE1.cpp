#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution{
public:
    static vector<int> nextLargerElement(vector<int>& arr){
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, -1);
        s.push(arr[n - 1]);
        for(int i = n - 2; i>=0; i--){
            if(s.top() > arr[i]){
                ans[i] = s.top();
                s.push(arr[i]);
            }
            else{
                while(!s.empty() && s.top() < arr[i])
                    s.pop();
                if(!s.empty())
                    ans[i] = s.top();
                s.push(arr[i]);
            }
        }
        return ans;
    }
};
int main(){
    int range, num;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        cin >> num;
        nums.push_back(num);
    }
    vector<int> ans = Solution :: nextLargerElement(nums);
    for(const auto& it : ans){
        cout << it << " ";
    }
    cout << endl;
}
