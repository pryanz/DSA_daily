class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        MyDict = dict()
        for i in range(len(nums)):
            if(target - nums[i]) in MyDict:
                return [MyDict[target-nums[i]], i]
            MyDict[nums[i]] = i
        return []