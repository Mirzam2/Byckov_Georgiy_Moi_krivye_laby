import numpy as np
import json
import matplotlib.pyplot as plt
with open("results.json") as f:
    data = json.load(f)
x = np.linspace(100, 10000, 9901)
plt.plot(x, data)
plt.xlabel(r'N', fontsize=14)
plt.ylabel(r'P', fontsize=14)
plt.title(r'$Вероятность от количества испытаний$')
print("HELP")
plt.show()
