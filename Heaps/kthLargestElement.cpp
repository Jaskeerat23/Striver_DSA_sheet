#include<iostream>
#include<vector>
using namespace std;
class Heap {

public:
    vector<int> heap;

    Heap() { heap.push_back(-1); }

    void push(int val) {
        int currIdx = this->heap.size();
        this->heap.push_back(val);
        if(currIdx == 1) return;

        while(currIdx/2 > 0) {
            int parent = currIdx/2;
            if(this->heap[parent] < this->heap[currIdx]) {
                swap(this->heap[parent], this->heap[currIdx]);
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
            int l = 2 * currIdx;
            int r = l + 1;
            int largest = currIdx;
            
            if(l < n && this->heap[largest] < this->heap[l])
                largest = l;
            if(r < n && this->heap[largest] < this->heap[r])
                largest = r;

            if(largest == currIdx) break;

            swap(this->heap[largest], this->heap[currIdx]);
            currIdx = largest;
        }
    }

    int giveMax(){
        return this->heap[1];
    }

    void print(){
        for(int i = 1; i < this->heap.size(); i++){
            cout << this->heap[i] << " ";
        }
        cout << endl;
    }
};

int findKthLargest(vector<int>& nums, int k) {
    Heap h;
    for(const auto& it : nums) h.push(it);
    cout << "Heap pushed\n";
    h.print();
    for(int i = 0; i < k-1; i++) h.pop();
    h.print();
    return h.giveMax();
}
int main(){
    Heap heap;
    heap.push(10);
    heap.push(20);
    heap.push(15);
    heap.push(30);
    heap.push(40);
    cout << heap.giveMax();
    heap.print();

    vector<int> nums;
    int range, num, k;

    cout << "Enter range : ";
    cin >> range;

    for(int i = 0; i < range; i++){
        cin >> num;
        nums.push_back(num);
    }

    cout << "Enter k : ";
    cin >> k;

    cout << findKthLargest(nums, k);

}