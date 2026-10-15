class TimeMap {
public:

    unordered_map<string, vector<std::pair<int, string>>> timeMap;
    string previousKey;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if( timeMap.contains(key) ) {
            timeMap[key].push_back( {timestamp, value} ); 
        } else {
            vector<std::pair<int, string>> valuePair;
            valuePair.push_back( {timestamp, value} );
            timeMap[key] = valuePair;
        }

        previousKey = key;
    }
    
    string get(string key, int timestamp) {
        if( !timeMap.contains(key) ) {
            return "";
        }

        // if( key != previousKey ) {
        //     return "";
        // }

        vector<std::pair<int, string>> valuesList(timeMap[key].begin(), timeMap[key].end());

        int left = 0;
        int right = valuesList.size() - 1;

        int prevTimestamp = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if( valuesList[mid].first <= timestamp ) {
                prevTimestamp = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if( prevTimestamp != -1 ){
            return valuesList[prevTimestamp].second;
        } else {
            return "";
        }
    }
};
