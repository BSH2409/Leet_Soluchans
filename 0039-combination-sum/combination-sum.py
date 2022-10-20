class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans=[]
        temp=[]
        def help(index, target):
            if index == len(candidates):
                if target == 0: 
                    ans.append(temp.copy())
                return
            if candidates[index] <= target:
                temp.append(candidates[index])
                help(index, target - candidates[index])
                temp.pop()
            help(index + 1, target)
            return ans
        help(0, target)
        return ans