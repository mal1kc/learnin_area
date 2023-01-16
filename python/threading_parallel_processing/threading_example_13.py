#!/bin/env python
from __init__ import *
from random import random

def report(lock,identifier):
    with lock:
        print(f'>thread {identifier} done')

def task(lock,identifier,value):
    with lock:
        print(f'> thread {identifier} sleeping for {value}')
        time.sleep(value)
        report(lock,identifier)
lock = threading.RLock()
for i in range(10):
    threading.Thread(target=task,args=(lock,i,random())).start()
