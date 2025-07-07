#include<iostream>
#include<random>
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int d) : val(d), next(NULL) {}
};
class Solution{
public:
    static bool hasCycle(ListNode* head){
        unordered_map<ListNode*, bool> map;
        ListNode* ptr = head;
        while(ptr!=NULL) {
            if(map.find(ptr) != map.end())
                return true;
            map.insert({ptr, true});
            ptr = ptr->next;
        }
        return false;
    }
    static bool hasCycleOptimized(ListNode* head){
        ListNode* fp = head, *sp = head;
        while(fp!=NULL && fp->next!=NULL){
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp) return true;
        }
        return false;
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
    while(ptr != NULL){
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
    cout << "Do you want to cycle the list(If yes enter the index, else 0) : ";
    cin >> ch;
    if(ch){
        ptr = head;
        while(ch--) ptr = ptr->next;
        tail->next = ptr;
    }
    bool ans = Solution :: hasCycle(head);
    cout << boolalpha << ans << endl;
}