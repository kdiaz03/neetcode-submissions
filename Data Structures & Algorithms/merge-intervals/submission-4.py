class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        output = []

        for interval in intervals:
            if not output:
                output.append(interval)
            
            curr_start = interval[0]
            curr_end = interval[1]

            prev_start = output[-1][0]
            prev_end = output[-1][1]

            if prev_end >= curr_start:
                output[-1] = [prev_start, max(prev_end, curr_end)]
            else:
                output.append(interval)

        return output