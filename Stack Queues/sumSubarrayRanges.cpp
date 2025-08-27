#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
static vector<long long> findPGE(vector<int>& arr){
        stack<int> st;
        vector<long long> pge(arr.size(), -1);
        for(long long i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty())
                pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }
    static vector<long long> findNGE(vector<int>& arr){
        stack<int> st;
        vector<long long> nge(arr.size(), arr.size());
        for(long long i = arr.size() - 1; i>-1; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty())
                nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    static vector<long long> findPSE(vector<int>& arr){
        stack<int> st;
        vector<long long> pse(arr.size(), -1);
        for(long long i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    static vector<long long> findNSE(vector<int>& arr){
        stack<int> st;
        vector<long long> nse(arr.size(), arr.size());
        for(long long i = arr.size() - 1; i>-1; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty())
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    static long long subArrayRanges(vector<int>& arr) {
        vector<long long> pse = findPSE(arr);
        vector<long long> nse = findNSE(arr);
        vector<long long> pge = findPGE(arr);
        vector<long long> nge = findNGE(arr);
        long long mod = 10e9 + 7, maxRange = 0, minRange = 0;
        for(long long i = 0; i<arr.size(); i++){
            long long minCount = (nse[i] - i) * (i - pse[i]) * (long long)arr[i];
            long long maxCount = (nge[i] - i) * (i - pge[i]) * (long long)arr[i];
            minRange+=minCount;
            maxRange+=maxCount;
        }
        return maxRange - minRange;
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
    long long ans = Solution :: subArrayRanges(arr);
    cout << "Ans is " << ans << endl;
}