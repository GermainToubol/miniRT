import os
import subprocess
import sys
import time
import pyautogui
import numpy as np

if os.getcwd().endswith("test"):
    os.chdir("..")

ret = -1

# Compilation
# ------------------------------------------------------------------------------

print(" Start compilation ".center(25, '-'))
with subprocess.Popen(["make"], stdout=subprocess.DEVNULL) as proc:
    ret = proc.wait()
print(" End compilation ".center(25, '-'))

if ret:
    print("Compilation failure")
    sys.exit(0)

# Runtime measure
# ------------------------------------------------------------------------------

rd_times = []

with subprocess.Popen(["./miniRT", "demo/lights_colors.rt"], stdout=subprocess.PIPE) as proc:
    for i in range(15):
        time.sleep(0.7)
        if i % 2:
            pyautogui.press('a')
        else:
            pyautogui.press('d')
    pyautogui.press('esc')
    for line in proc.stdout.readlines():
        rd_times.append(float(line.decode().split()[1]))
    proc.wait()

print(f"perf: {np.mean(rd_times)} ms")
