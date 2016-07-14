class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {val = x;}
}

public class Ghost_AddTwoNumbers {

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode solutionListNode = null;
        ListNode currentListNode = null;
        int carry = 0;
        int sum = 0;
        while (l1 != null && l2 != null) {
            sum = carry + l1.val + l2.val;
            carry = sum / 10;
            ListNode newListNode = new ListNode(sum % 10);
            if (solutionListNode == null) {
                solutionListNode = newListNode;
                currentListNode = newListNode;
            }
            else {
                currentListNode.next = newListNode;
                currentListNode = newListNode;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            sum = carry + l1.val;
            carry = sum / 10;
            ListNode newListNode = new ListNode(sum % 10);
            if (solutionListNode == null) {
                solutionListNode = newListNode;
                currentListNode = newListNode;
            }
            else {
                currentListNode.next = newListNode;
                currentListNode = newListNode;
            }
            l1 = l1.next;
        }
        while (l2 != null) {
            sum = carry + l2.val;
            carry = sum / 10;
            ListNode newListNode = new ListNode(sum % 10);
            if (solutionListNode == null) {
                solutionListNode = newListNode;
                currentListNode = newListNode;
            }
            else {
                currentListNode.next = newListNode;
                currentListNode = newListNode;
            }
            l2 = l2.next;
        }
        if (carry > 0) {
            ListNode newListNode = new ListNode(carry);
            currentListNode.next = newListNode;
            currentListNode = newListNode;
        }
        return solutionListNode;
    }

    public static void printList(ListNode listNode) {
        StringBuilder sb = new StringBuilder();
        if (listNode != null) {
            sb.append(listNode.val);
        }
        while (listNode.next != null) {
            listNode = listNode.next;
            sb.append(" -> ").append(listNode.val);
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) {

        final ListNode firstListNode = new ListNode(3);
        firstListNode.next = new ListNode(4);
        firstListNode.next.next = new ListNode(2);
        //printList(firstListNode);

        final ListNode secondListNode = new ListNode(4);
        secondListNode.next = new ListNode(6);
        secondListNode.next.next = new ListNode(5);
        //printList(secondListNode);

        final ListNode solutionListNode = addTwoNumbers(firstListNode, secondListNode);

        printList(solutionListNode);
    }
}
