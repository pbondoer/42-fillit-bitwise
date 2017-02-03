# fillit @ 42
Can you feel it?

**There is a slightly slower, but perhaps less confusing version available over
[at my first fillit](https://github.com/pbondoer/42-fillit).**

After finishing [libft](https://github.com/pbondoer/42-libft), fillit is the
second mandatory project before [get\_next\_line](https://github.com/pbondoer/
get_next_line), and after that, you branch out. The purpose is to make the
smallest possible "square" (which can contain holes) with a given list of
tetriminos, but the disposition must be as such that it returns the first
possible solution when placing them recursively from the top left.

This is a slightly more advanced version, as it uses bit-fields to store data as
well as to calculate the solution. It also prunes results in advance,
significantly improving times (see below, 7s vs 1.2s).

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

`-O3` isn't allowed on the school project, but benchmark results were added
below to show what it's really capable of. We should try this on bigger puzzles!

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```

## Benchmark
I did some quick benchmarks. Here are the results!

| Map		| Naive		| Naive -O3	| Bitwise	| Bitwise pruning	| Bitwise pruning -O3	|
| --------- | --------- | --------- | --------- | ----------------- | --------------------- |
| test\_8	| 0.03s		| 0.02s		| 0.01s		| 0.005s			| 0.004s				|
| test\_11	| 33.08s	| 21.25s	| 7.01s		| 1.85s				| 0.75s					|

## Special thanks
Thanks to my friends cchaumar and hmartzol for helping me understand what was
going on and for motivating me to try this out! I was happy with my fillit, but
now I'm twice as happy!
