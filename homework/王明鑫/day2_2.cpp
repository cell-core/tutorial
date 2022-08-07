class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *next_this=head->next;
        int num=0;//计数
        ListNode *last=new ListNode[30];//设定存储链表的数组，分配空间
        
        last[0].next=head;
        while(next_this!=NULL){
            num++;
            last[num].next=next_this; //将链表节点依次存入数组中，方便从后方索引           
            next_this=next_this->next;           
        }
        if(num==0){
            return NULL;//排除空链表
        }
        else if((num-n)==-1){
            return last[1].next;//排除单节点链表
        }
        else{
        last[num-n].next->next=last[num-n+1].next->next;//索引
        }
        return head;
    }
};
