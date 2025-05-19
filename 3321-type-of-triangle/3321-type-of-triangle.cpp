class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Ensure input has exactly 3 sides
        if (nums.size() != 3) {
            return "Not a Triangle";
        }
        
        // Copy and sort sides
        int sides[3] = {nums[0], nums[1], nums[2]};
        sort(sides, sides + 3);
        
        // Check triangle inequality
        if (sides[0] + sides[1] <= sides[2]) {
            return "none";
        }
        
        // Check type of triangle
        if (sides[0] == sides[1] && sides[1] == sides[2]) {
            return "equilateral";
        } 
        else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]) {
            return "isosceles";
        } 
        else {
            return "scalene";
        }
    }
};
