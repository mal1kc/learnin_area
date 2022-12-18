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

print('example 6\n'+('-'*21))
def example6():
    thread = threading.Thread(name='daemon Thread',daemon=True,target=lambda:print(f'this message is from daemon thread'))
    print(f'{thread.daemon=}')
    print(f'{thread.name=}')
    thread.start()

example6()
print('-'*32)

print('example 7\n'+('-'*21))
def example7():
    from threading import current_thread
    thread = current_thread()
    print(f'thread;\n{thread.name=},{thread.daemon=},{thread.ident=}')

example7()
print('-'*32)

print('example 8\n'+('-'*21))
def example8():
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
example8()
print('-'*32)

print('example 9\n'+('-'*21))
def example9():
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
example9()
print('-'*32)

print('example 10\n'+('-'*21))
def example10():
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
example10()
print('-'*32)
