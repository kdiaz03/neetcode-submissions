class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> pairs;
        for( int i = 0; i < position.size(); i++ ) {
            pairs.push_back( {position[i], speed[i]} );
        }
        std::sort(pairs.rbegin(), pairs.rend());

        std::stack<double> fleet;

        for( const auto& [position, speed] : pairs ) {
            double timeToTarget = static_cast<double>(target - position) / static_cast<double>(speed);

            if( !fleet.empty() && timeToTarget <= fleet.top() ) {
                continue;
            } else {
                fleet.push( timeToTarget );
            }
        }

        return static_cast<int>(fleet.size());
    }
};
