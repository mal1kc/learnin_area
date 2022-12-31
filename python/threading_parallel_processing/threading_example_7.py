#!/bin/env python
from __init__ import *

from threading import current_thread
thread = current_thread()
print(f'thread;\n{thread.name=},{thread.daemon=},{thread.ident=}')
