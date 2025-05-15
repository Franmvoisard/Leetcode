// Time Complexity: O(n)
// Space complexity: O(k) k <= n & k: is number of group changes

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> answer;
        answer.emplace_back(words[0]);
        for(int i = 1; i < groups.size(); i++){
            if(groups[i] != groups[i-1]){
                answer.emplace_back(words[i]);
            }
        }
        return answer;
    }
};
