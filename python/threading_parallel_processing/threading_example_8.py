#!/bin/env python
from __init__ import *
active_thread_count = threading.active_count()
print(f'{active_thread_count=}')
current_thread = threading.current_thread()
current_thread.name="main thread"
print(f'{current_thread=}')
print(f'{threading.get_ident()=}')
thread = threading.Thread(name='other thread',target=lambda:print(f'this message is from daemon thread'))
print(f'{threading.get_native_id()=}')
thread.start()
threads = threading.enumerate()
for th in threads:
    print(f'{th.name=}')
thread.join()
