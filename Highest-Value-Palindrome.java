import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'highestValuePalindrome' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. INTEGER n
     *  3. INTEGER k
     */

    public static String highestValuePalindrome(String s, int n, int k) {
        char[] arr = s.toCharArray();
        boolean[] changed = new boolean[n];
        int left = 0, right = n - 1;
        int used = 0;

        while (left < right) {
            if (arr[left] != arr[right]) {
                if (arr[left] > arr[right])
                    arr[right] = arr[left];
                else
                    arr[left] = arr[right];
                changed[left] = changed[right] = true;
                used++;
            }
            left++;
            right--;
        }

        if (used > k) return "-1";

        int remain = k - used;
        left = 0;
        right = n - 1;

        while (left <= right) {
            if (left == right) {
                if (remain > 0 && arr[left] != '9') arr[left] = '9';
            } else {
                if (arr[left] != '9') {
                    if (changed[left] || changed[right]) {
                        if (remain >= 1) {
                            arr[left] = arr[right] = '9';
                            remain -= 1;
                        }
                    } else {
                        if (remain >= 2) {
                            arr[left] = arr[right] = '9';
                            remain -= 2;
                        }
                    }
                }
            }
            left++;
            right--;
        }

        return new String(arr);
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        String s = bufferedReader.readLine();

        String result = Result.highestValuePalindrome(s, n, k);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
