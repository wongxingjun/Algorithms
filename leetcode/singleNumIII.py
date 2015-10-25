class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dict={}
        for i in nums:
            if i not in dict:
                dict[i]=1
            else:
                dict.pop(i)
        res=[]
        for i in dict:
            res.append(i)
        return res