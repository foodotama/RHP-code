import java.util.*;

public class Code11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefixSum = 0;
        int maxLength = 0;
        map.put(0, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                prefixSum--;
            else
                prefixSum++;

            if (map.containsKey(prefixSum)) {
                maxLength = Math.max(maxLength,
                                     i - map.get(prefixSum));
            } else {
                map.put(prefixSum, i);
            }
        }

        System.out.println(maxLength);
    }
}
