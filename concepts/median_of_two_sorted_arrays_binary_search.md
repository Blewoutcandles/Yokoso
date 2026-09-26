# Median of Two Sorted Arrays - Binary Search Approach

## 📌 பிரச்சனையின் விளக்கம்

இரண்டு sorted arrays `nums1` மற்றும் `nums2` கொடுக்கப்பட்டுள்ளன.

அவற்றின் அளவுகள்:

-   `nums1` → `m`
-   `nums2` → `n`

இரண்டு arrays-ஐ ஒன்றாக merge செய்யாமல், அவற்றின் **median**-ஐ கண்டுபிடிக்க
வேண்டும்.

### முக்கிய Constraint

``` text
Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)
```

அதாவது, இரண்டு arrays-ல் சிறிய array மீது மட்டும் Binary Search செய்ய வேண்டும்.

------------------------------------------------------------------------

# 💡 Core Concept - அடிப்படைத் தத்துவம்

இரண்டு arrays-ஐ merge செய்து:

``` text
A + B → Sorted Array → Median
```

என்று செய்வது `O(m + n)` ஆகும்.

அதற்கு பதிலாக, இரண்டு arrays-ஐ ஒரு சரியான இடத்தில் **partition** செய்கிறோம்.

நமது இலக்கு:

``` text
             Left Half | Right Half
Array A:     ... A_left | A_right ...
Array B:     ... B_left | B_right ...
```

என்பது போன்ற partition உருவாக்குவது.

அந்த partition சரியாக இருந்தால்:

``` text
Left Half-ல் உள்ள எல்லா elements
              <=
Right Half-ல் உள்ள எல்லா elements
```

ஆக இருக்கும்.

------------------------------------------------------------------------

# 🎯 Equal Partitioning

மொத்த elements:

``` text
m + n
```

Left Half-ல் இருக்க வேண்டிய elements எண்ணிக்கை:

``` text
left_half = (m + n + 1) / 2
```

Integer division பயன்படுத்துவதால்:

``` text
floor((m + n + 1) / 2)
```

என்பது கிடைக்கும்.

### ஏன் `+1`?

Odd number of elements இருந்தால் median Left Half-ல் இருக்க வேண்டும்.

உதாரணம்:

``` text
Total = 9

(9 + 1) / 2 = 5
```

அதனால்:

``` text
Left  = 5 elements
Right = 4 elements
```

Even case:

``` text
Total = 10

(10 + 1) / 2 = 5
```

அதனால்:

``` text
Left  = 5 elements
Right = 5 elements
```

------------------------------------------------------------------------

# 🔪 Partition Indices

நாம் Array A-வில் `i` elements எடுத்தால்:

``` text
A: [ elements before i | elements from i ]
                 ↑
             partition
```

அதே நேரத்தில் Array B-ல் எடுக்க வேண்டிய elements:

``` text
j = left_half - i
```

என்பதாக இருக்கும்.

இதனால் Left Half-ல் சரியான எண்ணிக்கையிலான elements இருக்கும்.

------------------------------------------------------------------------

# 🔍 Valid Partition Condition

Partition சரியாக இருக்க வேண்டுமெனில் இரண்டு முக்கியமான conditions:

``` text
A_left <= B_right
```

மற்றும்

``` text
B_left <= A_right
```

இரண்டும் true ஆக வேண்டும்.

Diagram:

``` text
Array A:  ... A_left | A_right ...

Array B:  ... B_left | B_right ...
```

Cross-check:

``` text
A_left  <= B_right
B_left  <= A_right
```

இவை இரண்டும் true என்றால்:

``` text
             Left Half | Right Half

Array A:     ... A_left | A_right ...
Array B:     ... B_left | B_right ...

             ✅ Valid Partition
```

------------------------------------------------------------------------

# ⚠️ Boundary Conditions

Partition array-ன் ஆரம்பத்திலோ அல்லது முடிவிலோ இருக்கலாம்.

அதனால் சில நேரங்களில் ஒரு side-ல் element இருக்காது.

### Case 1: `i == 0`

Array A-ன் Left Half-ல் எந்த element-மும் இல்லை.

``` text
A_left = -∞
```

### Case 2: `i == m`

Array A-ன் Right Half-ல் எந்த element-மும் இல்லை.

``` text
A_right = +∞
```

### Case 3: `j == 0`

``` text
B_left = -∞
```

### Case 4: `j == n`

``` text
B_right = +∞
```

C++-ல் இதை:

``` cpp
INT_MIN
INT_MAX
```

மூலம் handle செய்யலாம்.

------------------------------------------------------------------------

# 📝 Step-by-Step Example

கொடுக்கப்பட்ட arrays:

``` text
A = [1, 3, 5, 7]

B = [2, 4, 6, 8, 10]
```

Sizes:

``` text
m = 4
n = 5
```

Total:

``` text
m + n = 9
```

இது Odd.

------------------------------------------------------------------------

