#!/bin/env python
from __init__ import *

def task(message):
    # report the message
    print(message)

# create a thread timer object
timerT = threading.Timer(3, task, args=('hello world',))
# start the timer object
timerT.start()
# wait for the timer to finish
print('waiting for the timer ...')
