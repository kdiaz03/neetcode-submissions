class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyHash;

        for (int n : nums) {
            frequencyHash[n]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        for( auto const& [val, freq] : frequencyHash ) {

            if( minHeap.size() < k ) {
                minHeap.push( {freq, val} );
            } else if( freq > minHeap.top().first ) {
                minHeap.pop();
                minHeap.push( {freq, val} );
            }
        }

        std::vector<int> result;
        int heapSize = minHeap.size();
        for( int i = 0; i < heapSize; i++ ) {
            result.push_back( minHeap.top().second );
            minHeap.pop();
        }

        return result;
    }
};
