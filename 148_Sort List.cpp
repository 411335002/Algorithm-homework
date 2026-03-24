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
    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = middle(head);
        ListNode* right = mid->next;
        mid->next = nullptr; //切斷
        ListNode* L = sortList(head);
        ListNode* R = sortList(right);
        return merge(L,R);
    }
    // fast 每次走兩步，slow 每次走一步
    ListNode* middle(ListNode* head)
    {
        ListNode*  slow=head;
        ListNode*  fast=head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* merge(ListNode* L,ListNode* R)
    {
        if(L == nullptr) 
            return R;
        if(R == nullptr) 
            return L;
        ListNode* head;
        if (L -> val < R -> val)
        {
            head = L;
            L = L -> next;
        }
        else
        {
            head = R;
            R = R -> next;
        }
        ListNode* tail = head;
        while (L != nullptr && R != nullptr)
        {
            if (L -> val < R -> val)
            {
                tail -> next = L;
                L = L -> next;
            }
            else
            {
                tail -> next = R;
                R = R -> next;
            }
            tail = tail -> next;
        }
        if (L != nullptr)
            tail -> next = L;
        if (R != nullptr)
            tail -> next = R;
        return head;
    }
};
