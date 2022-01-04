
// 2. Add Two Numbers

// given two reversed numbers in the form of linked list, return their sum in similer format
// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumHead=NULL, *temp=NULL;
        int carry=0;
      
        while(l1 or l2 or carry){
            if(l1){
                carry+=(l1->val);
                l1=l1->next;
            }
            if(l2){
                carry += (l2->val);
                l2=l2->next;
            }
            
            ListNode* node = new ListNode(carry%10);
            carry/=10;
            
            if(!sumHead){                                         // head node of the sum
                sumHead=node;
                temp= sumHead;
            }
            else{
                temp->next=node;
                temp=temp->next;
            } 
            
        }
        
        return sumHead;
    }
};
