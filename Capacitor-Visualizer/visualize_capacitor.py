import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque
import re  # for extracting numbers

# === CONFIGURATION ===
port = '/dev/cu.usbmodem1101'        # Replace with your actual port (e.g., COM4 or /dev/ttyUSB0)
baud = 9600
max_len = 200

# === SETUP ===
data = deque([0.0]*max_len, maxlen=max_len)
ser = serial.Serial(port, baud)

fig, ax = plt.subplots()
line, = ax.plot(data)
ax.set_ylim(0, 5)

def update(frame):
    try:
        raw = ser.readline().decode().strip()
        
        # Extract first float number from the line using regex
        match = re.search(r"[-+]?\d*\.\d+|\d+", raw)
        if match:
            voltage = float(match.group())
            data.append(voltage)
            line.set_ydata(data)
            line.set_xdata(range(len(data)))
        
    except Exception as e:
        print("Error:", e)
    
    return line,

ani = animation.FuncAnimation(fig, update, interval=50)
plt.title("Real-Time Capacitor Voltage")
plt.xlabel("Time (frames)")
plt.ylabel("Voltage (V)")
plt.grid(True)
plt.tight_layout()
plt.show()