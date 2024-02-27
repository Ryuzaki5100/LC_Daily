import java.util.*;
import java.io.*;

class Q_735_AsteroidCollision {
    public static int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < asteroids.length; i++) {
            boolean skip = false;
            while (!s.empty() && s.peek() > 0 && asteroids[i] < 0) {
                if (s.peek() < Math.abs(asteroids[i]))
                    s.pop();
                else if (s.peek() > Math.abs(asteroids[i])) {
                    skip = true;
                    break;
                } else {
                    skip = true;
                    s.pop();
                    break;
                }
            }
            if (skip == true)
                continue;
            s.push(asteroids[i]);
        }
        int result[] = new int[s.size()];
        for (int i = s.size() - 1; i >= 0; i--)
            result[i] = s.pop();
        return result;
    }

    public static void main(String args[]) {
        int arr[] = { 10, 5, -5 };
        int res[] = asteroidCollision(arr);
        for (int i = 0; i < res.length; i++)
            System.out.printf("%d ", res[i]);
    }
};