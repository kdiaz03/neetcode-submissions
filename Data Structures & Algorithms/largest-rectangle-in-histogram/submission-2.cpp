class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        std::stack<std::pair<int, int>> hStack;

        for( int i = 0; i < heights.size(); i++ ) {
            int start = i;
            while( !(hStack.empty()) && (hStack.top().second > heights[i]) ) {
                int index = hStack.top().first;
                int height = hStack.top().second;
                hStack.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }

            hStack.push({start, heights[i]});
        }

        while( !hStack.empty() ) {
            int idx = hStack.top().first;
            int hgt = hStack.top().second;

            hStack.pop();

            maxArea = max(maxArea, hgt * (static_cast<int>(heights.size()) - idx));
        }
        
        return maxArea;
    }
};
