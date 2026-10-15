class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<std::pair<int, int>> tracking;

        for( int i = 0; i < temperatures.size(); i++ ) {
            int t = temperatures[i];

            while( !(tracking.empty()) && (t > tracking.top().second) ) {
                auto stackPair = tracking.top();
                res[stackPair.first] = ( i - stackPair.first );
                tracking.pop();
            }

            tracking.push({i, t});
        }

        return res;
    }
};
