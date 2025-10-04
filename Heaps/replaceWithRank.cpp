#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Heap{

public:
    vector<pair<int, int>> heap;

    Heap() {
        heap.push_back({-1, -1});
    }

    void push(int val, int idx) {
        int currIdx = this->heap.size();
        this->heap.push_back({val , idx});

        if(currIdx == 1) return;

        while(currIdx/2 > 0) {
            int parent = currIdx/2;

            if(this->heap[currIdx].first < this->heap[parent].first) {
                swap(this->heap[currIdx], this->heap[parent]);
                currIdx = parent;
            }
            else if(this->heap[currIdx].first == this->heap[parent].first && this->heap[currIdx].second < this->heap[parent].second){
                swap(this->heap[currIdx], this->heap[parent]);
                currIdx = parent;
            }

            else return;
        }
    }

    void pop() {
        this->heap[1] = this->heap.back();
        this->heap.pop_back();

        int currIdx = 1, n = this->heap.size();

        while(true) {
            int l = 2 * currIdx, r = l + 1;
            int largest = currIdx;

            if(r < n && this->heap[largest].first > this->heap[r].first)
                largest = r;
            if(l < n && this->heap[largest].first > this->heap[l].first)
                largest = l;
            if(r < n && this->heap[largest].first == this->heap[r].first && this->heap[largest].second > this->heap[r].second)
                largest = r;
            if(l < n && this->heap[largest].first == this->heap[l].first && this->heap[largest].second > this->heap[l].second)
                largest = l;


            if(currIdx == largest) break;

            swap(this->heap[largest], this->heap[currIdx]);
            currIdx = largest;
        }
    }

    void print() {
        for(int i = 1; i < this->heap.size(); i++)
            cout << this->heap[i].first << " ";
        cout << endl;
        for(int i = 1; i < this->heap.size(); i++)
            cout << this->heap[i].second << " ";
        cout << endl;
    }

    pair<int, int> giveMax() { 
        return this->heap[1];
    }
};

class Solution{

public:
    static vector<int> replaceWithRank(vector<int>& arr, int N) {
        unordered_map<int, int> ranks;
        int mapped = 0, i = 1;
        Heap heap;
        for(int i = 0 ; i < N; i++) {
            heap.push(arr[i], i);
        }

        heap.print();

        vector<int> ansVec(N, -1);

        while(mapped < N) {
            pair<int, int> p = heap.giveMax();
            heap.pop();
            heap.print();

            if(ranks.find(p.first) == ranks.end()) {
                ranks.insert({p.first, i});
                i++;
            }

            ansVec[p.second] = ranks[p.first];
            mapped++;
        }
        return ansVec;
    }
};
int main() {
    int range, num;
    vector<int> arr;
    cout << "Enter range : ";
    cin >> range;

    for(int i = 0; i < range; i++) {
        cin >> num;
        arr.push_back(num);
    }

    vector<int> ans = Solution :: replaceWithRank(arr, range);

    for(const auto& it : ans) cout << it << " ";
}