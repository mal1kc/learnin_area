#!/bin/env python
from __init__ import *

def work():
    print('working .',end='')
    for ti in range(10):
        time.sleep(0.5)
        print('. .',end='')
    print('..')
    raise Exception('something bad happened')
def custom_hook(args):
    print(f'thread failed:{args.exc_value}')
threading.excepthook = custom_hook
thread = threading.Thread(target=work)
thread.start()
thread.join()
print('continuing on ...')
time.sleep(0.2)
print('finished')
