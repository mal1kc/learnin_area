#!/bin/env python
from __init__ import *

def work():
    print('working .',end='')
    for ti in range(10):
        time.sleep(0.5)
        print('. .',end='')
    print('..')
    raise Exception('something bad happened')
thread = threading.Thread(target=work)
thread.start()
thread.join()
print('continuing on ...')
time.sleep(0.2)
print('finished')
