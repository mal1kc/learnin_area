#!/bin/env python
from __init__ import *

class CustomThread(threading.Thread):
    def run(self):
        time.sleep(1)
        print('this is coming from another thread')


thread = CustomThread()
thread.start()
print('waitin for thread finish')
thread.join()
