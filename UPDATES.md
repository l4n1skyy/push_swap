# Branch Updates

Comparison between `simple_selection` and the current `medium_sort` branch.

## Algorithms

### Original `simple_sort`

The original algorithm is preserved from the simple-selection branch:

1. Search A for its minimum and maximum.
2. Calculate the rotation cost of each extreme.
3. Select and rotate the cheaper extreme to the top of A.
4. Push it to B.
5. Repeat until A is empty.
6. Rotate B to its maximum and push all values back to A.

The current version adds a `limit` parameter to the searches, position checks,
rotation calculations, and extraction loops. The core min/max behavior remains
unchanged. It is still an O(n²) selection-sort-style algorithm.

### `simple_sortv2`

The current branch also keeps a separate chunked selection adaptation in
`algo_simplev2.c`. It removes minimum selection and keeps maximum selection:

1. Divide ranks into logical chunks.
2. Scan A and push values in the current chunk to B.
3. Rotate B when useful for lower-half chunk values.
4. After distribution, find maximum ranks in B and push them back to A.

It is not pure bucket sort because it still explicitly searches for and
extracts each maximum. The chunks organize the values first; selection still
determines the final order. It remains O(n²).

For 2, 3, and 5 values, it uses direct rank-based cases for fewer operations.
It is separate from the original `simple_sort` and is not used by the normal
`--simple` selector.

## Adaptive Selection

### Before: `simple_selection`

`run_sort()` calculated disorder and passed it into `select_strategy()`:

```text
disorder = compute_disorder(*head);
used_strategy = select_strategy(head, strategy, disorder, bench_ptr);
```

The old selector used only two adaptive paths:

```c
if (disorder < 0.2)
  minmax_sort(head, bench);
else
  radix_sort(head, bench);
```

`medium_sort()` was commented out. A sorted input (`disorder == 0.0`) skipped
the selector and produced no operations.

### Now: `medium_sort`

`main()` calculates disorder and passes it with the requested strategy:

```c
disorder = compute_disorder(head);
used_strategy = select_strategy(&head, strategy, disorder, &bench);
```

Explicit requests ignore disorder and run exactly the requested algorithm.
Adaptive mode calls `adaptive_sort()`, which now supports all three strategies:

```c
disorder < 0.2        -> simple_sort()
0.2 <= disorder < 0.5 -> medium_sort()
disorder >= 0.5      -> complex_sort()
```

`select_strategy()` returns the strategy that ran, so benchmark output can
show both the requested and actual strategy. Sorted input still takes the
zero-operation fast path.

## File Organization Changes

### Before

The old branch split the selection implementation across three files:

- `algo_simple_main.c` for the main min/max sorting flow;
- `algo_simple_find.c` for minimum, maximum, and position searches;
- `algo_simple_utils.c` for rotation costs and repositioning.

It also used `selection.c` and later `utils_strategy_selection.c` for strategy
selection. Medium code was absent or commented out.

### Now

The current branch separates each algorithm and completes the application
entry point:

- `algo_simple.c` for the preserved original selection algorithm;
- `algo_simplev2.c` for `simple_sortv2`;
- `algo_medium.c` for medium bucket sorting;
- `algo_complex.c` for radix sorting;
- `utils_parse_strategy.c` for option parsing and dispatch;
- `push_swap.c` for the executable entry point and benchmark reporting.
