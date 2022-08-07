class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;//复制下一个节点的数据
        node->next=node->next->next;//复制下一个节点的next指针
    }
};