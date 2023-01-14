#!/bin/env python
from __init__ import *
from random import random

def task(lock,identifier,value:int|float):
    # acquire the lock
    with lock:
        print(f'>thread {identifier} got the lock,sleepin for {value}')
        time.sleep(value)
# create shared lock
lock = threading.Lock()
for i in range(10):
    threading.Thread(target=task, args=(lock, i, random())).start()
