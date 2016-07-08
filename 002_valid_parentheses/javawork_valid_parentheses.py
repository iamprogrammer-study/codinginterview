start_ps = ['(','{','[']
end_ps = [')','}',']']

def isStart(c):
	return c in start_ps

def getStartPs(c):
	if c not in end_ps:
		return ''
	idx = end_ps.index(c)
	return start_ps[idx]

def isValid(str):
	stack = []
	for c in str:
		if isStart(c):
			stack.append(c)
			continue
		if len(stack) == 0:
			return False
		elif getStartPs(c) == stack[len(stack)-1]:
			stack.pop()
		else:
			return False
	return len(stack) == 0

print isValid('[()]{}{}')
print isValid('[(){}]{]')
print isValid('[(){}]-{}')
