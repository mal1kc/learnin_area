#!/bin/env python
from __init__ import *
from random import random

def task(semaphore, number:int):
    # attempt to acquire the semaphore
    with semaphore:
        # process
        value = random()
        time.sleep(value)
        # report result
        print(f'thread {number} got {value}')

# create a semaphore
semaphore = threading.Semaphore()
for i in range(10):
    worker = threading.Thread(target=task,args=(semaphore, i))
    worker.start()
# wait for all workers to complete ...
