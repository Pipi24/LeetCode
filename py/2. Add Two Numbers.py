# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 初始化一个新链表
        head = tail = ListNode(0)
        # 进位
        carry = 0
        # l1、l2其中之一未遍历完，将l1和l2相加
        # or carry是为了排除两个链表均只有一个节点并且循环完后carry为0，如[5][5]
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            # 将carry对10取余得到该位的值加入到新链表中
            tail.next = ListNode(carry % 10)
            tail = tail.next
            # 将carry对10取整得到向上一位的进位，实际上只能为0或1
            # carry //= 10 是python3写法
            carry //= 10
        return head.next
