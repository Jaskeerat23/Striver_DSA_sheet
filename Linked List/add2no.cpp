#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};
class Solution{
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* head = addingTwoNumbers(l1, l2, 0);
        return head;
    }
    static ListNode* addingTwoNumbers(ListNode* l1, ListNode* l2, int c){
        cout << "Carry is " << c << endl;
        if(l1 == nullptr && l2 == nullptr && c) {
            ListNode* newNode = new ListNode(c);
            return newNode;
        }
        if(l1 == nullptr) {
            cout << "List 1 ended " << endl;
            if(c){
                ListNode* newNode = new ListNode((l2->val + c)%10);
                newNode->next = addingTwoNumbers(nullptr, l2->next, (l2->val + c)/10);
                return newNode;
            }
            else
                return l2;
        }
        else if(l2 == nullptr) {
            cout << "List 2 ended" << endl;
            if(c){
                ListNode* newNode = new ListNode((l1->val + c)%10);
                newNode->next = addingTwoNumbers(l1->next, nullptr, (l1->val + c)/10);
                return newNode;
            }
            else
                return l1;
        }
        int sum = (l1->val + l2->val + c);
        ListNode* newNode = new ListNode(sum%10);
        newNode->next = addingTwoNumbers(l1->next, l2->next, sum/10);
        return newNode;
    }
};
ListNode* insertList(int range){
    ListNode* head = nullptr, *tail = nullptr, *ptr = nullptr;
    for(int i = 0; i < range; i++){
        int d;
        cout << "Enter data : ";
        cin >> d;
        ListNode* newNode = new ListNode(d);
        if(head == nullptr) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void displayList(ListNode* head){
    cout << "Provided list is : ";
    for(ListNode* ptr = head; ptr!=nullptr; ptr = ptr->next)
        cout << ptr->val << " ";
    cout << endl;
}
int main(){
    int range = -1, n;
    cout << "Enter range of list 1 : ";
    cin >> range;
    ListNode* head1 = insertList(range);
    cout << "Enter range of list 2 : ";
    cin >> range;
    ListNode* head2 = insertList(range);
    displayList(head1);
    displayList(head2);
    ListNode* newHead = Solution :: addTwoNumbers(head1, head2);
    cout << "new list is : ";
    for(ListNode* ptr = newHead; ptr!=nullptr; ptr = ptr->next)
        cout << ptr->val << " ";
    cout << endl;
}