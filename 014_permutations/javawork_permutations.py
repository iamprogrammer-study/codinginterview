class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        sub_list = [[]]
        for v in nums:
            next_list = []
            for a in sub_list:
                tmp_list = self.get_permutation_impl(v, a)
                #print tmp_list
                next_list.extend(tmp_list)
            sub_list = next_list
            for a in sub_list:
                if len(a) == len(nums):
                    ans.append(a)
            #print sub_ans
        return ans
        
    def get_permutation_impl(self, c, arr):
        #print c, arr
        ans = []
        for i in range(len(arr)+1):
            sub_list = arr[:i]
            sub_list.append(c)
            sub_list.extend(arr[i:])
            ans.append(sub_list)
        return ans

s = Solution()
#print s.permute([1,2,3])
print s.permute([1,2,3,4])
