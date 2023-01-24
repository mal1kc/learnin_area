#!/bin/env python
from __init__ import *
from random import random

# target function to prepare some work
def task(barrier, number):
    # generate a unique value
    value = random() * 10
    # block for a moment
    time.sleep(value)
    # report result
    print(f'thread {number} done, got: {value}')
    barrier.wait()
# create a barrier
Tbarrier = threading.Barrier(5+1)
# create the worker threads
for i in range(5):
    # start a new thread to perform some work
    worker = threading.Thread(target=task,args=(Tbarrier,i))
    worker.start()
# wait for all thread to finish
print('main thread waiting on all results ...')
Tbarrier.wait()
# report once all threads are done
print('all threads have their result')
