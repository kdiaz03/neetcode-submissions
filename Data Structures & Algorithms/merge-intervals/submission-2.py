class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        output = []

        for interval in intervals:
            if not output:
                output.append(interval)
                continue
            
            curr_start = interval[0]
            curr_end = interval[1]

            prev_start = output[-1][0]
            prev_end = output[-1][1]

            if( curr_start <= prev_end ):
                new_end = max(prev_end, curr_end)
                new_interval = [prev_start, new_end]
                output[-1] = new_interval
            else:
                output.append(interval)
        
        return output
            