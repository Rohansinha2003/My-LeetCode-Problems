class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> output = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        int number = 1, left = 0, right = n - 1;
        while (left <= right) {
            if (left == right) {
                output[left][left] = number;
                break;
            }
            // from up ro right
            for (size_t i = left; i < right; ++i) {
                output[left][i] = number;
                ++number;
            }
            // from right to down
            for (size_t i = left; i < right; ++i) {
                output[i][right] = number;
                ++number;
            }
            // from down to left
            for (size_t i = right; i > left; --i) {
                output[right][i] = number;
                ++number;
            }
            // from left to up
            for (size_t i = right; i > left; --i) {
                output[i][left] = number;
                ++number;
            }
            ++left;
            --right;
        }
        return output;
    }
};