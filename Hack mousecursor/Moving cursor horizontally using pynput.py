from pynput.mouse import Controller
import time
j=0
mouse=Controller()



for i in range(1,60):
    j+=20
    mouse.position=(j,300)
    time.sleep(0.5)
    
