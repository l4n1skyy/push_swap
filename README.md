*This project has been created as part of the 42 curriculum by lanusri-, jia-xcho.*

# push_swap

## Description

push_swap is a project with the purpose of sorting a stack of integers into ascending order, using a second stack (stack B) and a restricted set of operations, while minimizing the number of operations used.

## Instructions

### Compilation

```bash
make
make bonus
```

### Execution

```bash
./push_swap [flags] arg1 arg2 arg3 ...
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker_linux $ARG
```
The following inputs are not allowed and print `Error`:
- duplicate number
- decimal number
- letters or other characters
- outside the 32-bit range
- one quoted argument

### Strategy flags

| Flag | Strategy | Target complexity |
| --- | --- | --- |
| `--simple` | Chunk-based selection sort | O(n²) |
| `--medium` | Bucket-based sort | O(n√n) |
| `--complex` | LSD radix sort | O(n log n) |
| `--adaptive` | Measures disorder, then picks one of the above automatically | Varies |

### Benchmark mode

Pass a strategy flag and `--bench` to print the operation count on standard
error while the normal operation stream remains on standard output:

```bash
ARG="2 1 3 6 5 8"
./push_swap --bench --simple $ARG
```

| Input size | Simple | Medium | Complex |
| --- | ---: | ---: | ---: |
| 2 numbers | 1 | 5 | 3 |
| 3 numbers | 2 | 8 | 10 |
| 5 numbers | 10 | 16 | 25 |
| 100 numbers | 643 | 847 | 1084 |
| 500 numbers | 5777 | 8894 | 6784 |
| 5000 numbers | 246020 | 268740 | 100196 |
| 10000 numbers | 893396 | 757647 | 215392 |


| Input size | Pass | Good | Excellent |
| --- | ---: | ---: | ---: |
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |


## Algorithms — explanation and justification

## Simple sort — O(n²)

For small inputs, `sort_small` handles the base cases directly by rank comparison:

- **2 values:** a single `sa` if the two ranks are reversed.
- **3 values:** the correct combination of `sa`, `ra`, or `rra` is chosen from the three possible rank relationships.
- **5 values:** the two smallest ranks are pushed to B, the remaining three are sorted in A, then `pa` is used twice to restore the two smallest values in order.
- **n ≤ 100:** split range into 5 chunks, then selection sort.
- **n > 100:** split range into 10 chunks, then selection sort.

### Maximum Extraction Selection Sort Explanation
- Repeatedly find the biggest remaining rank in B and move it to A.
1. Look through B and find where the current target rank is sitting.
2. Rotate B (rb or rrb, whichever is the shorter direction) until that value is on top.
3. Push it onto A with pa.
4. Move to the next-lower rank and repeat.

Simple sort uses chunked max-extraction (rather than a plain 2-stack min/max scan) because grouping ranks into a handful of chunks first cuts down how far values have to travel before extraction, lowering the operation count while keeping the same O(n²).


## Medium sort — O(n√n)


```
bucket_count = max(1, floor(sqrt(n) / 2))
chunk_size   = ceil(n / bucket_count)
```
*** why divide sqrt(n) by 2?
constant to reduce distribution passes but increases extraction a bit, perform better in benchmarking.

- **medium_sort** = figures out how many buckets to use (√n/2) and how big each one is (chunk_size), then works through the ranks from highest down to lowest.
- **distribute_bucket** =  for the current bucket's rank range, scan A: if a value belongs in this bucket, push it to B; otherwise just rotate it out of the way in A. Same move as simple sort's chunk step.
- **sort_bucket** = same as the maximum-extraction loop from simple sort, just for one bucket.
- **move_rank_to_a** =  this is the maximum extraction step: find the target rank in B, rotate it to the top the short way (rb if it's closer to the front, rrb if closer to the back), then pa it onto A.

Medium sort was built as chunked max-extraction with √n-sized buckets (rather than, say, 3 or 4 fixed buckets like simple sort, or a fully sorted insertion approach) because shrinking the chunk size is what pushes the cost down from O(n²) to O(n√n).

## Complex sort — O(n log n)

The complex strategy is a least-significant-bit-first (LSD) radix sort on the ranks of the values.

For each bit position, from least to most significant:

1. Record how many values currently sit in A.
2. Inspect exactly that many values from the top.
3. Push each value whose current bit is 0 to B (`pb`) or rotate a value whose bit is 1 to the bottom of A (`ra`).
4. Push everything from B back to A (`pa`).

Complex sort uses radix-on-ranks (rather than a comparison-based O(n log n) sort like merge sort) because it needs no comparisons or extra data structures to reach O(n log n), every operation maps directly onto push/rotate, which fits the stack constraint of the project better.

## Adaptive mode


```
mistakes    = number of pairs where an earlier value is larger than a later one
total_pairs = n * (n - 1) / 2
disorder    = mistakes / total_pairs        (0 for n < 2)
```

`disorder` is `0.0` for an already-sorted input and `1.0` for a fully reverse-sorted one. This computation is O(n²) by nature, but it happens once.

`select_strategy()` receives the requested mode and the measured disorder. If a specific strategy (`--simple`, `--medium`, `--complex`).

| Disorder | Strategy used | Target class |
| --- | --- | --- |
| < 0.2 | `simple_sort` | O(n²) |
| 0.2 – < 0.5 | `medium_sort` | O(n√n) |
| ≥ 0.5 | `complex_sort` | O(n log n) |

## Delegation of work


- **lanusri-** — complex sort, medium sort, input validation, simple sort optimisation, utils.
- **jia-xcho** — simple sort, benchmarking, bonus, adaptive strategy, operations, input validation, utils.

## Resources

- 42 subject PDF for `push_swap`

## AI usage

- Helping to improve readability and language of README.
- Helping to debug issues as well as check for edge cases in code.