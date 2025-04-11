class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i = low; i <= high; i++){
            if(i < 100) {
                if(i % 11 == 0) count++;
                else continue;
            }
            else if(i > 100 && i < 1000) {
                i = 1000;
                continue;
            }
            else {
                string numStr = to_string(i);
                int sumA = 0;
                int sumB = 0;
                int half = numStr.size() / 2;

                for(int j = 0; j < half; j++){
                    sumA += (numStr[j] - 48);
                    sumB += (numStr[j + half] - 48);
                }
                if(sumA == sumB) {
                    count++;
                }
            }
        }
        return count;
    }
};
