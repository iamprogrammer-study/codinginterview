class ListNode(object):
	def __init__(self, x):
		self.val = x;
		self.next = None

def printNode(head):
	runner = head
	while runner != None:
		print runner.val , ' ->',
		runner = runner.next
	print 

def addTwoNumbers(l1, l2):
	runner1 = l1
	runner2 = l2
	result_head = ListNode(0)
	result_runner = result_head
	carry = 0
	while runner1 or runner2 or carry > 0:
		sum = carry
		if runner1:
			sum = sum + runner1.val
			runner1 = runner1.next
		if runner2:
			sum = sum + runner2.val
			runner2 = runner2.next
		carry = sum/10
		result_runner.next = ListNode(sum%10)
		result_runner = result_runner.next
	return result_head.next

a = ListNode(2)
a.next = ListNode(4)
a.next.next = ListNode(3)
b = ListNode(5)
b.next = ListNode(6)
b.next.next = ListNode(4)
result = addTwoNumbers(a, b)
printNode(result)
