import numpy as np
import json
import matplotlib.pyplot as plt
with open("results_1000.json") as f:
    data = json.load(f)
print(sum(data)/10**6)
"plt.hist(data, 1000, density=False, facecolor='g', alpha=0.75)"
#plt.show()