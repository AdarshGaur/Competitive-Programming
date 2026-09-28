import java.util.*;

/** Binary search on an ascending sorted array: O(log n) time, O(1) space. */
public class SortingAndSearching {
    public static int lowerBound(int[] a, int target) { // First index with a[i] >= target, or n.
        int left = 0, right = a.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    public static int upperBound(int[] a, int target) { // First index with a[i] > target, or n.
        int left = 0, right = a.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    public static int binarySearch(int[] a, int target) {
        int index = lowerBound(a, target);
        return index < a.length && a[index] == target ? index : -1;
    }
    public static void main(String[] args) {
        int[] a = {5, 2, 1, 2};
        Arrays.sort(a);
        System.out.println(Arrays.toString(a)); // [1, 2, 2, 5]
        System.out.println(lowerBound(a, 2)); // 1
        System.out.println(upperBound(a, 2)); // 3
        // Comparator sorting needs objects, not int[].
        Integer[] descending = {1, 5, 2};
        Arrays.sort(descending, Comparator.reverseOrder());
        System.out.println(Arrays.toString(descending)); // [5, 2, 1]
    }
}
