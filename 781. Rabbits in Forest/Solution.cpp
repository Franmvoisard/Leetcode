// Time: O(n)
// Space: O(n)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> frequencies;
        int answer = 0;
        for (int i = 0; i < answers.size(); i++) {
            frequencies[answers[i]]++;
        }

        for (auto& [key, value] : frequencies) {
            if (key != 0) {
                int rabbitGroupSize = key + 1;
                answer += ceil(1.0 * value / rabbitGroupSize) * rabbitGroupSize;
            } else {
                answer += value;
            }
        }
        return answer;
    }
};
