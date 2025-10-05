#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Heap{
public:
    priority_queue<pair<int, int>> maxHeap;

    void pushVal(int cnts, int val) {
        this->maxHeap.push({cnts, val});
    }

    void popVal() {
        this->maxHeap.pop();
    }

    pair<int, int> getmax() {
        return this->maxHeap.top();
    }
};


class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        Heap heap;
        vector<int> ans;

        for(const auto& it : nums) mapp[it]+=1;

        for(const auto& it : mapp) heap.pushVal(it.second, it.first);

        for(int i = 1; i <= k; i++) {
            pair<int, int> p = heap.getmax();

            heap.popVal();

            ans.push_back(p.second);
        }
        return ans;
    }
};
int main() {
    int range, num, k;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;

    for(int i = 0; i<range; i++) {
        cin >> num;
        nums.push_back(num);
    }

    cout << "Enter k : ";
    cin >> k;

    vector<int> ans = Solution :: topKFrequent(nums, k);
    for(const auto& it : ans) cout << it << " ";
    cout << endl;
}