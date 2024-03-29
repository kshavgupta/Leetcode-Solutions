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
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL, *ahead = NULL;
        while(curr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next, *t1 = NULL, *t2 = NULL;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *s = head, *e = reverse(slow);
        
        while(s && e){
            if(s == e){
                break;
            }
            t1 = s->next;
            t2 = e->next;
            s->next = e;
            e->next = t1;
            s = t1;
            e = t2;
        }
        
    }
};