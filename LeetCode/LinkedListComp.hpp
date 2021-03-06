// We are given head, the head node of a linked list containing unique integer values.

// We are also given the list G, a subset of the values in the linked list.

// Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

// Example 1:

// Input: 
// head: 0->1->2->3
// G = [0, 1, 3]
// Output: 2
// Explanation: 
// 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
// Example 2:

// Input: 
// head: 0->1->2->3->4
// G = [0, 3, 1, 4]
// Output: 2
// Explanation: 
// 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s(G.begin(),G.end());
        
        int res = 0;
        ListNode* cur = head;
        while(cur)
        {
            if(s.find(cur->val)!=s.end())
            {
                res++;
                while(cur && s.find(cur->val)!=s.end())
                    cur = cur->next;
            }
            else
                cur = cur->next;
        }
        return res;
    }
};


// #method 2
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s(G.begin(),G.end());
        
        int res = 0, flag=0;
        ListNode* cur = head;
        while(cur)
        {
            if(s.count(cur->val) && !flag)
            {
                res++;
                flag = 1;
            }
            else if(!s.count(cur->val) && flag)
                flag = 0;
            
            cur = cur->next;
        }
        return res;
    }