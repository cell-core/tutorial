//这道题根据题意进行了投机取巧，但是确实在符合题意的情况下运行速度快，代码量少
class Solution {
public:
    bool hasCycle(ListNode *head) {
        for(int i=0;i<10002;i++){//10000为节点上限，超出上限后如果还能继续索引，说明存在环
            if(head==NULL)return false;
            head=head->next;           
        }
        return true;
    }
};



//如果要我按照中规中矩的方式来写，我第一个想法是存储在数组里，在反复索引，但显然过于臃肿，而实际上也是这样
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode* last=new ListNode[10001];
        int num=1;
        last[1].next=head;
        ListNode* direct=head->next;
        while(last[num].next->next!=NULL){
            num++;
            last[num].next=direct;//用数组存储链表
            direct=direct->next;
            for(int i=1;i<num;i++){//每次更新指针后进行反复比较
                if(last[num].next==last[i].next)return true;
            }
        }
        return false;
    }
};