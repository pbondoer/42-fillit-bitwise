# fillit @ 42
Can you feel it?

**There is a slightly slower, but perhaps less confusing version available over
[at my first fillit](https://github.com/pbondoer/42-fillit).**

After finishing libft, fillit is the second mandatory project before
get_next_line, and after that, you branch out. The purpose is to make the
smallest possible "square" (which can contain holes) with a given list of
tetriminos, but the disposition must be as such that it returns the first
possible solution.

This is a slightly more advanced version, as it uses bit-fields to store data as
well as to calculate the solution.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

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
I did some quick benchmarks. Here's the results!

| Map		| Naive			| Bitwise		|
| test_8	| 0.03s			| 0.01s			|
| test_11	| 33.08s		| 7.01s			|

## Special thanks
Thanks to my friends @cchaumar and @hmartzol for helping me understand what was
going on and for motivating me to try this out! I was happy with my fillit, but
now I'm twice as happy!

## A little note for 42 students
Doing `fillit` as well? Don't copy code! Take a piece of paper and try figuring
it out. If you don't understand, I'll explain it to you in person or by
e-mail/Slack/whatever! Find me on the intranet, my login is the same as on
GitHub :)!

Good luck, and thanks for all the fish!
