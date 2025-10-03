#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Heap{

public:

    vector<int> heap;
    Heap() {
        heap.push_back(INT_MIN);
    }

    void insert(int val) {
        int currIdx = this->heap.size(), parent = floor(currIdx/2);
        this->heap.push_back(val);
        if(currIdx == 1){
            return;
        }

        while(parent > 0 && this->heap[parent] < val){
            swap(this->heap[parent], this->heap[currIdx]);
            currIdx = parent;
            parent = floor(currIdx/2);
        }
    }

    void pop() {
        int i = 1;
        this->heap[1] = this->heap.back();
        
        this->heap.pop_back();
        int  n = this->heap.size();

        while(true) {
            int lChild = 2 * i;
            int rChild = 2* i + 1;
            int largest = i;

            if(lChild < n && this->heap[lChild] > this->heap[largest]){
                largest = lChild;
            }

            if(rChild < n && this->heap[rChild] > this->heap[largest]){
                largest = rChild;
            }

            if(largest == i) break;
            swap(this->heap[largest], this->heap[i]);
            i = largest;
        }
    }


    void showHeap() {
        for(int i = 1; i < this->heap.size(); i++)
            cout << this->heap[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap heap;
    int val, range;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i < range; i++){
        cin >> val;
        heap.insert(val);
    }
    heap.showHeap();

    heap.pop();
    heap.showHeap();
    
}