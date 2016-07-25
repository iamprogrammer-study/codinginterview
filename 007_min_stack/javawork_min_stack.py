class MinStack(object):
	def __init__(self):
		self.data = []
		self.mins = []

	def push(self, x):
		self.data.append(x)
		if len(self.mins) == 0 or x < self.getMin():
			self.mins.append(x)

	def pop(self):
		if len(self.data) == 0:
			return
		if self.top() == self.getMin():
			del self.mins[len(self.mins)-1]
		del self.data[len(self.data)-1]

	def top(self):
		if len(self.data) == 0:
			return None
		return self.data[len(self.data)-1]

	def getMin(self):
		if len(self.mins) == 0:
			return None
		return self.mins[len(self.mins)-1]

s = MinStack()
s.push(-2)
s.push(0)
s.push(-3)
print s.getMin()
s.pop()
print s.top()
print s.getMin()