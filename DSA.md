-----------------------------
### Backtracking && Recursion
-----------------------------

1. Combination sum without dups and we can choose a number any number of times. Here TC -> O(N^(T/M)), T -> target sum, M -> smallest element, N->length of array (https://leetcode.com/problems/combination-sum/description/)
2. Combination sum with dups -> TC-O(n*2^n) (https://leetcode.com/problems/combination-sum-ii/description/)
    Note -> Consider combination sum with dups like combination sum without dups and choose an element multiple number of times. If we decide to not take an element then straight to the next distinct element. If we decide to take the element go to the next index. If it again contains the element take it 2 times.
3. Subset without duplicates (https://leetcode.com/problems/subsets/description/)
4. Subsets with duplicates (https://leetcode.com/problems/subsets-ii/description/)
5. Palindrome partitioning - Precompute DP to find string from i..j is a palindrome and not. TC->(n * 2^n). (https://leetcode.com/problems/palindrome-partitioning/description/)
6. Permutation sequence - Not a backtracking question but seems interesting (https://leetcode.com/problems/permutation-sequence/)
7. Inversion count
8. [NOT IMPORTANT skip if you want] Word break - II (https://leetcode.com/problems/word-break-ii/)
9. [Just analyse TC and SC otherwise NOT IMPORTANT] Combination sum 3 (https://leetcode.com/problems/combination-sum-iii/)
10. Permutation II  - find permutations of an array with dups - (https://leetcode.com/problems/permutations-ii/description/)
11. [Very difficult] Find Array from Given Subset Sums (https://leetcode.com/problems/find-array-given-subset-sums/description/)
12. N-queen - Lengthy, do it if you have time. We are using Bitset here (https://leetcode.com/problems/n-queens/description/)
13. Sudoko solver - Lengthy, do it if you have time. (https://leetcode.com/problems/sudoku-solver/submissions/1575765617/)
14. [NOT IMPORTANT skip if you want] Letter Combinations of a Phone Number (https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
15. [NOT IMPORTANT skip if you want] Restore IP Addresses (https://leetcode.com/problems/restore-ip-addresses/)
16. [SAME AS N-QUEEN-1] N-queen-2 (https://leetcode.com/problems/n-queens-ii/submissions/1576029867/)
17. Remove Invalid Parentheses (https://leetcode.com/problems/remove-invalid-parentheses/)
18. Maximum Score Words Formed by Letters (https://leetcode.com/problems/maximum-score-words-formed-by-letters/?envType=problem-list-v2&envId=bit-manipulation)
19. Palindrome Permutation II (https://algo.monster/liteproblems/267) [Solution](https://github.com/apoorvKautilya21/Data-Structures-And-Algorithm-in-C-/blob/main/13.%20Backtracking/8_palindromePermutation_2.cpp)
20. Expression Add Operators (https://leetcode.com/problems/expression-add-operators/description/)
21. Robot room cleaner (https://leetcode.com/problems/robot-room-cleaner/description/)



-----------------------------
### Meet in the middle
-----------------------------
1. Closest Subsequence Sum (https://leetcode.com/problems/closest-subsequence-sum/description/)


-----------------------------
### Divide and conqure
-----------------------------
1. (https://leetcode.com/problems/find-array-given-subset-sums/description/)


-----------------------------
### Graph
-----------------------------
1. Detect cycle in undirected graph (https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)
2. Detect cycle in Directed graph (https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTabValue=SUBMISSION)
3. Rotten oranges (https://leetcode.com/problems/rotting-oranges/)
4. [Easy] Rotten oranges (https://leetcode.com/problems/flood-fill/)
5. 01 Matrix (https://leetcode.com/problems/01-matrix/)
6. Surrounded regions (https://leetcode.com/problems/surrounded-regions/)
7. [Khatarnak question] Distinct Islands (https://www.naukri.com/code360/problems/distinct-islands_630460?leftPanelTabValue=PROBLEM)
8. Bipartite graph (https://leetcode.com/problems/is-graph-bipartite/submissions/1580155650/)
9. Find eventual states (https://leetcode.com/problems/find-eventual-safe-states/)
10. Course schedule I (https://leetcode.com/problems/course-schedule/description/)
11. Course schedule II (https://leetcode.com/problems/course-schedule-ii/description/)
12. Alien dictionary (https://www.naukri.com/code360/problems/alien-dictionary_630423?leftPanelTabValue=PROBLEM)
    12.1 Follow ups - when can it be invalid
    12.2 if abcd comes before abc
    12.3 Cycle in graph
13. Shortest path in DAG (https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897)
14. Shortest Path Visiting All Nodes - BFS, BEAUTIFUL (https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/)
15. Word ladder (https://leetcode.com/problems/word-ladder/)
16. Word ladder II (https://leetcode.com/problems/word-ladder-ii/)
17. [SKIP IF YOU WANT] Shortest Distance in a Binary Maze (https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1)
18. [Dijkstra] Path With Minimum Effort (https://leetcode.com/problems/path-with-minimum-effort/description/)
19. Cheapest flights with k stops (https://leetcode.com/problems/cheapest-flights-within-k-stops/)
    19.1 SHIKSHA TIME - whenever steps are involved in finding the min cost in a weighted graph then better to use BFS or Bellman ford
20. Minimum Multiplications to reach End (https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0)
21. Number of ways to arrive at destination (https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)
22. Bellman ford (https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
23. Floyd washall (https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
24. Find the City With the Smallest Number of Neighbors at a Threshold Distance (https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)
25. Number of Operations to Make Network Connected (https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)
26. Accounts merge (https://leetcode.com/problems/accounts-merge/)
27. [MUST DO] Number of Islands II (https://www.naukri.com/code360/problems/number-of-islands-ii_1266048?leftPanelTabValue=SUBMISSION)
28. [MUST DO] Make a large island (https://leetcode.com/problems/making-a-large-island/description/)
29. Most Stones Removed with Same Row or Column (https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
30. Strongly connectec components - Kosaraju algo
31. Bridges in a graph
32. Articulation points
33. Evaluate Division - TRY dfs and floyd warshall (https://leetcode.com/problems/evaluate-division/description/)
34. [If confident in BFS then SKIP IT] Get Watched Videos by Your Friends (https://leetcode.com/problems/get-watched-videos-by-your-friends/)
35. [STICK TO IT, IT's EASY] Cut Off Trees for Golf Event (https://leetcode.com/problems/cut-off-trees-for-golf-event/description/)
36. Longest Increasing Path in a Matrix - Can be done using DFS+DP or BFS+topoSort (https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/)
37. Reconstruct Itinerary - here we are finding topo sort in case of a cyclic graph. In such cases use DFS (https://leetcode.com/problems/reconstruct-itinerary/description/)
38. Network Delay Time (https://leetcode.com/problems/network-delay-time/)
39. Path with Maximum Probability (https://leetcode.com/problems/path-with-maximum-probability/description/)
40. Min Cost to Connect All Points (https://leetcode.com/problems/min-cost-to-connect-all-points/)
41. Largest Component Size by Common Factor - Math + graph (https://leetcode.com/problems/largest-component-size-by-common-factor/)
42. Longest Subsequence Repeated k Times (https://leetcode.com/problems/longest-subsequence-repeated-k-times/)
43. Jump game 3 (https://leetcode.com/problems/jump-game-iii/description/)
44. Jump game 4 (https://leetcode.com/problems/jump-game-iv/description/)
45. Open the lock (https://leetcode.com/problems/open-the-lock/description/)
46. M coloring problem - meant to be backtracking but did it with BFS (https://www.naukri.com/code360/problems/981273?leftPanelTabValue=PROBLEM)
47. Valid BFS (https://codeforces.com/problemset/problem/1037/D)
48. Maximize Amount After Two Days of Conversions (https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/description/)
49. Race car (https://leetcode.com/problems/race-car/description/)
50. Maximize the Number of Target Nodes After Connecting Trees I (https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/)
51. Shortest Path in a Grid with Obstacles Elimination (https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/)
52. [Do it if you have time] Frog Jump (https://leetcode.com/problems/frog-jump/description/)
53. [Great question for min distance] Minimum Weighted Subgraph With the Required Paths (https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/)
54. Swim in Rising Water (https://leetcode.com/problems/swim-in-rising-water/description/)
55. Battleships in a Board (https://leetcode.com/problems/battleships-in-a-board/description/)
56. Find All Possible Recipes from Given Supplies (https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/)
57. Maximum Score of a Node Sequence (https://leetcode.com/problems/maximum-score-of-a-node-sequence/description/)
58. Minimum height trees (https://leetcode.com/problems/minimum-height-trees/description/)
59. Find Minimum Diameter After Merging Two Trees (https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/)
60. Count Nodes With the Highest Score (https://leetcode.com/problems/count-nodes-with-the-highest-score/description/)
61. Sum of Distances in Tree (https://leetcode.com/problems/sum-of-distances-in-tree/description/)
62. Maximum Score After Applying Operations on a Tree - DP on trees (https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/)
63. Maximum Number of Points From Grid Queries (https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/)
64. The Earliest Moment When Everyone Become Friends (https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/)
65. Last Day Where You Can Still Cross (https://leetcode.com/problems/last-day-where-you-can-still-cross/description/)
66. Apply Substitutions (https://leetcode.com/problems/apply-substitutions/description/)
67. Valid Arrangement of Pairs (https://leetcode.com/problems/valid-arrangement-of-pairs/description/)
68. Minimum Obstacle Removal to Reach Corner - First try dijkstra then modified bfs for optimization (https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)
69. Trapping rain water II (https://leetcode.com/problems/trapping-rain-water-ii/description/)




-----------------------------
### Binary Trees
-----------------------------
1. [Too easy] Inorder, preorder, postorder, level order from leetcode
2. [Too easy] Zig zag traversal (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
3. Diameter of a Binary tree (https://leetcode.com/problems/diameter-of-binary-tree/)
4. Right view (https://leetcode.com/problems/binary-tree-right-side-view/description/)
5. Construct binary tree from pre and in order (https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
6. [Too easy] Max depth of a binary tree
7. [Too easy] Balanced binary tree
8. Binary tree max path sum (https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)
9. Boundary traversal (https://www.naukri.com/code360/problems/boundary-traversal_790725)
10. Vertical order traversal (https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/)
11. Top View (https://www.naukri.com/code360/problems/top-view-of-the-tree_799401)
12. Bottom view (https://www.naukri.com/code360/problems/top-view-of-the-tree_799401)
13. [Too easy] Binary tree paths(https://leetcode.com/problems/binary-tree-paths/submissions/747685431/)
14. LCA (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)
15. Max width of a binary tree (https://leetcode.com/problems/maximum-width-of-binary-tree/)
16. [Please try] Maximum binary tree - Question for monotonic stack (https://leetcode.com/problems/maximum-binary-tree/description/)
17. Children sum property (https://www.naukri.com/code360/problems/childrensumproperty_790723)
18. All nodes at the kth distance from target (https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)
19. Time to burn a binary tree (https://www.naukri.com/code360/problems/time-to-burn-tree_630563)
   OR
   (https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/)
20. Count nodes in a complete binary tree - Try to do it in O((logn)^2) (https://leetcode.com/problems/count-complete-tree-nodes/description/)
21. Serialize or deserialize - try using preorder (https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)
22. Flatten binary tree (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
23. Maximum binary tree 2 (https://leetcode.com/problems/maximum-binary-tree-ii/description/)
24. Construct binary tree from POST and INorder (https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)
25. Check Completeness of a Binary Tree (https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/)
26. Is binary tree heap (https://www.naukri.com/code360/problems/is-binary-heap-tree_893136?leftPanelTabValue=PROBLEM)
27. Convert BST to Min Heap (https://www.geeksforgeeks.org/convert-bst-min-heap/) - SOLVE HERE (https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498)
28. House robber III (https://leetcode.com/problems/house-robber-iii/)
29. Step-By-Step Directions From a Binary Tree Node to Another (https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/)
30. Distribute Coins in Binary Tree (https://leetcode.com/problems/distribute-coins-in-binary-tree/description/)
31. Binary tree cameras (https://leetcode.com/problems/binary-tree-cameras/description/)
32. Find leaves of binary tree (https://leetcode.com/problems/find-leaves-of-binary-tree/description/)



-----------------------------
### Binary search tree (BST)
-----------------------------
-> FOR BST leverage the facility that leftTree < root -> data < rightTree
-> Inorder is sorted (Think in this if nothing is working out)
-> Use Stack to montonic operation && to create the BST iterator
-> SEE the LCA problem
1. Floor in BST (https://www.naukri.com/code360/problems/floor-from-bst_920457)
2. Insert into BST (https://leetcode.com/problems/insert-into-a-binary-search-tree/)
3. Delete a node from BST (https://leetcode.com/problems/delete-node-in-a-bst/description/)
4. Kth smallest in BST (https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
5. LCA for BST (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)
6. Pred and succ of a number in BST - Do it iteratively (https://www.naukri.com/code360/problems/predecessor-and-successor_920476)
7. BST iterator - Use stack here (https://leetcode.com/problems/binary-search-tree-iterator/)
8. Two sum in BST - Sort of application of BST iterator - use stacks (https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)
9. Recover the binary tree (https://leetcode.com/problems/recover-binary-search-tree/description/)
10. Largest BST - read the question carefully (https://www.geeksforgeeks.org/problems/largest-bst/1)
11. Trim a Binary Search Tree (https://leetcode.com/problems/trim-a-binary-search-tree/description/)
12. Convert BST to Greater Tree (https://leetcode.com/problems/convert-bst-to-greater-tree/)
13. Increasing Order Search Tree (https://leetcode.com/problems/increasing-order-search-tree/description/)


-----------------------------
### Greedy (think greedily)
-----------------------------
1. [V easy] Assign cookies (https://leetcode.com/problems/assign-cookies/description/)
2. [V easy] Lemonade Change (https://leetcode.com/problems/lemonade-change/)
3. Jump game - more of Greedy (https://leetcode.com/problems/jump-game/description/)
4. Jump game II - more of Greedy (https://leetcode.com/problems/jump-game-ii/)
5. [Simple] Insert Interval (https://leetcode.com/problems/insert-interval/)
6. Candy (https://leetcode.com/problems/candy/description/)
7. Fractional Knapsack (https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)
8. Valid Parenthesis String (https://leetcode.com/problems/valid-parenthesis-string/description/)
Scan left to right and right to left. at any moment if open < 0 or close < 0(right to Left) return false
9. Minimum Number of Refueling Stops (https://leetcode.com/problems/minimum-number-of-refueling-stops/)
10. Put Marbles in Bags (https://leetcode.com/problems/put-marbles-in-bags/description/)
11. 



-----------------------------
### Job scheduling problems (Greedy + DP)
-----------------------------
1. Job Sequencing Problem - See how to do it using DSU or priority queue (https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)
2. N meetings in one room (https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)
3. Meeting Rooms III (https://leetcode.com/problems/meeting-rooms-iii/)
4. Non-overlapping Intervals (https://leetcode.com/problems/non-overlapping-intervals/description/)
5. Minimum Platforms (https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1)
6. Maximum Profit in Job Scheduling (https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/)
7. Maximum Number of Events That Can Be Attended (https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)
8. Maximum Number of Events That Can Be Attended II (https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)
9. Maximum Earnings From Taxi (https://leetcode.com/problems/maximum-earnings-from-taxi/)
10. Task Scheduler (https://leetcode.com/problems/task-scheduler/description/)
11. Course schedule III - think greedily (https://leetcode.com/problems/course-schedule-iii/description/)
12. Number of weak characters (https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/)
13. Find Servers That Handled Most Number of Requests (https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/)
14. Increment decrement (https://github.com/apoorvKautilya21/Data-Structures-And-Algorithm-in-C-/blob/main/Miscel/q1.cpp)



-----------------------------
### Geometry (GOOGLE)
-----------------------------
1. Minimum Area rectangle (https://leetcode.com/problems/minimum-area-rectangle/description/)
2. Minimum Area rectangle II (https://leetcode.com/problems/minimum-area-rectangle-ii/editorial/)
3. Separate Squares I (https://leetcode.com/problems/separate-squares-i/description/)
4. Maximum Number of Visible Points (https://leetcode.com/problems/maximum-number-of-visible-points/description/)



-----------------------------
### Two pointer and Sliding window (Try to optimize it to 1 pass)
-----------------------------
1. Maximum Points You Can Obtain from Cards (https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)
2. Longest Substring Without Repeating Characters (https://leetcode.com/problems/longest-substring-without-repeating-characters/)
3. Max Consecutive Ones III (https://leetcode.com/problems/max-consecutive-ones-iii/description/)
4. Fruit Into Baskets (https://leetcode.com/problems/fruit-into-baskets/description/)
5. Longest Substring with K Uniques (https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)
6. Number of Substrings Containing All Three Characters (https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)
7. Longest Repeating Character Replacement (https://leetcode.com/problems/longest-repeating-character-replacement/description/)
8. Binary Subarrays With Sum (https://leetcode.com/problems/binary-subarrays-with-sum/description/)
9. Subarray Sum Equals K - Prefix sum and hash table (https://leetcode.com/problems/subarray-sum-equals-k/)
10. Count Number of Nice Subarrays (https://leetcode.com/problems/count-number-of-nice-subarrays/)
11. Subarrays with K Different Integers (https://leetcode.com/problems/subarrays-with-k-different-integers/)
12. Minimum Window Substring - Try using only 1 hashmap (https://leetcode.com/problems/minimum-window-substring/description/)
https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/
13. 3sum (https://leetcode.com/problems/3sum/description/)
14. 4sum (https://leetcode.com/problems/4sum/)
15. Minimum Size Subarray Sum - Positive numbers only - try both O(n) & O(nlogn solutions) (https://leetcode.com/problems/minimum-size-subarray-sum/description/)
16. Shortest Subarray with Sum at Least K - Both Positive and negative numbers - Priority queue OR Deque  (https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)
17. Jump game 7 - DP + sliding window (https://leetcode.com/problems/jump-game-vii/description/)
18. Frequency of the Most Frequent Element (https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/)
19. Substring with Concatenation of All Words (https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)
20. Equal (https://www.interviewbit.com/problems/equal/)
21. Sort by color (https://www.interviewbit.com/problems/sort-by-color/)
22. Counting Triangles (https://www.interviewbit.com/problems/counting-triangles/)
23. Contiguous Array (https://leetcode.com/problems/contiguous-array/description/)
24. Longest Subarray Length (https://www.interviewbit.com/problems/longest-subarray-length/)
25. Subarray with equal occurences (https://www.interviewbit.com/problems/subarray-with-equal-occurences/)
26. Two out of Three (https://www.interviewbit.com/problems/two-out-of-three/)
27. Count Subarrays With More Ones Than Zeros (https://algomonster.medium.com/2031-count-subarrays-with-more-ones-than-zeros-d1f684a17361)
28. Longest Nice Subarray - (https://leetcode.com/problems/longest-nice-subarray/description/)
29.  Minimum Operations to Make Binary Array Elements Equal to One I (https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/)
30. Swap Adjacent in LR String (https://leetcode.com/problems/swap-adjacent-in-lr-string/description/)
31. Count Non-Decreasing Subarrays After K Operations (https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/description/)
32. Push dominoes (https://leetcode.com/problems/push-dominoes/description/)




-----------------------------
### Prefix sum
-----------------------------
1. (https://leetcode.com/problems/corporate-flight-bookings/description/)
2. Zero Array Transformation I (https://leetcode.com/problems/zero-array-transformation-i/description/)


-----------------------------
### Hashing
-----------------------------
1. 2sum (https://leetcode.com/problems/two-sum/description/)
2. Longest Consecutive Sequence (https://leetcode.com/problems/longest-consecutive-sequence/description/)
3. Largest subarray with 0 sum (https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)
4. Subarray Sum Equals K - Prefix sum and hash table (https://leetcode.com/problems/subarray-sum-equals-k/)
5. Count Subarrays with given XOR (https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/0)
6. Divide Array in Sets of K Consecutive Numbers - Try O(n) (https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/)
7. K-diff Pairs in an Array (https://leetcode.com/problems/k-diff-pairs-in-an-array/)





-----------------------------
### Priority queue
-----------------------------
1. Kth largest element - O(N) also possible (https://leetcode.com/problems/kth-largest-element-in-an-array/)
2. Merge two binary max heaps (https://www.naukri.com/code360/problems/merge-two-binary-max-heaps_1170049)
3. K-th Largest Sum Contiguous Subarray - O(N^2 logK) (https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1)
4. Smallest Range Covering Elements from K Lists - try to do without using merged array (https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)
5. Find median of a data stream (https://leetcode.com/problems/find-median-from-data-stream/description/)
6. Minimum Number of Refueling Stops (https://leetcode.com/problems/minimum-number-of-refueling-stops/)
7. Shortest Subarray with Sum at Least K - Both Positive and negative numbers - Priority queue OR Deque  (https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)



-----------------------------
### Stacks (Check if there is any monotonicity in problems, write down the question and check if we need next greater/smaller and prev greater/smaller)
-----------------------------
1. Valid Parentheses (https://leetcode.com/problems/valid-parentheses/description/)
2. Min stack (https://leetcode.com/problems/min-stack/description/)
3. Next greater element 1 (https://leetcode.com/problems/next-greater-element-i/description/)
4. Next greater element II (https://leetcode.com/problems/next-greater-element-ii/description/)
5. Trapping rain water (https://leetcode.com/problems/trapping-rain-water/description/)
6. [MUST DO] Sum of Subarray Minimums (https://leetcode.com/problems/sum-of-subarray-minimums/)
7. [Variation of above] Sum of Subarray Ranges (https://leetcode.com/problems/sum-of-subarray-ranges/)
8. Asteroid Collision (https://leetcode.com/problems/asteroid-collision/submissions/1586866307/)
9. Largest Rectangle in Histogram (https://leetcode.com/problems/largest-rectangle-in-histogram/description/)
10. [DP + Stacks] Maximal Rectangle (https://leetcode.com/problems/maximal-rectangle/)
11. Remove K Digits (https://leetcode.com/problems/remove-k-digits/)
12. Online Stock Span (https://leetcode.com/problems/online-stock-span/description/)
13. Evaluate Reverse Polish Notation (https://leetcode.com/problems/evaluate-reverse-polish-notation/)
14. Decode string (https://leetcode.com/problems/decode-string/description/)
15. Basic calculator II (https://leetcode.com/problems/basic-calculator-ii/description/)
16. Basic calculator IV (https://leetcode.com/problems/basic-calculator-iv/description/)
17. Apply Operations to Maximize Score (https://leetcode.com/problems/apply-operations-to-maximize-score/description/)
18. Number of Visible People in a Queue (https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/)
19. Basic calculator III (https://leetcode.com/problems/basic-calculator-iii/)
20. Find the celebrity (https://leetcode.com/problems/find-the-celebrity/description/)





-----------------------------
### Queue
-----------------------------
1. 


### Divide.  and conqure
1. Count of Smaller Numbers After Self (https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/)
2. 



-----------------------------
### Deque
-----------------------------
1. Shortest Subarray with Sum at Least K - Both Positive and negative numbers - Priority queue OR Deque  (https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)
2. Sliding Window Maximum (https://leetcode.com/problems/sliding-window-maximum/description/)


-----------------------------
### Binary search
-----------------------------
1. Find First and Last Position of Element in Sorted Array (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)
2. Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/)
3. Search in Rotated Sorted Array II (https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)
4. Find Minimum in Rotated Sorted Array II (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/)
5. Single Element in a Sorted Array (https://leetcode.com/problems/single-element-in-a-sorted-array/description/)
6. Find Peak Element (https://leetcode.com/problems/find-peak-element/description/)
7. Find nth root (https://www.naukri.com/code360/problems/nth-root-of-m_1062679)
8. Koko Eating Bananas (https://leetcode.com/problems/koko-eating-bananas/)
9. Minimum Number of Days to Make m Bouquets (https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/)
10. Find the Smallest Divisor Given a Threshold (https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)
11. Capacity To Ship Packages Within D Days (https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)
12. Kth Missing Positive Number (https://leetcode.com/problems/kth-missing-positive-number/description/)
13. Aggressive cows (https://www.geeksforgeeks.org/problems/aggressive-cows/0)
14. Allocate Minimum Pages (https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)
15. The Painter's Partition Problem-II (https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
16. Minimize Max Distance to Gas Station (https://www.naukri.com/code360/problems/minimise-max-distance_7541449)
17. Median of Two Sorted Arrays (https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
18. K-th Element of Two Sorted Arrays (https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159)
19. My calendar I - See both use cases, start time and endTime (https://leetcode.com/problems/my-calendar-i/)
20. My calendar II (https://leetcode.com/problems/my-calendar-ii/)
21. My calendar III (https://leetcode.com/problems/my-calendar-iii/)




-----------------------------
### Math
-----------------------------
1. GCD (https://www.naukri.com/code360/problems/hcf-and-lcm_840448?leftPanelTabValue=SUBMISSION)
2. Print all prime factors (https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/)
3. Prime all primes till n (https://leetcode.com/problems/count-primes/description/)
4. Primes primes in ranges - Prefix sum (https://www.geeksforgeeks.org/problems/count-primesFlatten a Multilevel Doubly Linked List-in-range1604/0)
5. Closest Prime Numbers in Range (https://leetcode.com/problems/closest-prime-numbers-in-range/description/)
6. Prime factorization query based O(Qlogn) (https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description)
7. Smallest Palindromic Rearrangement II (https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/description/)
8. Count Numbers with Non-Decreasing Digits (https://leetcode.com/problems/count-numbers-with-non-decreasing-digits/description/)
9. Find X Value of Array I (https://leetcode.com/problems/find-x-value-of-array-i/description/)
10. Count the Number of Ideal Arrays (https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/)



-----------------------------
### Array
-----------------------------
1. First missing Positive number (https://leetcode.com/problems/first-missing-positive/description/)
2. Container With Most Water (https://leetcode.com/problems/container-with-most-water/description/)
3. Maximum Width Ramp (https://leetcode.com/problems/maximum-width-ramp/description/)
4. Merge 2 sorted list (https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/)
5. Maximum Value of an Ordered Triplet II (https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/)
6. Number of Matching Subsequences (https://leetcode.com/problems/number-of-matching-subsequences/description/)
7. Integer to English Words (https://leetcode.com/problems/integer-to-english-words/description/)
8. Snapshot array (https://leetcode.com/problems/snapshot-array/description/)

### Random
1. Random Pick with Weight (https://leetcode.com/problems/random-pick-with-weight/description/)
2. Guess the word (https://leetcode.com/problems/guess-the-word/description/)

-----------------------------
### Linked list
-----------------------------
1. Reverse a Doubly Linked List (https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
2. Add two numbers (https://leetcode.com/problems/add-two-numbers/description/)
3. Sort linked list of 0s 1s 2s (https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937)
4. Odd Even Linked List (https://leetcode.com/problems/odd-even-linked-list/)
5. Remove kth node from end of linked list (https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)
6. Reverse a linked list (https://leetcode.com/problems/reverse-linked-list/description/)
7. Palindrome Linked List (https://leetcode.com/problems/palindrome-linked-list/)
8. Reverse a linked list (https://www.naukri.com/code360/problems/add-one-to-linked-list_920557)
9. Intersection of Two Linked Lists (https://leetcode.com/problems/intersection-of-two-linked-lists/description/)
10. Linked list cycle (https://leetcode.com/problems/linked-list-cycle/description/)
11. Find the length of a linked list (https://www.geeksforgeeks.org/problems/find-length-of-loop/1)
12. Linked List Cycle II (https://leetcode.com/problems/linked-list-cycle-ii/description/)
13. Delete all occurrences of a given key in a doubly linked list (https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?leftPanelTabValue=PROBLEM)
14. Find pairs with given sum in doubly linked list (https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1)
15. Remove Duplicates from Sorted List II (https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)
16. Reverse nodes in k groups (https://leetcode.com/problems/reverse-nodes-in-k-group/description/)
17. Copy List with Random Pointer (https://leetcode.com/problems/copy-list-with-random-pointer/description/)
18. Rotate a linked list (https://leetcode.com/problems/rotate-list/description/)
19. Flatten a Multilevel Doubly Linked List (https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/)
20. Rotate List (https://leetcode.com/problems/rotate-list/description/)
21. LRU (https://leetcode.com/problems/lru-cache/submissions/1587777136/)
22. LFU (https://leetcode.com/problems/lfu-cache/description/)
23. Merge k sorted lists (https://leetcode.com/problems/merge-k-sorted-lists/description/)
24. Linked List in Binary Tree (https://leetcode.com/problems/linked-list-in-binary-tree/description/)
25. Minimum Pair Removal to Sort Array II (https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/)




-----------------------------
### Intervals
-----------------------------
1. Merge intervals (https://leetcode.com/problems/merge-intervals/description/)
2. Insert intervals (https://leetcode.com/problems/insert-interval/)
3. Range module (https://leetcode.com/problems/range-module/)
4. Interval List Intersections (https://leetcode.com/problems/interval-list-intersections/description/)
5. Minimum Number of Arrows to Burst Balloons (https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)
6. Remove Covered Intervals (https://leetcode.com/problems/remove-covered-intervals/description/)



-----------------------------
### Trie
-----------------------------
1. Implement Trie (Prefix Tree) (https://leetcode.com/problems/implement-trie-prefix-tree/)
2. Implement trie 2 (https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM)
3. Complete string (https://www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=SUBMISSION)
4. Count Distinct Substrings (https://www.naukri.com/code360/problems/count-distinct-substrings_985292)
5. Maximum XOR of Two Numbers in an Array (https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
6. Longest Common Prefix of K Strings After Removal - Beautiful question of Trie (https://leetcode.com/problems/longest-common-prefix-of-k-strings-after-removal/description/)
7. Word search II (https://leetcode.com/problems/word-search-ii/description/)


-----------------------------
### Segment tree
-----------------------------
BIT supports associative operations like sum or XOR, but we can modify it to support range maximum queries. Instead of storing sums in the tree, you store maximums.
If you need to overwrite a value (e.g., tree[i] = val, not max), BIT won't help directly — you'd need a Segment Tree.

1. Range Sum Query - Mutable (https://leetcode.com/problems/range-sum-query-mutable/?envType=problem-list-v2&envId=segment-tree)
2. Xenia and bitwise operation (https://codeforces.com/problemset/problem/339/D) - [Solution](https://github.com/apoorvKautilya21/Data-Structures-And-Algorithm-in-C-/blob/main/30.%20Segment%20trees/4_bitwiseCodeForces.cpp)
3. Sereja and Brackets (https://codeforces.com/problemset/problem/380/C) - [Solution](https://github.com/apoorvKautilya21/Data-Structures-And-Algorithm-in-C-/blob/main/30.%20Segment%20trees/5_bracketsCodeforces.cpp)
4. Count of Smaller Numbers After Self (https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/?envType=problem-list-v2&envId=segment-tree)
5. Count of Range Sum (https://leetcode.com/problems/count-of-range-sum/description/?envType=problem-list-v2&envId=segment-tree)
6. [Just see how we are using segment tree] Create Sorted Array through Instructions (https://leetcode.com/problems/create-sorted-array-through-instructions/description/)
7. [Easy with fenwick] Queries on a Permutation With Key (https://leetcode.com/problems/queries-on-a-permutation-with-key/description/)
8. Count Good Triplets in an Array (https://leetcode.com/problems/count-good-triplets-in-an-array/description/)
9. Longest Increasing Subsequence II (https://leetcode.com/problems/longest-increasing-subsequence-ii/description/)
10. Maximize Subarray Sum After Removing All Occurrences of One Element (https://leetcode.com/problems/maximize-subarray-sum-after-removing-all-occurrences-of-one-element/description/)
11. Count Number of Teams (https://leetcode.com/problems/count-number-of-teams/description/)


-----------------------------
### String matching Algo
-----------------------------
1. Find the Index of the First Occurrence in a String - KMP (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)
2. Longest Happy Prefix - KMP (https://leetcode.com/problems/longest-happy-prefix/description/)
3. Find the Occurrence of First Almost Equal Substring - Z Algo (https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/)
4. Maximum Length of Repeated Subarray (https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)
5. Find the Occurrence of First Almost Equal Substring (https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/)
6. Find the String with LCP (https://leetcode.com/problems/find-the-string-with-lcp/description/)










### ---- Shortest Path Algos ----

1. For unit weights graphs - use BFS
2. For DAG (-ve wts as well) use Topo sort - In O(V + E)
3. For Dijkstra -> All cases excepts Graphs with negative cycles where it gives TLE
4. Bellman ford - all cases - detect -ve cycles ( use a dictionary to do this, and we repeatedly test out each edge to see if converting using the maximums we already know leads to a new maximum. We repeat until we are sure we have exhausted all possible (greedy) sequences of conversions. This is Bellman-Ford shortest path algorithm, where relaxing an edge just means trying out a conversion.)
5. Floyd warshall - multi source shortest path - all cases - detect -ve cycles

### ---- Cycle detection ----
1. Undirected graph - Use parent and current node to find cycle. If nbr of a src node is visible and it is not the parent then there is cycle. (BFS and DFS)
2. Directed graph
    2.1 Start DFS from a source and store the path traversed. If we again come to the node present in the path then dang! there is a cycle. We will have to mark the path as false once we are done with dfs of the particular node
    2.2 Use topo sort (BFS). If all nodes will be visited using topo sort then there isn't any cycle.
    2.3 For directed graph if you want to find the nodes which are in cycle or which ends up in a cycle then see the problem "Find eventual states".



https://leetcode.com/discuss/post/5031296/google-technical-phone-screen-round-2024-1mbj/
(TRIE + BFS)


https://leetcode.com/problems/russian-doll-envelopes/description/
https://leetcode.com/problems/range-module/description/
https://leetcode.com/discuss/post/6527460/google-screening-round-question-march-20-nkba/
https://leetcode.com/problems/house-robber-iii/description/
https://leetcode.com/discuss/post/5567668/google-interview-onsite-1-by-anonymous_u-1qk1/



https://leetcode.com/discuss/post/6532222/google-onsite-googliness-round-by-anonym-p32b/



