import serial
import time
import pyautogui as pag
import os

stan= serial.Serial('COM20', 115200)
prev= time.time()

while True:
    got= stan.readline().decode('ascii').replace("\n", "").replace("\r", "")
    print(got)
    naya= time.time()

    if naya-prev >= 3 and got:

        os.startfile("C:\Windows\system32\cmd.exe")
        prev= time.time()