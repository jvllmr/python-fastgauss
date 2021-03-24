# python-fastgauss


## Why did I do this? 
In his [YouTube-Video](https://www.youtube.com/watch?v=Qgevy75co8c) mCoding said the fastest way to loop in Python is by not looping in Python.
His conclusion was that it is faster to just calculate the outcome of the loop.
But there actually is another way to get faster by doing the calculation in C and importing the function into Python.
I built this example which calculates the gaussian formula in two different ways to prove / show it.
As I'm not an expert in C I mostly made this example by following [this Guide](https://docs.python.org/3/extending/extending.html) from the offical Python Documentation.

If you know a way to do it better / get faster feel free to make a pull request! :slightly_smiling_face:


## How you can try it

It works on Windows and Linux distributions.
I only tested it with Python 3 but it might also work with Python 2.

Simply clone the repository with:

`git clone https://github.com/kreyoo/python-fastgauss.git`

Compile the C-Extension for Python with:
`python setup.py build`

Run and have fun with:
`python fastgauss.py`


