#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {};
};
class Solution{
public:
    //EXTREME BRUTE - FORCE T.C. - O(N) S.C. - O(N)
    static ListNode* segregate(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* ptr = head;
        for(ptr = head; ptr!=NULL; ptr = ptr->next)
            arr.push_back(ptr->val);
        dutchFlagAlgo(arr);
        int i;
        for(ptr = head, i = 0; ptr!=NULL; ptr = ptr->next, i++)
            ptr->val = arr[i];
        return head;
    }
    static void dutchFlagAlgo(vector<int>& arr){
        int l = 0, m = 0, h = arr.size() - 1;
        while(m < h){
            if(arr[m] == 2){
                swap(arr[h], arr[m]);
                m++, h--;
            }
            else if(arr[m] == 1)
                m++;
            else if(arr[m] == 0){
                swap(arr[l], arr[m]);
                m++, l++;
            }
        }
    }
    static ListNode* segregate2(ListNode* head){
        if(head == NULL && head->next == NULL)  return head;
        ListNode* fHead = NULL, *sHead = NULL, *tHead = NULL;
        ListNode* fTail = NULL, *sTail = NULL, *tTail = NULL;
        ListNode* ptr = head;
        while(ptr != NULL){
            ListNode* temp = NULL;
            if(ptr->val == 0){
                if(fHead == NULL)
                    fTail = fHead = ptr;
                else{
                    fTail->next = ptr;
                    fTail = ptr;
                }
                temp = ptr->next;
                ptr->next = NULL;
            }
            else if(ptr->val == 1){
                if(sHead == NULL)
                    sTail = sHead = ptr;
                else{
                    sTail->next = ptr;
                    sTail = ptr;
                }
                temp = ptr->next;
                ptr->next = NULL;
            }
            else{
                if(tHead == NULL)
                    tTail = tHead = ptr;
                else{
                    tTail->next = ptr;
                    tTail = ptr;
                    
                }
                temp = ptr->next;
                ptr->next = NULL;
            }
            ptr = temp;
        }
        if(fHead!=NULL && sHead !=NULL) fTail->next = sHead;
        if(sHead!=NULL && tHead !=NULL) sTail->next = tHead;
        if(sHead==NULL && (fHead!=NULL && tHead!=NULL)) fTail->next = tHead;
        if(fHead != NULL) return fHead;
        if(sHead != NULL) return sHead;
        return tHead;
    }
};
int main(){
    int range = -1;
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
    ListNode* newHead = Solution :: segregate2(head);
    cout << "Sorted list is : ";
    for(ptr = newHead; ptr!=NULL; ptr = ptr->next)
        cout << ptr->val << " ";
    cout << endl;
}