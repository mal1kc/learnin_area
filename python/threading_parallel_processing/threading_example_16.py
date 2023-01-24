#!/bin/env python
from __init__ import *
from random import random

def task(event, number):
    # wait for the event to be set
    event.wait()
    # begin processing
    value = random()
    time.sleep(value)
    print(f'thread {number} got {value}')

# create a shared event object
event = threading.Event()
# create a suite of threads
for i in range(5):
    thread = threading.Thread(target=task,args=(event,i))
    thread.start()
# block for a moment
print(' main thread blocking ...')
time.sleep(2)
# start processing in all threads
event.set()
# wait for all threads to finnish ...
