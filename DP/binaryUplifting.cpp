#include<bits/stdc++.h>
using namespace std;
class TreeAncestor {
public:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while(1 << LOG <= n) LOG++;
        parent[0] = 0;

        vector<vector<int>> children(n, vector<int>());
        for(int i = 0; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        up.resize(n, vector<int>(LOG));
        depth.resize(n);
        parent[0] = 0;

        stack<pair<int, int>> stk;
        stk.push({0, 0}); // {node, depth}
        
        while(!stk.empty()) {
            pair<int, int> top = stk.top();
            stk.pop();
            int v = top.first;
            int d = top.second;

            depth[v] = d;
            up[v][0] = parent[v];
            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }

            for(auto& it: children[v]) {
                if(it == 0) continue;
                stk.push({it, d + 1});
            }

        }

        // for(int v = 0; v < n; v++) {
        //     up[v][0] = parent[v];
        //     if(v != 0) depth[v] = depth[parent[v]] + 1;
        //     for(int j = 1; j < LOG; j++) {
        //         up[v][j] = up[up[v][j - 1]][j - 1];
        //     }
        // }
    }

    int getKthAncestor(int node, int k) {
        if(depth[node] < k) return -1;
        for(int i = 0; i < LOG; i++) {
            if(k & (1 << i)) node = up[node][i];
        }
        return node;
    }
};

int main() {
    int n;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    n = parent.size();
    TreeAncestor ta(n, parent);
    while(true) {
        int node, k;
        cout << "Enter node and kth ancestor: ";
        cin >> node >> k;

        cout << ta.getKthAncestor(node, k) << endl;
    }
}
