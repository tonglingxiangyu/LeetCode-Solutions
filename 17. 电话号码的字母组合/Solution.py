class Solution:
    def backtracking(self, start, k, path, ans, digits, num_map):
        if len(path) == k:
            ans.append(path[:])
            return
        for alpha in num_map[digits[start]]:
            path += alpha
            self.backtracking(start+1, k, path, ans, digits, num_map)
            path = path[:-1]

    def letterCombinations(self, digits: str) -> List[str]:
        num_map = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        path = ''
        ans = []
        if not digits:
            return ans
        self.backtracking(0, len(digits), path, ans, digits, num_map)
        return ans