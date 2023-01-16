#!/bin/env python
from __init__ import *

def task(value:int):
    # create local storage
    local=threading.local()
    # store value in local storage
    local.value = value
    # block for given time
    time.sleep(value)
    # retrieve given value
    print(f'stored value: {local.value}')

# create thread and start thread
threading.Thread(target=task,args=(1,)).start()
# create another thread and start it
threading.Thread(target=task,args=(2,)).start()
