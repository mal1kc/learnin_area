#!/bin/env python
import threading
import time

print('example 1\n'+('-'*21))
def task1():
    # block for 1 second
    time.sleep(1)
    # display a message

    print('this is from another thread')


def example1():
    thread = threading.Thread(target=task1)
    thread.start()
    print('waiting fo the thread ..')
    thread.join() # explicitly waiting to finish thread

example1()
print('-'*32)

print('example 2\n'+('-'*21))
def task2(sleep_time,message):
    # block for 1 second
    time.sleep(sleep_time)
    # display a message
    print(message)


def example2():
    thread = threading.Thread(target=task2,args=(1.5,'new message from another thread'))
    thread.start()
    print('waiting fo the thread ..')
    thread.join() # explicitly waiting to finish thread

example2()

print('-'*32)
