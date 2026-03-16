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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* sortedhead = head;
        ListNode* current = head -> next;
        sortedhead -> next = nullptr;  // 先把sorted list切開
        while(current != nullptr)
        {
            ListNode* nexttemp = current -> next;
            if (current -> val < sortedhead -> val)
            {
                current -> next = sortedhead;
                sortedhead = current;
            }   
            else 
            {
                ListNode* p = sortedhead;
                while(p -> next != nullptr && p -> next -> val < current -> val)
                {
                    p = p -> next;
                }
                current -> next = p -> next;
                p -> next = current;
            }
            current = nexttemp;
        }
    return sortedhead;
    }
};