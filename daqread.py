import math
import matplotlib
#matplotlib.use("Qt4Agg")
from matplotlib import pyplot as plt

datapoints = []

f = open("#4.txt", "r")
raw = f.readlines()


t = []
f = []
p = []

for line in raw:
    parts = line.split(":")
    t.append(int(parts[0])/1000)
    data = parts[1].split(", ")
    f.append(float(data[0]))
    p.append(float(data[1]))
    

start = min(t)
for tid in range(0, len(t)):
    t[tid] -= start

total_imp = 0
for force in f:
    total_imp += force * 0.1
    
print("Designation: "+chr(int(math.log(total_imp / 2.5, 2) + 66))+str(int(sum(f)/len(f))))
print("Total impulse: "+str(total_imp)+ " Ns")
print("Peak pressure: "+str(max(p))+" PSI")
print("Peak thrust: "+str(max(f))+ "N")
print("Burntime: " + str(round(max(t)-min(t), 2))+"s")

ax_vel = matplotlib.pyplot.subplot(2,1,1)
matplotlib.pyplot.title("Thrust")
matplotlib.pyplot.plot(t, f)
ax_alt = matplotlib.pyplot.subplot(2,1,2, sharex=ax_vel)
matplotlib.pyplot.title("Chamber Pressure")
matplotlib.pyplot.plot(t, p)

matplotlib.pyplot.show()
