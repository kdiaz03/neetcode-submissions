#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:

    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int n : nums) {
            counts[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        for (auto const& [num, freq] : counts) {
            minHeap.push({freq, num});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
