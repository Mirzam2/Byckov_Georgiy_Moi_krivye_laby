import numpy as np
import json
import matplotlib.pyplot as plt
with open("results_graph_1.json") as f:
    data = json.load(f)
x = []
for i in range(100):
    x.append(i*10+10)
print(x)
plt.plot(x, data)
plt.xlabel(r'Size', fontsize=14)
plt.ylabel(r'Time', fontsize=14)
plt.title(r'$Time(Size)$')
plt.show()