## Step 1: Left Half Size

``` text
left_half = (m + n + 1) / 2

           = (4 + 5 + 1) / 2

           = 5
```

எனவே Left Half-ல் 5 elements இருக்க வேண்டும்.

------------------------------------------------------------------------

# 🔎 Step 2: Initial Binary Search

Array A-ல்:

``` text
low = 0
high = 4
```

முதல் முயற்சி:

``` text
i = (low + high) / 2
  = (0 + 4) / 2
  = 2
```

அதாவது A-ல் 2 elements எடுத்துக் கொள்கிறோம்.

``` text
A = [1, 3 | 5, 7]
```

எனவே:

``` text
A_left  = 3
A_right = 5
```

Left Half-ல் மொத்தம் 5 elements தேவை.

A-ல் 2 எடுத்துவிட்டோம்.

எனவே B-ல்:

``` text
j = 5 - 2
  = 3
```

elements எடுக்க வேண்டும்.

``` text
B = [2, 4, 6 | 8, 10]
```

எனவே:

``` text
B_left  = 6
B_right = 8
```

------------------------------------------------------------------------

## Step 3: Partition Check

முதல் condition:

``` text
A_left <= B_right

3 <= 8

✅ True
```

இரண்டாவது condition:

``` text
B_left <= A_right

6 <= 5

❌ False
```

Partition சரியாக இல்லை.

நமக்கு:

``` text
B_left > A_right
```

என்று தெரிகிறது.

இதன் பொருள்:

``` text
B-ல் அதிக elements Left Half-க்கு எடுத்துள்ளோம்.
```

எனவே A-ல் இன்னும் அதிக elements எடுக்க வேண்டும்.

அதனால்:

``` text
low = i + 1
```

அதாவது:

``` text
low = 3
```

------------------------------------------------------------------------

# 🔎 Step 4: Second Binary Search

இப்போது:

``` text
i = 3
```

A:

``` text
A = [1, 3, 5 | 7]
```

எனவே:

``` text
A_left  = 5
A_right = 7
```

B-ல்:

``` text
j = left_half - i
  = 5 - 3
  = 2
```

B:

``` text
B = [2, 4 | 6, 8, 10]
```

எனவே:

``` text
B_left  = 4
B_right = 6
```

------------------------------------------------------------------------

# ✅ Step 5: Valid Partition

Check 1:

``` text
A_left <= B_right

5 <= 6

✅ True
```

Check 2:

``` text
B_left <= A_right

4 <= 7

✅ True
```

எனவே சரியான partition கிடைத்துவிட்டது.

``` text
Array A: [1, 3, 5 | 7]
Array B: [2, 4   | 6, 8, 10]

             ↑
       Valid Partition
```

------------------------------------------------------------------------

# 🧮 Step 6: Median Calculation

Total elements:

``` text
9
```

இது Odd.

Odd case-ல் median:

``` text
max(A_left, B_left)
```

எனவே:

``` text
median = max(5, 4)

       = 5
```

### Answer:

``` text
5
```

------------------------------------------------------------------------

# 🧠 ஏன் `max(A_left, B_left)`?

Valid partition கிடைத்த பிறகு:

``` text
Left Half:

A: [1, 3, 5]
B: [2, 4]
```

Left Half-ல் மிகப்பெரிய element:

``` text
max(5, 4) = 5
```

Odd total elements-க்கு இதுவே நடுவில் இருக்கும் element.

------------------------------------------------------------------------

# 🧮 Even Case

Total elements even என்றால்:

``` text
Left Half | Right Half
```

இரண்டிலும் equal number of elements இருக்கும்.

Median:

``` text
max(A_left, B_left) + min(A_right, B_right)
------------------------------------------------
                       2
```

அதாவது C++:

``` cpp
(max(a_left, b_left) + min(a_right, b_right)) / 2.0
```

### Example

``` text
A = [1, 3]
B = [2, 4]
```

Merged order:

``` text
[1, 2, 3, 4]
```

Middle two:

``` text
2 and 3
```

Median:

``` text
(2 + 3) / 2 = 2.5
```

Binary-search partition:

``` text
A = [1 | 3]
B = [2 | 4]
```

So:

``` text
A_left  = 1
A_right = 3

B_left  = 2
B_right = 4
```

Median:

``` text
max(1, 2) = 2

min(3, 4) = 3

(2 + 3) / 2 = 2.5
```

------------------------------------------------------------------------

# 💻 C++ Solution

``` cpp
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

        int m = a.size();
        int n = b.size();

        // Always perform binary search on the smaller array
        if (m > n) {
            return findMedianSortedArrays(b, a);
        }

        int low = 0;
        int high = m;

        int left_half = (m + n + 1) / 2;

        while (low <= high) {

            int i = (low + high) / 2;

            // Number of elements that must be taken from B
            int j = left_half - i;

            // Boundary handling
            int a_left  = (i == 0) ? INT_MIN : a[i - 1];
            int a_right = (i == m) ? INT_MAX : a[i];

            int b_left  = (j == 0) ? INT_MIN : b[j - 1];
            int b_right = (j == n) ? INT_MAX : b[j];

            // Valid partition
            if (a_left <= b_right && b_left <= a_right) {

                // Odd number of elements
                if ((m + n) % 2 != 0) {
                    return max(a_left, b_left);
                }

                // Even number of elements
                return (max(a_left, b_left)
                      + min(a_right, b_right)) / 2.0;
            }

            // Too many elements taken from A
            else if (a_left > b_right) {
                high = i - 1;
            }

            // Too few elements taken from A
            else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};
```

------------------------------------------------------------------------

# 🔄 Binary Search Decision Logic

இந்த இரண்டு conditions-ஐ நினைவில் வைத்துக் கொள்ளுங்கள்:

``` text
A_left > B_right
```

என்றால்:

``` text
A-ல் அதிக elements எடுத்துள்ளோம்
```

எனவே:

``` text
high = i - 1
```

------------------------------------------------------------------------

மற்றொரு பக்கம்:

``` text
B_left > A_right
```

என்றால்:

``` text
A-ல் குறைவான elements எடுத்துள்ளோம்
```

எனவே:

``` text
low = i + 1
```

### நினைவில் வைத்துக்கொள்ள ஒரு shortcut

``` text
A_left > B_right
        ↓
Too much A
        ↓
Move LEFT
        ↓
high = i - 1
```

``` text
B_left > A_right
        ↓
Too little A
        ↓
Move RIGHT
        ↓
low = i + 1
```

------------------------------------------------------------------------

# 🎯 ஏன் Smaller Array-ல் Binary Search?

நாம் Binary Search செய்யும் search space:

``` text
0 ... m
```

எனவே complexity:

``` text
O(log m)
```

இங்கு `m` என்பது Binary Search செய்யும் array-ன் size.

அதனால் எப்போதும்:

``` text
m <= n
```

என்று வைத்துக் கொண்டால்:

``` text
O(log(min(m, n)))
```

கிடைக்கும்.

அதற்காக:

``` cpp
if (m > n) {
    return findMedianSortedArrays(b, a);
}
```

என்று arrays-ஐ swap செய்கிறோம்.

------------------------------------------------------------------------

# ⏱️ Complexity Analysis

## Time Complexity

Binary Search சிறிய array-ல் மட்டுமே செய்யப்படுகிறது.

``` text
O(log(min(m, n)))
```

------------------------------------------------------------------------

## Space Complexity

Extra array அல்லது data structure எதுவும் பயன்படுத்தவில்லை.

``` text
O(1)
```

Recursive swap காரணமாக அதிகபட்ச recursion depth ஒன்று மட்டுமே இருப்பதால்,
algorithm-ன் auxiliary space நடைமுறையில் `O(1)` ஆகும்.

------------------------------------------------------------------------

# 🧩 முக்கியமான கருத்துகள்

இந்த problem-ஐ solve செய்யும்போது நினைவில் வைத்துக் கொள்ள வேண்டியவை:

### 1. Arrays-ஐ merge செய்ய வேண்டாம்

``` text
Merge → O(m + n)
```

அதற்குப் பதிலாக:

``` text
Binary Search → O(log(min(m, n)))
```

------------------------------------------------------------------------

### 2. Binary Search smaller array-ல்

``` text
m <= n
```

என்று உறுதி செய்யுங்கள்.

------------------------------------------------------------------------

### 3. `j` தனியாக Binary Search செய்யப்படாது

`i` தெரிந்தவுடன்:

``` text
j = left_half - i
```

என்று நேரடியாக கிடைக்கும்.

------------------------------------------------------------------------

### 4. Cross conditions முக்கியம்

``` text
A_left <= B_right
B_left <= A_right
```

இரண்டும் true என்றால் partition valid.

------------------------------------------------------------------------

### 5. Boundary values

``` text
i == 0 → A_left  = -∞
i == m → A_right = +∞

j == 0 → B_left  = -∞
j == n → B_right = +∞
```

------------------------------------------------------------------------

# 🧠 Mental Model

இந்த problem-ஐ இப்படிப் பாருங்கள்:

``` text
             LEFT HALF       |      RIGHT HALF

Array A:       A_left        |       A_right
Array B:       B_left        |       B_right

                    ↓
          சரியான partition?
                    ↓

        A_left <= B_right
              AND
        B_left <= A_right
                    ↓
                   YES
                    ↓
                 Median
```

முழு problem-ன் சாராம்சம்:

> **இரண்டு sorted arrays-ஐ merge செய்யாமல், அவற்றின் நடுவில் ஒரு partition
> கண்டுபிடிப்பதே இந்த problem-ன் core idea.**

Binary Search அந்த partition-ஐ வேகமாக கண்டுபிடிக்கிறது.
