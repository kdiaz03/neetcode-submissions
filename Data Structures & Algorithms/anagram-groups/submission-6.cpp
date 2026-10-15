class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if ( strs.size() == 1 ) {
            return { {strs[0]} };
        }

        std::unordered_map<std::string, vector<string>> groupings;

        for( int i = 0; i < strs.size(); i++ ) {
            int counts[26] = {0};

            for (char c : strs[i] ) {
                counts[c - 'a']++;
            }

            std::string key = "";
            for (int n : counts) {
                key += std::to_string(n) + "#";
            }

            if ( groupings.count(key) ) {
                groupings[key].push_back(strs[i]);
            } else {
                std::vector<std::string> anagrams = { strs[i] };
                groupings[key] = anagrams;
            }
        }

        vector<vector<string>> result;
        for (auto& [key, val] : groupings) {
            result.push_back(val);
        }

        return result;
    }
};
