# 005 - Array Shifting (Duplicate Zeros)

**Problem:** Every `0` in the array is duplicated, and everything after it shifts to the right. The array keeps its **same length**, so values that fall off the end are dropped. Do it **in place**.

```
before: [1, 0, 2, 3, 0, 4, 5, 0]
after:  [1, 0, 0, 2, 3, 0, 0, 4]
```

---

## First thought (and why it is awkward)

If I go left to right and shift everything on every zero, each zero costs O(n) and I also overwrite numbers I have not read yet. That is O(n²) and messy.

## My approach: work from the back  (`main.cpp`)

**Idea:** Imagine the array was long enough to hold the final result. Its size would be `len + zeros`. Writing **from the end** means I never overwrite something I still need to read.

Two pointers:

- `i` reads the original array, going right to left.
- `j` writes into the "imaginary" long array, also right to left. It starts at `len + zeros - 1`.

```
arr = [1, 0, 2, 3, 0, 4, 5, 0]    len=8  zeros=3  -> imaginary length 11

index of imaginary array:  0 1 2 3 4 5 6 7 | 8 9 10   (8,9,10 do not exist)
                                           ^ the cut-off
```

Rule: only write when `j < len` (inside the real array). Writes beyond are simply thrown away.

```
read i=7 (0):  copy to j=10 (skip), j=9 (skip)       0 is written twice
read i=6 (5):  j=8  skip
read i=5 (4):  j=7  -> arr[7]=4
read i=4 (0):  j=6, j=5 -> arr[6]=0, arr[5]=0
...and so on, until i reaches 0.
```

The code does this in two lines per element: copy the value, then if it is a zero, copy it once more.

- **Time:** O(n). One count pass plus one backward pass.
- **Memory:** O(1). Only a few integers; the array is edited in place.

---

## Comparison

| Approach                        | Time  | Memory | Note                         |
|---------------------------------|-------|--------|------------------------------|
| Shift on every zero             | O(n²) | O(1)   | Slow                         |
| Build a new array, copy back    | O(n)  | O(n)   | Simple, not in place         |
| **Backward two pointers (mine)**| **O(n)** | **O(1)** | In place and linear      |

**Lesson to remember:** when moving things to the right inside one array, **start from the end**. Writing from the back never destroys data you still need.
