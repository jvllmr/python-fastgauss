import timeit, fastgaussmodule

def quickmaths(n=100_000_000):
    return (n * (n-1)) / 2

def quickermaths(n=100_000_000):
    return fastgaussmodule.quickermaths(n)

if __name__ == "__main__":
    print("Without C-Module:"+ str(timeit.timeit(quickmaths, number=1)))
    print("With C-Module:"+ str(timeit.timeit(quickermaths, number=1)))