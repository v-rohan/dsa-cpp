/**
 * https://www.interviewbit.com/problems/merge-k-sorted-lists/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minH;
    for(auto i: A){
        ListNode* node = i;
        while(node!=NULL){
            minH.push({node->val, node});
            node = node->next;
        }
    }
        ListNode* head = minH.top().second;
        ListNode* ptr = head;
        minH.pop();
        while(!minH.empty()){
            ptr->next = minH.top().second;
            ptr = ptr->next;
            minH.pop();
        }
        return head;
}
