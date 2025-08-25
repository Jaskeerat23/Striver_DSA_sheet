#include<vector>
#include<iostream>
class Queue{
public:
    std :: vector<int> queue;
    int r, f;
    Queue() : r(-1), f(0) {};

    void push(int n){
        if(r == -1){
            r = 0;
        }
        queue.push_back(n);
        f++;
    }

    void pop(){
        if(r == f || r == -1){
            std :: cout << "Queue is Empty Already!!\n";
            return;
        }
        r++;
    }

    void peek(){
        if(r == f || r == -1){
            std :: cout << "Queue is Empty!!\n";
            return;
        }
        std :: cout << queue[r] << std :: endl;
    }

    void display(){
        if(r == f || r == -1){
            std :: cout << "Queue is Empty!!\n";
            return;
        }
        for(int i = r; i < queue.size(); i++){
            std :: cout << queue[i] << " ";
        }
        std :: cout << std :: endl;
    }
};
int main(){
    Queue q;
    q.display();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.display();
    q.pop();
    q.peek();
    q.display();
}