#!/usr/bin/env python3
import random
import sys

N = int(sys.argv[1])
print(" ".join(str(i) for i in random.sample(range(-2147483648, 2147483648), N)), end="")