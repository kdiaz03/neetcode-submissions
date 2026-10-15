#include <string>
#include <vector>
#include <cctype> // Required for std::isdigit

class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string encodedStr = "";

        for (const std::string& s : strs) {
            int s_size = s.length();
            encodedStr += std::to_string(s_size);
            encodedStr += "#";

            for (char c : s) {
                encodedStr += c; 
            }
        }
        return encodedStr;
    }

    // 15#wordherehbuhnjgr5#hello
    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded;

        int i = 0;
        while (i < (int)s.size()) {
            int strSize = 0;
            string sizeBuilder = "";
            while( std::isdigit( s[i] ) ) {
                sizeBuilder += s[i];
                i++;
            }

            strSize = std::stoi(sizeBuilder);
            if ( s[i] == '#') {
                decoded.push_back(s.substr(i + 1, strSize));
                i += 1 + strSize;
                continue;
            } else {
                i++;
            }
        }
        return decoded;
    }
};