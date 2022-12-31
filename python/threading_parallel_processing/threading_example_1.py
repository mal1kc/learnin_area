#!/bin/env python
from __init__ import *

def task():
    # block for 1 second
    time.sleep(1)
    # display a message

    print('this is from another thread')

thread = threading.Thread(target=task)
thread.start()
print('waiting fo the thread ..')
thread.join() # explicitly waiting to finish thread
