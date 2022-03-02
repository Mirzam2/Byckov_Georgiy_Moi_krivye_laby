import numpy as np
import json
import matplotlib.pyplot as plt
with open("results_2.json") as f:
    data = json.load(f)
x = []
for i in range(2177):
     x.append(i+1)
for i in range(215,1000):
    x.append(i*10+10)


plt.plot(x, data)
plt.xlabel(r'n', fontsize=14)
plt.ylabel(r'Time', fontsize=14)
plt.title(r'$Time(n)$')
plt.show()
