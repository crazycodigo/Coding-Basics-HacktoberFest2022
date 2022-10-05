from pynput.mouse import Controller
import time
j=0
mouse=Controller()



for i in range(1,30):
    j+=20
    mouse.position=(j,j)
    time.sleep(0.7)
    
