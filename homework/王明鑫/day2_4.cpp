class Solution {
public:
//用函数本身进行递归，单个函数的作用为比较list1和list2的大小，并返回较小的值
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //当任意链表索引结束，结束递归
        if(list1==NULL||list2==NULL){
            if(list1==NULL)return list2;
            else return list1;
        };
        //进行两次比较，第一次比较当前list1和list2
        if(list1->val<list2->val){
        list1->next=mergeTwoLists(list1->next,list2);//再对较小的一方同本身的下一节点和另一节点比较，指向较小一方
        return list1;//递归的最后返回最小值，即head
        }
        else {
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
        }
    }
};