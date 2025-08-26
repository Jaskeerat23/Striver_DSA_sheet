#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
public:
    static vector<int> findPSE(vector<int>& arr){
        stack<int> st;
        vector<int> pse(arr.size(), -1);
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    static vector<int> findNSE(vector<int>& arr){
        stack<int> st;
        vector<int> nse(arr.size(), arr.size());
        for(int i = arr.size() - 1; i>-1; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty())
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    static int sumSubarrayMins(vector<int>& arr){
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);
        long long mod = 10e9;
        cout << "Nse array is : " << endl;
        for(const auto& it : nse) cout << it << " ";
        cout << endl;
        cout << "Pse array is\n";
        for(const auto& it : pse) cout << it << " ";
        cout << endl;
        int ans = 0;
        for(int i = 0; i<arr.size(); i++){
            int cand = (nse[i] - i) * (i - pse[i]) * arr[i];
            ans+=(cand)%(mod + 7);
        }
        return ans;
    }
};
int main() {
    int range;
    vector<int> arr;
    cout << "Enter n : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int ans = Solution :: sumSubarrayMins(arr);
    cout << "Ans is " << ans << endl;
}