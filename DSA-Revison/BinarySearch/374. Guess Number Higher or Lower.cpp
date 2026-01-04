/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number guess(MID) < mid
 *			      1 if num is lower than the picked number  guess(MID) > mid
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == -1) {
                // require no sai bada hai mid
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};