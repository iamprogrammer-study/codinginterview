class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {val = x;}
}

public class Ghost_AddTwoNumbers {

    public static ListNode addTwoNumbers(ListNode firstListNode, ListNode secondListNode) {
        ListNode solutionListNode = null;
        ListNode currentListNode = null;
        int carry = 0;
        int sum = 0;
        while (firstListNode != null && secondListNode != null) {
            sum = carry + firstListNode.val + secondListNode.val;
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
            firstListNode = firstListNode.next;
            secondListNode = secondListNode.next;
        }
        while (firstListNode != null) {
            sum = carry + firstListNode.val;
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
            firstListNode = firstListNode.next;
        }
        while (secondListNode != null) {
            sum = carry + secondListNode.val;
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
            secondListNode = secondListNode.next;
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
