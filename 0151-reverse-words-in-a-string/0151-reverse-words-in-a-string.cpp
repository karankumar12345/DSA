class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim leading and trailing spaces
        int left = 0;
        int right = s.size() - 1;

        while (left <= right && s[left] == ' ')
            left++;
        while (left <= right && s[right] == ' ')
            right--;

        // Step 2: Split words and reverse the order

        vector<string> words;
        string word;

        while (left <= right) {
            char c = s[left];
            if (c != ' ') {
                word += c;

            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            left++;
        }

        if (!word.empty())
            words.push_back(word); // Add the last word

        // Step 3: Join words in reverse order
        reverse(words.begin(), words.end());
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1)
                result += " "; // Add a space between words
        }

        return result;
    }
};