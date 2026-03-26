import serial
import serial.tools.list_ports as ports
import csv
from datetime import datetime
import matplotlib.pyplot as plt
import numpy as np
import time

coms = ports.comports()
for port in coms:
    print(port.device)
    print(port.description)

com = str(input("Choose COM port (e.g. COM3): "))
ser = serial.Serial(port = com, baudrate = 9600, timeout = 1)
file_name = "Arduino_Data.csv"

while True:
    line = ser.readline().decode("utf-8").strip()

    if line:
        print(line)
#       parts = line.split(",")

#         if len(parts) == 3:
#             millis = parts[0]
#             voltage = parts[1]
#             temp = parts[2]
#
#             timestamp = datetime.now().isoformat()
#
# #           writer.writerow([timestamp, millis, voltage, temp])
# #           f.flush()
#
#             print(timestamp, voltage, temp)

# with open(file_name, "w", newline="") as f:
#     writer = csv.writer(f)
#     writer.writerow(["timestamp", "millis", "voltage_V", "temp_C"])
#
#     while True:
#         line = ser.readline().decode("utf-8").strip()
#
#         if line != "":
#             parts = line.split(",")
#
#             if len(parts) == 3:
#                 millis = parts[0]
#                 voltage = parts[1]
#                 temp = parts[2]
#
#                 timestamp = datetime.now().isoformat()
#
#                 writer.writerow([timestamp, millis, voltage, temp])
#                 f.flush()
#
#                 print(timestamp, voltage, temp)