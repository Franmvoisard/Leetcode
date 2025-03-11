struct ABCFrequencyMap {
private:
    int frequencies[3] = {0,0,0};
    int getIndexByChar(char c) {
        switch (c) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        }
        return -1;
    }

public:
    inline void decrementFrequency(char c) {
        frequencies[getIndexByChar(c)]--;
    }

    inline void incrementFrequency(char c) {
        frequencies[getIndexByChar(c)]++;
    }

    inline bool allElementsPresent() {
        bool result = true;
        for (int i = 0; i < 3; i++) {
            if (frequencies[i] == 0) {
                result = false;
                break;
            }
        }
        return result;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        int left = 0;
        ABCFrequencyMap frequencyMap; // A B C

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];
            frequencyMap.incrementFrequency(currentChar);
            
            while (frequencyMap.allElementsPresent()){
                result += s.size() - right;
                char characterToRemove = s[left];
                frequencyMap.decrementFrequency(characterToRemove);
                left++;
            }
        }
        return result;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
};
