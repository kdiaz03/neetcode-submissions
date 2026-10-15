class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> counts;

        for (int n : nums) {
            if ( counts.count(n) ) {
                return true;
            } else {
                counts[n] = 1;
            }
        }

        return false;
    }
};