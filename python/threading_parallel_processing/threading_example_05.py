#!/bin/env python
from __init__ import *

# create instance of Thread object with lambda func
thread = threading.Thread(target=lambda:(
time.sleep(0.2),
print('this is from another thread')
))
# report thread alive status
is_alive = thread.is_alive()
print(f'thread\'s {is_alive=}')
# report thread identifier value
ident = thread.ident
print(f'{ident=}')
# report thread daemon property
daemon = thread.daemon
print(f'{daemon=}')
name = thread.name
print(f'{name=}')
thread.start()
# report thread native id property
native_id = thread.native_id
print(f'{native_id=}')
is_alive = thread.is_alive()
print(f'{is_alive=}')
ident = thread.ident
print(f'{ident=}')
thread.join()
is_alive = thread.is_alive()
print(f'{is_alive=}')
