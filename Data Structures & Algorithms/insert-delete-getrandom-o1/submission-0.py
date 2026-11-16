import random

class RandomizedSet:

    def __init__(self):
        self.rand_set = set()

    def insert(self, val: int) -> bool:
        if val in self.rand_set:
            return False
        
        self.rand_set.add(val)
        return True

    def remove(self, val: int) -> bool:
        if val in self.rand_set:
            self.rand_set.discard(val)
            return True
        
        return False

    def getRandom(self) -> int:
        rand_element = random.choice(tuple(self.rand_set))
        return rand_element

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()