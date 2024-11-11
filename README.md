# Quine-McKluskey


Back to the drawing board

Steps:

convert minterms to binary

sort into columns based on number of 1s

compare adjacent columns to find single bit differences

repeat until all possible terms have been combined

create logical SoP expression with remaining terms

implementation:

    the terms can be number or binary strings
    the columns can be represented as arrays or unordered sets
    encapsulation?

need efficient ways to
    count 1 bits
    compare for single bit differences
    tell when all terms are accounted for