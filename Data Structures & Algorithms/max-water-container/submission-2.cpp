class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;

        int maxArea = 0;

        while( left < right ) {
            int base = right - left;
            int height = min(heights[left], heights[right]);

            maxArea = max(maxArea, base * height);

            if( (heights[left]) >= heights[right] ) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea; 
    }
};
