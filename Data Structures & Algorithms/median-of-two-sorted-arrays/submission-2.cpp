class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure A is the smaller array to keep binary search O(log(min(m, n)))
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if (B.size() < A.size()) return findMedianSortedArrays(nums2, nums1);

        int m = A.size();
        int n = B.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int l = 0;
        int r = m; // Range is 0 to m (number of elements to take from A)

        while (l <= r) {
            int i = l + (r - l) / 2; // Midpoint for A
            int j = half - i;        // Remaining elements from B

            // Boundary values
            int aLeft = (i > 0) ? A[i - 1] : INT_MIN;
            int aRight = (i < m) ? A[i] : INT_MAX;
            int bLeft = (j > 0) ? B[j - 1] : INT_MIN;
            int bRight = (j < n) ? B[j] : INT_MAX;

            // Check if partition is correct
            if (aLeft <= bRight && bLeft <= aRight) {
                // Odd total
                if (total % 2 != 0) {
                    return static_cast<double>(max(aLeft, bLeft));
                }
                // Even total
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            } 
            else if (aLeft > bRight) {
                r = i - 1; // Take fewer elements from A
            } 
            else {
                l = i + 1; // Take more elements from A
            }
        }
        return 0.0;
    }
};