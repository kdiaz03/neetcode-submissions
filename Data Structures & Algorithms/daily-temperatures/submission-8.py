class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        temp_stack = []
        result = [0 for _ in range(len(temperatures))]

        for i, temp in enumerate(temperatures):
            while temp_stack and temp > temp_stack[-1][1]:
                k = temp_stack[-1][0]
                result[k] = i - k
                temp_stack.pop()
            
            temp_stack.append((i, temp))

        return result