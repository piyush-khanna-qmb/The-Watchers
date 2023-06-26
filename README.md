# The-Watchers

A 2-ESP32 communication device with Uatu at one end and Kaang on another.

Uatu keeps a watch with the HCSR sensor of someone approaching and on presence of someone, or someone crossing it, sends a message to Kaang thorugh bluetooth.

Kaang on other end is connected to the PC and continuously keeps on listening from Uatu. 

Stan.py is a python program interfacing with the Kaang in which Pyserial is used to read an edge trigger coming from Uatu. On processing of a valid and confirmed signal, pyautogui library is used to automate process in computer to switch to rightmost desktop (on which workspace is opened instead of games or fun stuff on desktops on its left)
