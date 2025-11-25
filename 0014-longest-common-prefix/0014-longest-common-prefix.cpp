class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans = "";
        if (strs.empty()) return ans; // Handle empty input
        
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;
            for (int j = 1; j < strs.size(); j++) { // Corrected the loop variable from i to j
                if (i >= strs[j].length() || ch != strs[j][i]) { // Added boundary check for index i
                    match = false;
                    break;
                }
            }
            if (!match) {
                break;
            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;   
    }
};