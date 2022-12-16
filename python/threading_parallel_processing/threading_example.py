#!/bin/env python
import threading
import time
from pprint import pprint

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

print('example 3\n'+('-'*21))


def example3():
    class CustomThread(threading.Thread):
        def run(self):
            time.sleep(1)
            print('this is coming from another thread')


    thread = CustomThread()
    thread.start()
    print('waitin for thread finish')
    thread.join()

example3()
print('-'*32)

print('example 4\n'+('-'*21))

def example4():
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

example4()
print('-'*32)

print('example 5\n'+('-'*21))
def example5():
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

example5()
print('-'*32)

print('example 5\n'+('-'*21))
def example6():
    thread = threading.Thread(name='daemon Thread',daemon=True,target=lambda:print(f'this message is from daemon thread'))
    print(f'{thread.daemon=}')
    print(f'{thread.name=}')
    thread.start()

example6()
print('-'*32)
