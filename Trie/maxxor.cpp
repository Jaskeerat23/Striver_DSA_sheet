#include<bits/stdc++.h>
using namespace std;
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

    int findMaximumXOR(vector<int>& nums) {
        for(int& it: nums) {
            insert(it);
        }

        int maxi = 0;
        for(int& it: nums) {
            int ans = find(it);
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};

int main() {
    // int bits_req = ceil(log2(32));
    // unsigned int shifted_bits = 32u << (31 - bits_req);
    // cout << "Bits req are " << bits_req << endl;
    // cout << "Bits shifted is " << (31 - bits_req) << endl;
    // cout << "After shifting the number is " << shifted_bits << endl;

    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int ans = sol.findMaximumXOR(nums);
    cout << ans << endl;
}