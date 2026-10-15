class Solution {
public:
    int trap(vector<int>& height) {
        if( height.size() <= 0 ) { return 0; }

        int l = 0;
        int r = static_cast<int>( height.size() ) - 1;

        int maxL = height[l];
        int maxR = height[r];

        int water = 0;

        while( l < r ) {
            if( maxL < maxR ) {
                l = l + 1;
                maxL = max(maxL, height[l]);
                water = water + ( maxL - height[l] );
            } else {
                r = r - 1;
                maxR = max(maxR, height[r]);
                water = water + (maxR - height[r]);
            }
        }

        return water;
    }
};
