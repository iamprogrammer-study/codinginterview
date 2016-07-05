def singleNumber(nums):
    result = 0
    for v in nums:
        result = result^v
    return result
