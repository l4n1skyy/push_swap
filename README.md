# push_swap

## Description

`push_swap` sorts stack A in ascending order using only stack A, stack B, and permitted operations. Values must be unique signed integers. The program outputs operations only, one per line, on standard output.

## Build

```sh
make
make clean
make fclean
make re
```

## Usage

```sh
./push_swap [--bench] [--simple|--medium|--complex|--adaptive] numbers...
```

- `--simple`: O(n²) strategy.
- `--medium`: O(n√n) bucket-based strategy.
- `--complex`: O(n log n) strategy.
- `--adaptive`: select strategy using disorder.
- `--bench`: print benchmark metrics.
- No selector: use adaptive selection by default.

### Invalid Inputs
- duplicate values
- invalid numeric format
- missing arguments
- values outside the signed `int` range

## Operations

Only these operations are used:

| Operation | Effect |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the top two values in A, B, or both. |
| `pa`, `pb` | Push the top value from B to A, or A to B. |
| `ra`, `rb`, `rr` | Rotate A, B, or both upward. |
| `rra`, `rrb`, `rrr` | Reverse-rotate A, B, or both. |

There are exactly two stacks. Chunks and buckets are rank ranges, not extra
stacks or temporary containers. Node ranks are metadata attached to values.

## Ranking

Each input value receives a zero-based rank before sorting:

- smallest value: rank `0`;
- largest value: rank `n - 1`.

Algorithms use ranks for bucket and radix decisions, so negative and positive
values are handled identically.

## Algorithms

### Simple: O(n²)

The simple strategy is a min/max extraction adaptation with chunking:

1. Split the rank range into a small fixed number of logical chunks.
2. Scan A and push values belonging to the current chunk to B.
3. Rotate B when useful so smaller ranks remain accessible.
4. Starting with rank `n - 1`, find each maximum rank in B, rotate it to the
	top using `rb` or `rrb`, and push it to A with `pa`.

The maximum-rank search can scan B for every rank, giving an O(n²) upper bound
in the Push_swap operation model. It uses only A and B.

For inputs of 2, 3, and 5 values, simple uses direct rank-based cases instead
of chunking. The 5-value case pushes the two smallest ranks to B, sorts the
remaining three in A, then pushes the two values back in order.

### Medium: O(n√n)

The medium strategy uses `floor(√n)` logical buckets:

1. Divide the rank range into `floor(√n / 2)` logical buckets. This is still
	O(√n), with a smaller constant for the benchmark sizes.
2. Scan A and push only the current bucket to B. Nonmatching values stay in A
	through `ra`.
3. B contains only that bucket. Find its ranks from largest to smallest,
	rotate B with `rb` or `rrb`, and push each value to A with `pa`.
4. Repeat for the next lower bucket. Each completed bucket is placed below the
	already sorted higher ranks.

There are O(√n) bucket passes, each scanning O(n) values. Sorting one bucket
of O(√n) values costs O(n) operations in the worst case, and all buckets
together therefore cost O(n√n). B is emptied after every bucket, so no third
stack or auxiliary container is needed.

### Complex: O(n log n)

The complex strategy is an LSD radix sort on the ranks:

1. Process one binary rank bit at a time.
2. For each value in A, push bit `0` to B and rotate bit `1` in A.
3. Push all values from B back to A.
4. Repeat for every bit of the largest rank.

There are O(log n) bit passes and O(n) operations per pass, giving
O(n log n). No array or third stack is used.

### Adaptive

Before performing any moves, adaptive selection computes disorder as the ratio
of inverted pairs to all pairs:

```text
disorder = inverted_pairs / total_pairs
```

The selected strategy is:

| Disorder | Strategy | Target class |
| --- | --- | --- |
| `< 0.2` | Simple | O(n²) |
| `0.2` to `< 0.5` | Medium | O(n√n) |
| `>= 0.5` | Complex | O(n log n) |

This lets nearly sorted inputs use the simpler strategy while highly disordered
inputs use radix sorting.

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
| 100 | Simple | 621 | 712 | 656.58 | Good |
| 100 | Medium | 819 | 900 | 859.05 | Good |
| 100 | Complex | 1084 | 1084 | 1084.00 | Good |
| 100 | Adaptive | 819 | 1084 | 975.58 | Good |
| 500 | Simple | 5566 | 6057 | 5802.92 | Good |
| 500 | Medium | 8652 | 9091 | 8890.64 | Pass |
| 500 | Complex | 6784 | 6784 | 6784.00 | Good |
| 500 | Adaptive | 6784 | 9090 | 8027.56 | Pass |

All 400 runs passed the checker. At 100 values, every strategy stayed below
1500 operations. At 500 values, simple and complex stayed below 8000;
medium and adaptive stayed below the 12000 pass threshold.