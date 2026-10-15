class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupings;

        for( const string& s : strs ) {
            int counts[26] = {0};

            for( const char& c : s ) {
                counts[c - 'a']++;
            }

            string key;
            for( int n : counts ) {
                key += std::to_string(n) + "#";
            }

            groupings[key].push_back(s);
        }
        
        vector<vector<string>> results;

        for( auto& [key, val] : groupings ) {
            results.push_back(std::move(val));
        }

        return results;
    }
};
