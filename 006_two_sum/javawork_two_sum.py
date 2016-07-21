def twoSum(nums, target):
	d = dict()
	for i,v in enumerate(nums):
		sub = target - v
		if sub in d.keys():
			return [i,d[sub]]
		else:
			d[v] = i
	return []

print twoSum([2,1,4,7,9], 6)
print twoSum([5,2,6,7,1,10], 17)
print twoSum([5,2,6,7,1,10], 18)
