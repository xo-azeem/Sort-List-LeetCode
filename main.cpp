// Code 

// Definition for a binary tree node.
/*
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution {
public:

    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
    
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};
