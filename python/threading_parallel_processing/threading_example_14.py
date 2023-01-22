#!/bin/env python
from __init__ import *

def task(condition, work_list):
    # block for a moment
    time.sleep(1)
    # add data to the work list
    work_list.append(2)
    # notify a waiting thread that work is done
    print('thread sending notif...')
    with condition:
        condition.notify()

# create a condition
condition = threading.Condition()
work_list = list()
print('main thread waiting for data ...')
with condition:
    # start a new thread to perform some work
    worker = threading.Thread(target=task, args=(condition,work_list))
    worker.start()
    # wait to be notified
    condition.wait()
# we know the data is ready
print(f'got data: {work_list}')
