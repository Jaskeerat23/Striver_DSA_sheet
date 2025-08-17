#include<iostream>
#include<vector>
#include<bits/stdc++.h>
class Stack{
public:
    std :: vector<int> stack;
    void push(int n){
        stack.push_back(n);
    }
    void pop(){
        if(!stack.empty())
            stack.pop_back();
        else
            std :: cout << "Stack is empty\n";
    }
    void peek(){
        if(!stack.empty())
            std :: cout << stack.back() << std :: endl;
        else
            std :: cout << "Stack is empty\n";
    }
    void display(){
        if(stack.empty()){
            std :: cout << "Stack is empty\n";
            return;
        }
        for(int i = stack.size() - 1; i >= 0; i--)
            std :: cout << stack[i] << " ";
        std :: cout << std :: endl;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();
}