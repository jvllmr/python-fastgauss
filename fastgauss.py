import timeit, fastgaussmodule

def quickmaths(n=100_000_000):
    return (n * (n-1)) / 2

def quickermaths(n=100_000_000):
    return fastgaussmodule.quickermaths(n)

if __name__ == "__main__":
    print("Python only: "+ str(timeit.timeit(quickmaths, number=1))+ " seconds")
    print("With Module coded in C: "+ str(timeit.timeit(quickermaths, number=1))+ " seconds")