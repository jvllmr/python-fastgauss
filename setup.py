from distutils.core import setup, Extension
from shutil import copy2
from os.path import basename
from os import listdir
fastgaussmodule = Extension("fastgaussmodule",sources = ["fastgaussmodule.c"])

setup(name= "fastgaussmodule", version="1.0", description="fastest gauss in python EVER", ext_modules=[fastgaussmodule])

project_root = __file__.rstrip(basename(__file__))
build_dir = project_root + "build/"
for folder in listdir(build_dir):
    for filename in listdir(build_dir+folder):
        if ".so" in filename:
            copy2(build_dir+folder+"/"+filename,project_root+"fastgaussmodule.so")
print("Setup successful!")