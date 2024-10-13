# **Pattern Searching Walkthrough (KMP Algorithm)**

This document walks through how the Knuth-Morris-Pratt (KMP) algorithm is implemented in the code using an example. We'll explain each part of the code and how the <b>LPS (Longest Prefix Suffix)</b> array helps optimize the pattern search process.

### Example:

- **Text:** `"ababcababcababc"`
- **Pattern:** `"ababc"`

We will search for the pattern `"ababc"` in the text `"ababcababcababc"`.

## **Step 1: LPS Array Calculation**

The LPS array helps us avoid redundant comparisons. The LPS array stores, for each index `i` in the pattern, the length of the longest proper prefix of the pattern that is also a suffix ending at `i`.

### **LPS Array Construction**

We start by constructing the **LPS** array using the `computeLPS()` function in the code.

1. **Pattern:** `"ababc"`
2. **LPS Array Initialization:** `lps = [0, 0, 0, 0, 0]` (All elements initialized to 0).

We iterate through the pattern:

- At index `1`, the characters at indices `0` and `1` don't match (`a != b`), so `lps[1] = 0`.
- At index `2`, the characters at indices `1` and `2` don't match, so `lps[2] = 0`.
- At index `3`, the characters at indices `0` and `3` match (`a == a`), so `lps[3] = 1`.
- At index `4`, the characters at indices `1` and `4` match (`b == b`), so `lps[4] = 2`.

Thus, the final **LPS array** for the pattern `"ababc"` is:

```plaintext
LPS = [0, 0, 1, 2, 0]
```

**Explanation:**

- The value at `lps[i]` tells us the length of the longest proper prefix of the pattern that also matches the suffix ending at index `i`. For example, at index `4`, the value `2` means the prefix `"ab"` matches the suffix `"ab"`.

---

## **Step 2: Pattern Searching Using LPS Array**

Now we move to the `searchStringIndex()` function to search for the pattern in the text.

### **Initial State:**

- **Text:** `"ababcababcababc"`
- **Pattern:** `"ababc"`
- **LPS Array:** `[0, 0, 1, 2, 0]`
- Start with indices `i = 0` (for text) and `j = 0` (for pattern).

### **Search Process:**

- At `i = 0`, the characters `text[0]` and `pattern[0]` match (`a == a`). So, we increment both `i` and `j` to `1`.
- At `i = 1`, the characters `text[1]` and `pattern[1]` match (`b == b`). We increment both `i` and `j` to `2`.
- At `i = 2`, the characters `text[2]` and `pattern[2]` match (`a == a`). We increment both `i` and `j` to `3`.
- At `i = 3`, the characters `text[3]` and `pattern[3]` match (`b == b`). We increment both `i` and `j` to `4`.
- At `i = 4`, the characters `text[4]` and `pattern[4]` match (`c == c`). Since `j` equals the length of the pattern, we've found an occurrence of the pattern starting at index `i - j = 0`.

At this point, we update `j` to `lps[j-1] = lps[4] = 0` and continue searching from `i = 5`.

### **Further Matches:**

The process repeats as we continue searching the text:

- Another match is found starting at index `5`.
- Another match is found starting at index `10`.

**Final Output:**

- The pattern is found at indices `0`, `5`, and `10`.

---

## **Code Breakdown:**

### 1. **`computeLPS()` Function:**

- **Purpose:** Creates the LPS array, which stores information about the longest proper prefix that matches a suffix for each index in the pattern.
- **How it Works:**
  - Iterates over the pattern and compares characters to build the LPS array.
  - The LPS array helps determine how far back we can jump in the pattern when a mismatch occurs.

### 2. **`searchStringIndex()` Function:**

- **Purpose:** Uses the LPS array to efficiently search for the pattern in the text.
- **How it Works:**
  - Compares the text and pattern characters.
  - On a mismatch, instead of restarting the comparison, it uses the LPS array to skip unnecessary checks.
  - Adds the starting index of each pattern match to the result.

## **Why Use the KMP Algorithm?**

- **Efficiency:** The KMP algorithm avoids redundant comparisons, making it faster than a naive search approach.
- **Time Complexity:** O(n + m), where `n` is the length of the text and `m` is the length of the pattern.
- **Space Complexity:** O(m) due to the LPS array.

This approach ensures that even if the text or pattern is large, the algorithm will perform efficiently without backtracking unnecessarily.
