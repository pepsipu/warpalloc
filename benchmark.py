import subprocess
import statistics
import matplotlib.pyplot as plt

runs = 25
runs_array = [num + 1 for num in range(runs)]
malloc = []
walloc = []
for x in range(runs):
    malloc.append(int(subprocess.check_output(['./build/malloc_benchmark']).decode()))
    walloc.append(int(subprocess.check_output(['./build/walloc_benchmark']).decode()))

plt.plot(runs_array, malloc, label="ptalloc benchmark")
plt.plot(runs_array, walloc, label="warpalloc benchmark")
plt.legend()
plt.title("ptalloc vs warpalloc time to run the same benchmark")
plt.xlabel("Trials")
plt.ylabel("Time")
plt.xticks(runs_array)
plt.show()