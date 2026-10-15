class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<string>> groupings;
        
        for (int i = 0; i < strs.size(); i++) {
            int counts[26] = {0};
            
            for (char c : strs[i]) {
                counts[c - 'a']++;
            }
            
            std::string key;
            for (int n : counts) {
                key += std::to_string(n);
                key += "#";
            }
            
            groupings[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto& [key, val] : groupings) {
            result.push_back(std::move(val));
        }
        
        return result;
    }
};