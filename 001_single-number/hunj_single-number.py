def singleNumber(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    dic = {}
    for num in nums:
        if num not in dic:
            dic[num] = True
        elif num in dic:
            dic[num] = False

    for that_number, appeared_only_once in dic.items():
        if appeared_only_once:
            return that_number