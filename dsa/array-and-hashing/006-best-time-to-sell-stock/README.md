# 006 - Best Time to Buy and Sell Stock

**Problem:** `prices[i]` is the price on day `i`. Buy once, then sell on a **later** day. What is the largest profit? If nothing is profitable, return 0.

```
prices = [7, 1, 5, 3, 6, 4]

buy at 1 (day 1), sell at 6 (day 4)  -> profit 5
```

```
price
 7 |*
 6 |              *
 5 |       *
 4 |                 *
 3 |          *
 1 |    *
   +--------------------
     d0 d1 d2 d3 d4 d5
        buy       sell
```

---

## First thought: brute force

Try every buy day and every later sell day, and keep the best difference. This is O(n²) and it re-checks the same things again and again.

## My approach: one pass, remember the lowest price so far  (`main.cpp`)

**Idea:** Stand on each day and pretend it is the **sell day**. The best buy day for it is simply the **cheapest price seen before** (or today). So I only need to carry one number: the minimum so far.

```
prices = [7, 1, 5, 3, 6, 4]

day  price  minPrice  profit if sell today  best
 0     7       7           0                  0
 1     1       1           0                  0
 2     5       1           4                  4
 3     3       1           2                  4
 4     6       1           5                  5   <- best
 5     4       1           3                  5
```

Two variables are all the memory I need:

- `minPrice`: cheapest price seen up to now.
- `best`: biggest `price - minPrice` seen up to now.

Because `minPrice` is updated *before* computing the profit, the profit is at least 0 (same-day), so a falling market correctly gives 0.

- **Time:** O(n). A single pass.
- **Memory:** O(1). Two integers.

---

## Comparison

| Approach                      | Time  | Memory | Note                         |
|-------------------------------|-------|--------|------------------------------|
| Brute force, all buy/sell pairs | O(n²) | O(1) | Too slow for big inputs      |
| **Track the min so far (mine)** | **O(n)** | **O(1)** | Optimal                  |

**Lesson to remember:** instead of looking back at all earlier days, keep a **running summary** of the past (here, the minimum). A good summary turns a nested loop into a single loop.
