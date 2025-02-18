import os
import sys

if len(sys.argv) <= 2:
    print("NOT ENOUGH ARGUMENTS")

compiler = "gcc" if sys.argv[2].lower == "c" else "g++";

os.system(compiler + " -Werror -Wpedantic -Wall -O2 -o " + sys.argv[1] + ".out " + sys.argv[1] + "." + (sys.argv[2].lower()))
os.system("cat " + sys.argv[1] + ".txt | ./" + sys.argv[1] + ".out ")