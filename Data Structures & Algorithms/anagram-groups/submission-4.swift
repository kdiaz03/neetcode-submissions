class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var groups = [[Int]:[String]]()
        
        for str in strs {
            var count = Array(repeating: 0, count: 26)

            for scalar in str.unicodeScalars {
                let index = Int(scalar.value - 97)
                count[index] += 1
            }

            groups[count, default: []].append(str)
        }

        return Array(groups.values)
    }
}