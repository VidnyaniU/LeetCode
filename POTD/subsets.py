def subsets(self, nums):
        res = []
        self.n = len(nums)
        self.backtrack(res, 0, [], nums)
        return res
    
def backtrack(self, res, ind, curr, nums):
    if ind == self.n:
        res.append(curr[:])
        return
    self.backtrack(res, ind + 1, curr, nums)
    curr.append(nums[ind])
    self.backtrack(res, ind + 1, curr, nums)
    curr.pop()