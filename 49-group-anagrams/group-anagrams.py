from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        HashMpp = defaultdict(list)
        for s in strs:
            s_sort = "".join(sorted(s))
            HashMpp[s_sort].append(s)
        
        return list(HashMpp.values())