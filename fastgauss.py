import timeit, fastgaussmodule

def quickmaths(n=100_000_000):
    return (n * (n-1)) / 2

def quickermaths(n=100_000_000):
    return fastgaussmodule.quickermaths(n)

print(timeit.timeit(quickmaths, number=1))
print(timeit.timeit(quickermaths, number=1))