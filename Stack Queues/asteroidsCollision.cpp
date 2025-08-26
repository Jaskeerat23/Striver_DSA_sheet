#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution{
public:
    static vector<int> asteroidCollision(vector<int>& asteroids){
        stack<int> st;
        vector<int> ans;
        for(int i = 0; i<asteroids.size(); i++){
            if(!st.empty() && asteroids[i] < 0){
                bool pushed = true;
                while(!st.empty() && st.top() > 0){
                    if(st.top() < -1 * asteroids[i]) st.pop();
                    else if(st.top() >= -1 * asteroids[i]){
                        if(st.top() == -1 * asteroids[i]) st.pop();
                        pushed = false;
                        break;
                    }
                }
                if(pushed) st.push(asteroids[i]);
            }
            else
                st.push(asteroids[i]);
        }
        if(st.empty()) return {};
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    int range;
    vector<int> arr;
    cout << "Enter n : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    vector<int> ans = Solution :: asteroidCollision(arr);
    for(const auto& it : ans){
        cout << it << " ";
    }
}