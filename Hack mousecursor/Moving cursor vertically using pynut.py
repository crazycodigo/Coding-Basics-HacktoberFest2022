from pynput.mouse import Controller
import time
j=0
mouse=Controller()



for i in range(1,38):
    j+=20
    mouse.position=(700,j)
    time.sleep(0.5)
    
