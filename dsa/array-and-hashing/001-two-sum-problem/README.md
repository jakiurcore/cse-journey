# 001 - Two Sum

**Problem:** Given a list of numbers and a `target`, find the two positions whose numbers add up to `target`.

```
nums   = [ 2,  7, 11, 15 ]      target = 9
index      0   1   2   3

2 + 7 = 9   ->  answer: 0 1
```

There are four files here. They are four ways of thinking about the **same** question, from slowest to smartest.

---

## 1. Brute force  (`brute-force.cpp`)

**Idea:** Try every pair. Nothing clever.

```
i=0:  (2,7) (2,11) (2,15)
i=1:        (7,11) (7,15)
i=2:               (11,15)
```

Pick one number, then look at every number to its right. If they add up to the target, stop.

- **Time:** O(n²). Pairs grow like n·(n-1)/2.
- **Memory:** O(1). No extra storage.
- **When to use it:** Tiny inputs, or as the "obviously correct" version to check the others against.
- **Watch out:** The inner loop is `j < size - 1`, so it never looks at the **last** element. It should be `j < size`.

---

## 2. Sort + binary search  (`binary-search.cpp`)

**Idea:** For each number `x`, I already know what I need: `target - x`. If the list is sorted I can *find* that number fast instead of scanning for it.

```
sorted:  [ 2, 7, 11, 15 ]
x = 2 -> need 7 -> binary search:

  [ 2  7  11  15 ]
         ^mid=11  too big  -> go left
  [ 2  7 ]
      ^mid=7      found!
```

Sorting destroys the original positions, so each value is stored as a pair `(original index, value)`. After sorting I still know where it came from.

- **Time:** O(n log n). The sort costs n log n, then n searches at log n each.
- **Memory:** O(n) for the pairs.
- **Watch out:** If `complement == x` (for example `3 + 3 = 6`), the search can find the *same element* again. The code guards against that with `if (n[i].first == j) continue;`. That guard can still miss a duplicate that sits on a different index, so the version is a bit fragile.

---

## 3. Sort + two pointers  (`two-pointer.cpp`)

**Idea:** In a sorted list, one pointer at each end tells me which way to move.

```
[ 2   7   11   15 ]    target = 9
  L              R     2+15 = 17  too BIG   -> move R left (need smaller)
  L         R          2+11 = 13  too BIG   -> move R left
  L     R              2+7  = 9   FOUND
```

- Sum too small -> move `L` right (a bigger left number).
- Sum too big   -> move `R` left (a smaller right number).

Each step throws away a number that can never be part of the answer, so the pointers cross at most once.

- **Time:** O(n log n), and the sort dominates. The two-pointer walk itself is only O(n).
- **Memory:** O(n) for the `(index, value)` pairs. It would be O(1) if only the values were needed, not the original positions.
- **When to use it:** When the array is *already sorted*. Then it is O(n) time and O(1) memory.

---

## 4. Hash map  (`hashmap.cpp`)  - the best general answer

**Idea:** Walk the list once. For every number, ask the map: "have I already seen the number I need?" If not, remember this one.

```
nums = [2, 7, 11, 15]   target = 9

i=0  x=2   need 7   map={}            no  -> store 2   map={2:0}
i=1  x=7   need 2   map={2:0}         YES -> answer (0, 1)
```

Why it works: whichever number of the pair comes second will find the first one already waiting in the map. So one pass is enough.

- **Time:** O(n). Each lookup and insert is O(1) on average.
- **Memory:** O(n). In the worst case the map holds every number.
- **Trade-off:** I spend memory to buy speed.

---

## Summary

| Approach       | Time       | Memory | Note                          |
|----------------|------------|--------|-------------------------------|
| Brute force    | O(n²)      | O(1)   | Simple, slow                  |
| Binary search  | O(n log n) | O(n)   | Needs sort, fragile on duplicates |
| Two pointers   | O(n log n) | O(n)   | Best if input already sorted  |
| **Hash map**   | **O(n)**   | O(n)   | Best in general               |

**Lesson to remember:** "Find the partner of x" is a *lookup* problem. Whenever you are searching for something again and again, ask whether a hash map, or sorting, can make that lookup cheap.
