class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<std::pair<int, int>> tempStack;
        vector<int> result(temperatures.size(), 0);

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

        return result;
    }
};