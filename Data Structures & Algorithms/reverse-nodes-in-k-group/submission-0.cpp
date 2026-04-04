/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k){
        k--;

        while(temp && k > 0){
            k--;
            temp = temp->next;
        }

        return temp;
    }

    void reverse(ListNode* head){

        ListNode* temp = head,*prev=NULL;

        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

       // return prev;


    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head, *prevLast=NULL;

        while(temp){

            ListNode* kthnode = getKthNode(temp,k);

            if(kthnode == NULL){

                if(prevLast)
                prevLast->next=temp;
                break;

            }

            ListNode* newnext = kthnode->next;

            kthnode->next = NULL;

            reverse(temp);

            if(head == temp) // first subarray
            {
                head = kthnode;
            }else{
                prevLast->next = kthnode;
            }

            prevLast = temp;
            temp = newnext;

        }

        return head;
    }
};