#!/bin/env python
from __init__ import *

class CustomThread(threading.Thread):
    def run(self):
        time.sleep(1)
        print('this is coming from another thread')
        self.value = 99

thread = CustomThread()
thread.start()
print('waitin for thread finish')
thread.join()
value = thread.value
print(f'{value=}')
