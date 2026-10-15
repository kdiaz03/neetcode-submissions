class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<std::pair<int, int>> tempStack;
        vector<int> result(temperatures.size(), -1);

        for( int i = 0; i < temperatures.size(); i++ ) {
            int currTemp = temperatures[i];

            while( !tempStack.empty() ) {
                int idx = tempStack.top().first;
                int temp = tempStack.top().second;

                if( currTemp > temp ) {
                    result[idx] = i - idx;
                    tempStack.pop();
                } else {
                    break;
                }
            }

            tempStack.push({i, currTemp});
        }

        int prevIdx = -1;
        int prevTemp = -1;
        while (!tempStack.empty()) {
            int idx = tempStack.top().first;
            int temp = tempStack.top().second;

            tempStack.pop();

            if( temp < prevTemp ) {
                result[idx] = prevIdx - idx;
            } else {
                result[idx] = 0;
                prevIdx = idx;
                prevTemp = temp;
            }
        }

        return result;
    }
};
