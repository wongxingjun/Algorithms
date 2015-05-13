class Solution:
	# @param {integer[]} nums
	# @return {integer}
	def singleNumber(self, nums):
		dic={}
		for i in nums:
			if i not in dic:
				dic[i]=1
			else:
				dic[i]+=1
			for e in dic:
				if dic[e]==1:
					return e
