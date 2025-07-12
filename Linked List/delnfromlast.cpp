#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};
class Solution{
public:
    static ListNode* delNFromLast(ListNode* head, int n){
        if(head == NULL) return head;
        ListNode* s = head, *f = head, *temp = head;
        while(n>0 && s!=NULL){
            s = s->next;
            n-=1;
        };
        cout << "deleting....." << endl;
        if(s == NULL){
            head = head->next;
            return head;
        }
        while(s->next!=NULL){
            cout << "In the loop" << endl;
            s = s->next;
            f = f->next;
        }
        f->next = f->next->next;
        return head;
    }
};
int main(){
    int range = -1, n;
    cout << "Enter range : ";
    cin >> range;
    ListNode* head = NULL, *tail = NULL, *ptr = NULL;
    for(int i = 0; i < range; i++){
        int d;
        cout << "Enter data : ";
        cin >> d;
        ListNode* newNode = new ListNode(d);
        if(head == NULL) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout << "Provided list is : ";
    for(ptr = head; ptr!=NULL; ptr = ptr->next)
        cout << ptr->val << " ";
    cout << endl;
    cout << "Enter n : ";
    cin >> n;
    ListNode* newHead = Solution :: delNFromLast(head, n);
    cout << "new list is : ";
    for(ptr = newHead; ptr!=NULL; ptr = ptr->next)
        cout << ptr->val << " ";
    cout << endl;
}