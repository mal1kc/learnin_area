#!/bin/env python
from __init__ import *

def task(sleep_time,message):
    # block for 1 second
    time.sleep(sleep_time)
    # display a message
    print(message)


thread = threading.Thread(target=task,args=(1.5,'new message from another thread'))
thread.start()
print('waiting fo the thread ..')
thread.join() # explicitly waiting to finish thread
