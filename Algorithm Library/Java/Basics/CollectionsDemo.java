import java.util.*;

/** Common C++ STL equivalents. */
public class CollectionsDemo {
    public static void main(String[] args) {
        // vector<int> -> ArrayList<Integer>; arrays are faster for fixed-size numeric data.
        List<Integer> list = new ArrayList<>();
        list.add(30); list.add(10); list.add(20);
        Collections.sort(list);
        System.out.println(list); // [10, 20, 30]
        list.remove(Integer.valueOf(20)); // remove(1) would remove INDEX 1.

        // unordered_map / unordered_set -> HashMap / HashSet (expected O(1)).
        Map<String, Integer> frequency = new HashMap<>();
        frequency.put("java", frequency.getOrDefault("java", 0) + 1);
        System.out.println(frequency.get("java")); // 1
        Set<Integer> unique = new HashSet<>(list);
        System.out.println(unique.contains(10)); // true

        // set / map -> TreeSet / TreeMap (O(log n)); no indexed access or fast rank.
        NavigableSet<Integer> sorted = new TreeSet<>(list);
        System.out.println(sorted.ceiling(15)); // 30; null if no such element.
        System.out.println(sorted.floor(15)); // 10
        NavigableMap<Integer, String> map = new TreeMap<>();
        map.put(2, "two"); map.put(1, "one");
        System.out.println(map.firstKey()); // 1

        // queue, deque, stack -> ArrayDeque; prefer it to legacy Stack.
        Deque<Integer> queue = new ArrayDeque<>();
        queue.addLast(1); queue.addLast(2);
        System.out.println(queue.removeFirst()); // 1: FIFO
        queue.push(3);
        System.out.println(queue.pop()); // 3: LIFO

        // priority_queue -> PriorityQueue; Java defaults to a MIN-heap.
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int x : list) { minHeap.add(x); maxHeap.add(x); }
        System.out.println(minHeap.poll()); // 10
        System.out.println(maxHeap.poll()); // 30

        // Strings are immutable. Build output with StringBuilder; compare with equals.
        StringBuilder output = new StringBuilder();
        for (int x : list) output.append(x).append(' ');
        System.out.println(output.toString().trim()); // 10 30
        System.out.println("java".equals(new String("java"))); // true
    }
}
