import numpy as np
import json
import matplotlib.pyplot as plt
y = [2889, 2103, 2423, 2787, 2927, 3042, 3142,
     3231, 3188, 3215, 3174, 3151, 3103, 3147, 3086,
     2937, 2533, 2260, 2014, 1797, 1621, 1508, 1386]
x = [0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11,
     0.12, 0.13, 0.14, 0.15, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
plt.plot(x, y)
plt.xlabel(r'n', fontsize=14)
plt.ylabel(r'Time', fontsize=14)
plt.title(r'$Time(n)$')
plt.show()
