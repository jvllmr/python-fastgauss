import timeit, fastgaussmodule

def quickmaths(n=100_000_000):
    return (n * (n+1)) / 2

def quickermaths(n=100_000_000):
    return fastgaussmodule.quickermaths(n)

if __name__ == "__main__":
    python_time = timeit.timeit(quickmaths, number=1)
    c_time = timeit.timeit(quickmaths, number=1)
    delta = python_time - c_time

    print("Python only: "+ str(python_time) + " seconds")
    print("With Extension coded in C: "+ str(c_time) + " seconds")
    print("The implementation with the C-Extension was faster by " + str(delta) + " seconds!")