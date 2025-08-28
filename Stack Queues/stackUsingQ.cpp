#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class MyStack {
public:
    // queue
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    //This funcion will pass all the elements of q1 to q2
    void fillQueue(queue<int>& q1, queue<int>& q2){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }

    void push(int x) {
        // fillQueue(q1, q2);/
        q1.push(x);
        // fillQueue(q2, q1);
    }
    
    int pop() {
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        fillQueue(q2, q1);
        return x;
    }
    
    int top() {
        cout << "Size of q2 before top is " << q2.size() << endl;
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(x);
        q1.pop();
        fillQueue(q2, q1);
        return x;
    }
    
    bool empty() {
        if(q1.size()) return false;
        return true;
    }
};


int main(){
    MyStack* stk = new MyStack();
    stk->push(1);
    stk->push(2);
    stk->push(3);
    stk->push(4);
    cout << stk->top();
    cout << stk->pop();
    cout << stk->pop();
    cout << stk->pop();
    cout << stk->pop();
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */