# push_swap

## Description

`push_swap` sorts stack A in ascending order using only stack A, stack B, and permitted operations. Values must be unique signed integers. The program outputs operations only, one per line, on standard output.

## Build

### simple_sort: O(n²)

`simple_sort` is the original min/max selection adaptation used by the
`--simple` selector and by adaptive mode for low disorder. It keeps two local
stacks: A is the working stack and B is the temporary stack.

For each remaining value, it:

1. Scans the active part of A to find its minimum and maximum.
2. Finds the position of each extreme and calculates its rotation cost. A
	position in the first half uses `ra`; a position in the second half uses
	`rra`.
3. Selects whichever extreme is cheaper, rotates it to the top, and sends it
	to B with `pb`.
4. If the previous selected value was a maximum, rotates B with `rb` so the
	selected extremes stay useful for the final reconstruction.
5. After A is empty, rotates B so its maximum is on top and repeatedly uses
	`pa` to rebuild A in ascending order.

The search for the extremes is O(n) and is repeated O(n) times. Rotations also
can cost O(n) per iteration, so the Push_swap operation bound is O(n²). This
is a direct selection-sort-style algorithm: it repeatedly selects the cheapest
minimum or maximum from the remaining values.

### simple_sortv2: O(n²)

`simple_sortv2` in `algo_simplev2.c` is a separate chunk-based selection adaptation. It is not used
by `--simple`; it remains available as an alternative implementation.

For inputs of 2, 3, and 5 values it uses direct rank cases:

- 2 values: swap A only when the ranks are reversed.
- 3 values: choose the required `sa`, `ra`, or `rra` combination from the
  three rank relationships.
- 5 values: push ranks 0 and 1 to B, sort the remaining three in A, then use
  `pa` twice to restore the two smallest values in order.

For larger inputs it:

1. Uses 5 logical chunks for at most 100 values and 10 chunks above 100.
2. Scans A once for each chunk. Values whose rank belongs to the current
	range are pushed to B with `pb`; other values are rotated in A with `ra`.
3. Rotates B with `rb` when a newly pushed value belongs to the lower half of
	the current chunk.
4. Once all chunks are in B, searches for ranks from `n - 1` down to 0,
	rotates each selected rank to the top with `rb` or `rrb`, and pushes it to A
	with `pa`.

The repeated maximum searches make the general path O(n²). It uses only A and
B; chunks are rank ranges, not additional stacks.

### Medium: O(n√n)

The medium strategy processes one bucket at a time and never stores multiple
logical buckets in B. For `n` values it uses:

```text
bucket_count = max(1, floor(sqrt(n) / 2))
chunk_size   = ceil(n / bucket_count)
```

The division by 2 changes only the constant; the number of buckets remains
Θ(√n).

Buckets are processed from the highest rank range down to the lowest:

1. Calculate the current rank range. A value belongs to the bucket when
	`rank >= lower` and `rank < upper`.
2. Scan the current A from top to bottom. If a value belongs to the current
	bucket, push it to B with `pb`. Otherwise rotate A with `ra` and continue.
3. After the scan, B contains only values from the current bucket. A contains
	the unprocessed lower ranks and the buckets already completed.
4. Start with the largest rank in the bucket. Search B for that rank, choose
	`rb` or `rrb` according to its position, rotate it to the top, and push it
	to A with `pa`.
5. Repeat the previous step for every rank in the bucket, descending to the
	lower boundary.
6. Move to the next lower bucket and repeat until rank 0 has been processed.

There are Θ(√n) bucket passes, and each distribution scans at most O(n)
values, giving O(n√n). A bucket has O(√n) values. Extracting one bucket by
maximum selection costs O((√n)²) = O(n); across all buckets this is also
O(n√n). Only A and B are used.

### Complex: O(n log n)

The complex strategy is a least-significant-bit-first radix sort on ranks.
Ranks are used instead of raw numbers, so negative values do not require a
special case.

For each bit from least significant to most significant:

1. Record the current number of values in A.
2. Inspect exactly that many values from the top of A.
3. If the current bit is 0, push the value to B with `pb`.
4. If the current bit is 1, rotate it to the bottom of A with `ra`.
5. Push every value from B back to A with `pa`.

The push/rotate pass costs O(n) operations. A rank below n needs O(log n) bits,
so the total operation bound is O(n log n). The binary partition is stable
because bit-1 values stay in A in their relative order and bit-0 values are
returned from B in the order produced by the pass.

### Adaptive

Adaptive mode measures disorder before performing any sorting operation. It
examines every pair of values in the original A:

```text
mistakes = number of pairs where an earlier value is larger
total_pairs = n * (n - 1) / 2
```

The result is between 0 and 1. A sorted input has disorder 0; a reverse-sorted
input has disorder 1. Inputs with fewer than two values return disorder 0.

The entry point passes both the requested strategy and the measured disorder to
`select_strategy()`:

```c
disorder = compute_disorder(head);
used_strategy = select_strategy(&head, strategy, disorder, &bench);
```

For an explicit `--simple`, `--medium`, or `--complex` request, disorder is
not used to override the request. The requested algorithm runs directly. When
`--adaptive` is requested, `select_strategy()` calls `adaptive_sort()`, which
runs the algorithm selected by the thresholds below and returns its strategy
identifier. If disorder is `0.0`, the input is already sorted and the selector
returns without generating operations.

The thresholds are:

| Disorder | Strategy | Target class |
| --- | --- | --- |
| `< 0.2` | `simple_sort` | O(n²) |
| `0.2` to `< 0.5` | `medium_sort` | O(n√n) |
| `>= 0.5` | `complex_sort` | O(n log n) |

This keeps nearly sorted data on the original selection algorithm, uses bucket
sorting for medium disorder, and uses radix sorting for highly disordered data.
Benchmark output records both the requested strategy and the strategy actually
used, which is useful for adaptive mode.
The disorder calculation itself is O(n²), but it happens before stack
operations and is separate from each selected sorting strategy's operation
class.

## Benchmark targets


| Input | Pass | Good | Excellent |
| --- | ---: | ---: | ---: |
| 100 numbers | `< 2000` | `< 1500` | `< 700` |
| 500 numbers | `< 12000` | `< 8000` | `< 5500` |

Benchmark mode reports disorder, the selected strategy and complexity, total
operations, and counts for each operation type on standard error. The normal
operation stream remains on standard output.

### Measured Results

These results use 100 random unique signed integers for each size. Every output
was verified with `checker_linux`. The maximum determines the benchmark level;
the average is included for comparison.

| Input | Strategy | Min | Max | Average | Result |
| --- | --- | ---: | ---: | ---: | --- |
| 100 | Simple | 983 | 1287 | 1122.20 | Good |
| 100 | Medium | 819 | 900 | 859.05 | Good |
| 100 | Complex | 1084 | 1084 | 1084.00 | Good |
| 100 | Adaptive | 819 | 1084 | 975.58 | Good |
| 500 | Simple | 21027 | 24191 | 22306.21 | Fail |
| 500 | Medium | 8652 | 9091 | 8890.64 | Pass |
| 500 | Complex | 6784 | 6784 | 6784.00 | Good |
| 500 | Adaptive | 6784 | 9090 | 8027.56 | Pass |

All 400 runs passed the checker. At 100 values, `simple_sort`, medium,
complex, and adaptive stayed below 1500 operations. At 500 values, the old
`simple_sort` does not meet the 12000-operation minimum.

### Measured Results: simple_sortv2

The same 100 random inputs were tested directly with `simple_sortv2` and every
operation stream was checked with `checker_linux`.

| Input | Min | Max | Average | Result |
| --- | ---: | ---: | ---: | --- |
| 100 | 621 | 712 | 656.58 | Good |
| 500 | 5566 | 6057 | 5802.92 | Good |

`simple_sortv2` passes both benchmark sizes and is substantially more efficient
than the original `simple_sort` on large inputs.