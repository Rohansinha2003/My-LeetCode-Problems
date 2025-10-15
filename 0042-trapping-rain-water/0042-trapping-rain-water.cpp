class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    vector<int> left(n);

    // right[i] contains height of tallest bar to
    // the right of i'th bar including itself
    vector<int> right(n);

    int res = 0;

    // fill left array
    left[0] = height[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], height[i]);

    // fill right array
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], height[i]);

    // calculate the accumulated water element by element
    for (int i = 1; i < n - 1; i++) {
        int minOf2 = min(left[i], right[i]);
            res += minOf2 - height[i];
    }

    return res;
    }
};