class Solution {
public:
    int MAX_WIDTH;
    string helper(int i, int j, int fillSpaceCount, int extraSpaces,
                  vector<string>& words) {
        string line;
        for (int k = i; k < j; k++) {
            line += words[k];
            if (k == j - 1)
                continue;
            for (int z = 1; z <= fillSpaceCount; z++) {
                line += " ";
            }

            if (extraSpaces > 0) {
                line += " ";
                extraSpaces--;
            }
        }
        while (line.length() < MAX_WIDTH) {
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i = 0;
        while (i < n) {
            int charCount = words[i].length();
            int j = i + 1;
            int spaces = 0;

            while (j < n &&
                   words[j].length() + 1 + charCount + spaces <= maxWidth) {
                charCount += words[j].length();
                spaces += 1;
                j++;
            }
            int remainingSpaces = maxWidth - charCount;
            int fillSpaceCount = spaces == 0 ? 0 : remainingSpaces / spaces;
            int extraSpaces = spaces == 0 ? 0 : remainingSpaces % spaces;
            if (j == n) {
                fillSpaceCount = 1;
                extraSpaces = 0;
            }
            ans.push_back(helper(i, j, fillSpaceCount, extraSpaces, words));
            i = j;
        }
        return ans;
    }
};