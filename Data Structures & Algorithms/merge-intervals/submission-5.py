class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        output = [intervals[0]]

        for start, end in intervals:
            prev_end = output[-1][1]

            if prev_end >= start:
                output[-1][1] = max(prev_end, end)
            else:
                output.append([start, end])
            
        return output