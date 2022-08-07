class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int num=1;
        ListNode* direct=head->next;
        ListNode* last=new ListNode[100001];//建立数组存储整个链表，便于索引
        last[1].next=head;
        while(direct!=NULL){
            num++;//计数
            last[num].next=direct;
            direct=direct->next;
        }
        for(int i=1;i<=(int)num/2;i++)
        {
            if(last[i].next->val!=last[num-i+1].next->val)//依次对相应位置进行比较，一但比较失败即返回false
            return false;
        }
        return true;//比较全部无误后返回true
    }
};