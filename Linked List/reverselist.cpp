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
    static ListNode* reverseList(ListNode* head){
        ListNode* fp = head, *sp = head->next, *tp = sp;
        while(tp!=nullptr){
            tp = sp->next;
            sp->next = fp;
            fp = sp;
            sp = tp;
        }
        head->next = nullptr;
        ListNode* newHead = fp;
        return newHead;
    }
    static ListNode* reverseListUsingRecursion(ListNode* head){

        /*The inutition behind this algorithm is that traverse till the end of the
        list so that we find the new head and then keep returning it through 
        function calls in the stack while manipulating the node next to the current node
        in the original list*/
        
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseListUsingRecursion(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
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
    ListNode* reversedHead = Solution :: reverseListUsingRecursion(head);
    ptr = reversedHead;
    while(ptr!=nullptr){
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "nullptr" << endl;
}