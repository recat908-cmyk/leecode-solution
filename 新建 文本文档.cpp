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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        //我们最主要的问题是两个指针同步走，不能保证它们到达相交部分时处于同一个步数
            //那就让他们相交时的步数一样，两条都走一遍
        ListNode* A = headA, * B = headB;
        //相交点是n，都走一遍，确保相交时总路数相同，要么指向n，要么nullptr。
        while (A != B)
        {
            A = A != nullptr ? A->next : headB; //A走完，走B的。
            B = B != nullptr ? B->next : headA;
        }
        //A != nullptr ? A->next : A->headB是错的
        //A==nullptr的话，是空指针，不能去访问，所以直接A=headB。

        return A;

    }
};