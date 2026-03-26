#include<bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
    vector<int> seg;

    SegmentTree(int n) {
        seg.resize(4 * n, 0);
    }

    int build(vector<int>& arr, int low, int high, int ind) {
        cout << low << " " << high << endl;
        if(low == high) {
            seg[ind] = arr[low];
            return seg[ind];
        }

        int mid = low + (high - low)/2;
        int l = build(arr, low, mid, 2 * ind + 1);
        int r = build(arr, mid + 1, high, 2 * ind + 2);

        return seg[ind] = l + r;
    }

    int update_seg(int idx, int low, int high, int ind, int val) {
        cout << idx << " " << ind << endl;
        if(low == high) {
            int old_val = seg[ind];
            seg[ind] = val;
            cout << "the change is of " << old_val - val << endl;
            return old_val - val;
        }

        int mid = low + (high - low)/2;

        if(idx > mid) {
            int chg = update_seg(idx, mid + 1, high, 2 * ind + 2, val), old_val = seg[ind];
            seg[ind] -= chg;
            return chg;
        }
        int chg = update_seg(idx, low, mid, 2 * ind + 1, val);
        seg[ind] -= chg;
        return chg;
    }

    int range_sum(int ind, int low, int high, int q_l, int q_r) {
        if(low >= q_l && high <= q_r) {
            return seg[ind];
        }
        if(low > q_r || high < q_l) return 0;

        int mid = low + (high - low)/2;
        int l = range_sum(2 * ind + 1, low, mid, q_l, q_r);
        int r = range_sum(2 * ind + 2, mid + 1, high, q_l, q_r);
        return l + r;
    }

    void print() {
        for(int& it: seg) cout << it << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cout << "First integer denotes number of elements in array, then n consecutive elements denote the number in the array\n";
    cin >> n;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(n);
    st.build(arr, 0, n - 1, 0);

    cout << "The segment tree is: \n";
    st.print();

    cout << "Entered values are : \n";
    for(int& it: arr) cout << it << " ";
    cout << endl;

    while(true) {
        int ch, idx, val;

        cin >> ch;

        if(!ch){
            int idx, val;
            cin >> idx >> val;
            st.update_seg(idx, 0, n - 1, 0, val);
            cout << "Updated Segment tree is: \n";
            st.print();
        }
        else {
            int l, h;
            cin >> l >> h;
            cout << "Sum of range " << l << " " << h << " is " << st.range_sum(0, 0, n - 1, l, h);
        }
    }
}