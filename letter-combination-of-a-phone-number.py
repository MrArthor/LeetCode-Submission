class Solution3(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        def letterCombinationsRecu(result, digits, curr, n):
            if n == len(digits):
                result.append("".join(curr))
                return
            for choice in lookup[int(digits[n])]:
                curr.append(choice)
                letterCombinationsRecu(result, digits, curr, n+1)
                curr.pop()

        if not digits:
            return []
        result = []
        letterCombinationsRecu(result, digits, [], 0)
        return result

