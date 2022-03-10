import numpy as np
import json
import matplotlib.pyplot as plt
with open("results_3.json") as f:
    data = json.load(f)
x = []
for i in range(20):
     x.append(i+1)



plt.plot(x, data)
plt.xlabel(r'n', fontsize=14)
plt.ylabel(r'Time', fontsize=14)
plt.title(r'$Time(n)$')
plt.show()
