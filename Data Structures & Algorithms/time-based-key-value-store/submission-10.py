class TimeMap:

    def __init__(self):
        self.time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.time_map:
            self.time_map[key].append((value, timestamp))
        else:
            self.time_map[key] = [(value, timestamp)]


    def get(self, key: str, timestamp: int) -> str:
        values = self.time_map.get(key, [])
        left, right = 0, len(values) - 1

        result = ""

        while left <= right:
            mid = int(left + (right - left) / 2)
            if values[mid][1] <= timestamp:
                result = values[mid][0]
                left = mid + 1
            else:
                right = mid - 1
            
        return result

        