class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var diff = [Int: Int]()

        for (i, num) in nums.enumerated() {
            let delta = target - num
            if let matchIndex = diff[delta] {
                return [matchIndex, i]
            }
            diff[num] = i
        }
        return []
    }
}