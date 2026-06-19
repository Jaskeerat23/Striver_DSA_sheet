#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
    return a[1] <= b[1];
}

class TrieNode {
public:
    TrieNode* links[2]{};
};

class Solution {
public:

    TrieNode* root;
    Solution() {
        root = new TrieNode();
    }

    void insert(int n) {
        TrieNode* ptr = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(ptr->links[bit] == nullptr) {
                ptr->links[bit] = new TrieNode();
            }
            ptr = ptr->links[bit];
        }
    }

    int find(int n) {
        TrieNode* ptr = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(ptr->links[!bit] != nullptr) {
                ptr = ptr->links[!bit];
                ans = ans + (1 << i);
            }
            else ptr = ptr->links[bit];
        }
        return ans;
    }

    vector<int> findMaximumXOR(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int i = 0, j = 0, ans_idx = 0, mini = INT_MAX;

        for(int i = 0; i < m; i++) queries[i].push_back(i);

        vector<int> ans(m, 0);

        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), comparator);

        while(i < n && j < m) {
            // cout << "inside\n";
            int mi = queries[j][1];
            while(i < n && nums[i] <= mi) {
                mini = min(mini, nums[i]);
                insert(nums[i]);
                i++;
            }

            // cout << "Entered till " << i << endl;

            while(j < m && (queries[j][1] == mi || i == n)) {
                if(mini > queries[j][1]) {
                    ans[queries[j].back()] = -1;
                }
                else {
                    ans[queries[j].back()] = find(queries[j][0]);
                }
                j++;
                // ans_idx++;
            }

            // cout << "Answered queries till " << j << endl;
            // cout << "looping\n";
        }

        return ans;

        // for(int& it: nums) {
        //     insert(it);
        // }

        // int maxi = 0;
        // for(int& it: nums) {
        //     int ans = find(it);
        //     maxi = max(maxi, ans);
        // }
        // return maxi;
    }
};

int main() {
    // int bits_req = ceil(log2(32));
    // unsigned int shifted_bits = 32u << (31 - bits_req);
    // cout << "Bits req are " << bits_req << endl;
    // cout << "Bits shifted is " << (31 - bits_req) << endl;
    // cout << "After shifting the number is " << shifted_bits << endl;

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(2, 0));
    vector<int> nums(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;
    vector<int> ans = sol.findMaximumXOR(nums, queries);
    for(auto& it: ans) cout << it << " ";
    return 0;
}