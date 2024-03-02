import java.util.*;
import java.io.*;

public class Q_977_SquaresOfASortedArray {
    public static int performBinarySearch(int[] nums) {
        int i = 0, j = nums.length - 1, mid = 0, result = nums.length;
        while (i <= j) {
            mid = (j - i) / 2 + i;
            if (nums[mid] >= 0) {
                j = mid - 1;
                result = mid;
            } else
                i = mid + 1;
        }
        return result;
    }

    public static int[] sortedSquares(int[] nums) {
        int i = performBinarySearch(nums), j = i - 1, n = nums.length, k = 0;
        int result[] = new int[n];
        while (i < n && j >= 0)
            result[k++] = Math.abs(nums[i]) < Math.abs(nums[j]) ? nums[i] * nums[i++] : nums[j] * nums[j--];
        while (i < n)
            result[k++] = nums[i] * nums[i++];
        while (j >= 0)
            result[k++] = nums[j] * nums[j--];
        return result;
    }

    public static void main(String argsp[]) {

    }
};
