#include<bits/stdc++.h>
using namespace std;
class SparseTable {
public:
    vector<vector<long long>> st;

    void build(vector<long long>& arr) {
        int n = arr.size();
        int logn = log2(n);
        st.resize(n, vector<long long>(logn + 1, 0));
        for(int i = 0; i < n; i++) st[i][0] = arr[i];

        for(int j = 1; j <= logn; j++) {
            for(int i = 0; i <= n - (1 << j); i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    long long query(int l, int r) {
        int len = r - l + 1;
        int logn = log2(len);

        return min(st[l][logn], st[r - (1 << logn) + 1][logn]);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n, 0), ans;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SparseTable st;
    st.build(arr);
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        ans.push_back(st.query(a - 1, b - 1));
    }

    for(auto& it: ans) cout << it << endl;

    return 0;
}