#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int data) : val(data), next(nullptr) {};
};


class Solution{
public:
    //BruteForce
    static ListNode* deleteMiddle(ListNode* head){
        if(head == nullptr) return head;
        ListNode* f = head, *s = head;
        while(f!=nullptr && f->next!=nullptr){
            s = s->next;
            f = f->next->next;
        }
        ListNode* ptr = head;
        while(ptr->next!=s) ptr = ptr->next;
        ptr->next = ptr->next->next;
        return head;
    }
    //Optimal
    static ListNode* deleteMiddle(ListNode* head){
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* f = head->next->next, *s = head;
        while(f!=nullptr && f->next!=nullptr){
            s = s->next;
            f = f->next->next;
        }
        ListNode* temp = s->next;
        s->next = s->next->next;
        delete(temp);
        return head;
    }
};

int main(){
    int d, ch = 1;
    ListNode* head = NULL, *tail = NULL;
    while(ch){
        cout << "Enter data : ";
        cin >> d;
        ListNode* newNode = new ListNode(d);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Do you want to continue(0/1) : ";
        cin >> ch;
    }
    cout << "Provided Linked List is : ";
    ListNode* ptr = head;
    while(ptr != nullptr){
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}