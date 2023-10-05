#!/bin/env python
from __init__ import *
thread = threading.Thread(name='daemon Thread',daemon=True,target=lambda:print('this message is from daemon thread'))
print(f'{thread.daemon=}')
print(f'{thread.name=}')
thread.start()
