/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {

public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int result = 0;
        
        while(left <= right){
            int midpoint = left + (right - left) / 2;
            int guessResult = guess(midpoint);

            if(guessResult == 0) {
                result = midpoint;
                break;
            }

            if(guessResult > 0){ // Higher
                left = midpoint + 1;
            }
            else {
                right = midpoint - 1;
            }
        }
        return result;
    }
};
