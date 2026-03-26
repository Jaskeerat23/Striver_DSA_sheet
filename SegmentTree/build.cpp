#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    vector<int> update_pending;
    //Number of elements in the original array
    SegmentTree(int n) {
        seg.resize(4 * n, -1);
        update_pending.resize(4 * n, 0);
    }

    int build(vector<int>& arr, int ind, int low, int high) {
        if(low == high) {
            return seg[ind] = arr[low];
        }
        int mid = low + (high - low)/2;
        int l = build(arr, 2 * ind + 1, low, mid);
        int r = build(arr, 2 * ind + 2, mid + 1, high);
        return seg[ind] = l + r;
    }


    //low -> the left of current node
    //high -> the right of current node
    //q_r -> the right asked in query
    //q_l -> the left asked in query
    int query(int ind, int low, int high, int q_r, int q_l) {
        
        //the range completely fits
        if(low >= q_l && high <= q_r) return seg[ind];
        
        //if range does not even fit a bit
        if(low > q_r || high < q_l) return 0;

        int mid = low + (high - low)/2;
        int l = query(2 * ind + 1, low, mid, q_r, q_l);
        int r = query(2 * ind + 2, mid + 1, high, q_r, q_l);

        return l + r;
    }

    //q_l -> the low for query range
    //q_r -> the high for query range
    //low -> the current low of the node
    //high -> the current high of the node
    //update_val -> the value with which we have to update the nodes of the given range
    int lazy_prop(int ind, int q_l, int q_r, int low, int high, int update_val) {

        //first we check for any pending lazy updates
        if(update_pending[ind]) {
            seg[ind] += (high - low + 1) * update_pending[ind];

            if(low != high) {
                update_pending[2 * ind + 1] += update_pending[ind];
                update_pending[2 * ind + 2] += update_pending[ind];
            }
            update_pending[ind] = 0;
        }

        //if the current range completely satisfied 
        if(q_l <= low && q_r >= high) {

            //update the node val
            seg[ind] += (high - low + 1) * update_val;

            //if node is not leaf propagate the update to it's children
            if(low != high) {
                update_pending[2 * ind + 1] += update_val; 
                update_pending[2 * ind + 2] += update_val;
            }

            return seg[ind];
        }

        if(q_l > high || q_r < low) return seg[ind];

        int mid = low + (high - low)/2;

        int l = lazy_prop(2 * ind + 1, q_l, q_r, low, mid, update_val);
        int r = lazy_prop(2 * ind + 2, q_l, q_r, mid + 1, high, update_val);
        return seg[ind] = l + r;
    }

    void print() {
        for(auto& it: seg) cout << it << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    cout << "The range is : " << n << endl;

    vector<int> arr(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter array is:\n";
    for(int& it: arr) cout << it << " ";
    cout << endl;

    SegmentTree st(n);
    st.build(arr, 0, 0, n - 1);

    st.print();

    while(true) {
        int l = 0, h = 0, val = 0;
        cin >> l >> h >> val;
        cout << "Query range is " << l << " " << h << " with value " << val << endl;

        cout << st.lazy_prop(0, l, h, 0, n - 1, val);

        st.print();
    }
}