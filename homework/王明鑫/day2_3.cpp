class Solution {
public:
    ListNode* start_head=NULL;//标记最后节点的坐标，在原函数中返回，作为head
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;//排除空链表
       reverseDiGui(head);//调用递归函数进行排序
       head->next=NULL;//为最初一个节点的next赋NULL值，即反向后的最后节点
       return start_head;
    }
    //新建立一个递归函数
    ListNode* reverseDiGui(ListNode* head){
        if(head->next!=NULL)reverseDiGui(head->next)->next=head;//向后传递，将后一个节点的next赋值为当前节点的指针
        else start_head=head;//标记最后节点坐标
        return head;//返回当前节点指针
    }
};