#!/usr/bin/env python3
from random import sample
import sys

n = int(sys.argv[1])
print(" ".join(str(i) for i in sample(range(n), n)))
