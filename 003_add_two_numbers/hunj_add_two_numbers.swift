import Cocoa

/// Definition for singly-linked list.
public class ListNode {
	public var val: Int
	public var next: ListNode?
	public init(_ val: Int) {
		self.val = val
		self.next = nil
	}
}

class Solution {
	/**
	iterates through the two given linkedlist and add each positioning node's values.
	if either list is shorter, the iteration will only last until the shorter list.
	*/
	func addTwoNumbers(l1: ListNode?, _ l2: ListNode?) -> ListNode? {
		/// some pointer setup...
		var iterator1 = l1
		var iterator2 = l2
		
		/// list to return
		let answerList = ListNode(0)	// the "head" is a dummy node that has value of 0
		var answerIter = answerList
		
		/// boolean to determine whether there was a carry in previous iteration
		var isCarry = false
		
		while iterator1 != nil && iterator2 != nil {
			// set up a variable that is a temporary result of adding the two values
			var newValue = iterator1!.val + iterator2!.val
			print(newValue)
			
			// if the previous digit calculation has a carry, add 1 and switch back the status
			if isCarry {
				newValue += 1
				isCarry = false
			}
			
			// if the resulting value is greater than 10, set up a carry flag (overflow) and keep the digit
			if newValue >= 10 {
				isCarry = true
				newValue = newValue - 10
			}
			
			// append the result as a node
			answerIter.next = ListNode(newValue)
			
			// advance the two iterators
			iterator1 = iterator1?.next
			iterator2 = iterator2?.next
			
			answerIter = answerIter.next!
		}
		
		// return the answer list, but omitting the dummy head node that has value of 0
		return answerList.next
	}
	
	func stringOf(list: ListNode?) -> String {
		var returnString = ""
		var iterator = list
		while iterator != nil {
			returnString += String(iterator!.val)
			iterator = iterator!.next
		}
		return returnString
	}
}



/// some testing here
let s = Solution()

let some1_1 = ListNode(2)
let some1_2 = ListNode(4)
let some1_3 = ListNode(3)
some1_1.next = some1_2
some1_1.next!.next = some1_3
print(s.stringOf(some1_1))	// 243

let some2_1 = ListNode(5)
let some2_2 = ListNode(6)
let some2_3 = ListNode(4)
some2_1.next = some2_2
some2_1.next!.next = some2_3
print(s.stringOf(some2_1))	// 564

/// actual usage:
s.addTwoNumbers(some1_1, some2_1)

print(s.stringOf(s.addTwoNumbers(some1_1, some2_1))) // print it out to make sure, "708"
