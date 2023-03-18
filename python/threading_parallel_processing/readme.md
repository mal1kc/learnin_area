
# Table of Contents

1.  [what are threads](#orgcf6e498)
2.  [thread vs process](#org9335253)
3.  [life-cycle of thread](#org744349d)
4.  [run a func in thread](#org4c6fab3)
    1.  [how to run a func in thread](#org4426654)
        1.  [example](#org71b7a62)
        2.  [example with arguments](#org503189b)
5.  [extend the thread class](#orge7aff0a)
    1.  [possible usage cases](#orgc9fe10c)
    2.  [example of extending the thread class](#orgee0a207)
    3.  [example of extending the thread class with return values](#org3b36ab6)
6.  [thread instance attributes](#org992af7f)
    1.  [thread name](#org366cfc9)
    2.  [thread daemon](#org379488f)
    3.  [thread identifier](#org9d5d3bc)
    4.  [thread native identifier](#orged41eba)
    5.  [thread alive status](#org47d81db)
        1.  [in example:](#org50bcc63)
7.  [configure threads](#orgaaa42b4)
    1.  [how to configure thread name](#orgb42dbc2)
    2.  [how to configure thread daemon](#orge9e5952)
        1.  [for example:](#org65a4a42)
8.  [whats main thread](#orga6268da)
9.  [Thread Utilities](#org7bca341)
    1.  [number of active threads](#org6490d15)
    2.  [current thread](#org9672123)
    3.  [thread identifier](#orgceba026)
    4.  [native thread identifier](#org78786ab)
    5.  [enumarate active threads](#org3c0b699)
10. [thread exception handling](#org47122aa)
    1.  [unhandled exception](#orgde50c0b)
    2.  [exception hook](#orgb209cb8)
        1.  [example](#org0d5efa9)
11. [limitation of threads in cpython](#orgdb161aa)
12. [when to use thread](#orgb24b47f)
    1.  [use threads for blocking IO](#org543eb72)
    2.  [use threads external c code (that realses the GIL)](#org12d4b10)
    3.  [use threads with (some) third-party python interpreter](#orga17cc0d)
13. [threads blocking calls](#org7e68a89)
    1.  [blocking calls on concurrency primitives](#orgb2bdae8)
    2.  [blocking calls for I/O](#org4eb22d3)
    3.  [blocking calls to sleep](#org3ae67ea)
14. [thread-local data](#org2117660)
    1.  [example](#org0df91df)
15. [thread mutex lock - *threading.Lock*](#orgd6d8a95)
    1.  [what is mutual exclusion lock](#orgc6ad994)
        1.  [why we need mutual exclusion lock](#orgf0ace02)
        2.  [description of mutex](#org408ef10)
    2.  [how to use mutex lock](#orge049d82)
        1.  [for example](#org517ead9)
    3.  [example of using mutex lock](#org3e84334)
16. [thread reentrant lock  - *threading.RLock*](#orgfae16de)
    1.  [what is reentrant lock](#org6e2364c)
        1.  [why we neet reentrant lock](#org0059070)
        2.  [description of reentrant lock](#org6c11d7c)
    2.  [how to use reentrant lock](#org5261bb1)
    3.  [example of using reentrant lock](#org0a7c07c)
17. [thread condition - *threading.Condition*](#orgc942cd2)
    1.  [what is a threading condition](#org8590788)
    2.  [how to use condition object](#org29dd753)
    3.  [example of wait and notify with a condition](#org8218e09)
18. [thread semaphore - *threading.Semaphore*](#orge3f3be0)
    1.  [what is a semaphore](#org92a58a0)
    2.  [how to use a semaphore](#org27aa1ee)
        1.  [acquiring and releasing](#org961a242)
    3.  [example](#org5adb2ea)
19. [thread event - *threading.Event*](#org3357e88)
    1.  [how to use event object](#orgc7f1f5f)
    2.  [example](#org21a2fca)
20. [timer threads - *threading.Timer*](#org697496e)
    1.  [how to use a timer thread](#org51fc538)
    2.  [example of using a timer thread](#org7071e07)
21. [thread barrier - *threading.Barrier*](#org69b2f17)
    1.  [what is barrier](#orgfdd0cfa)
    2.  [how to use barrier](#org0cb927b)
    3.  [example](#org43274a9)
22. [pyhton : threading best practices](#orgae218ad)
    1.  [tip 1: use context managers](#org065dcee)
        1.  [not use this](#org0c4e4c9)
        2.  [use this for better control over threads (more safe)](#orgc7d13b8)
        3.  [the real benefit](#org1978ada)
    2.  [tip 2 : Use timedouts when waiting](#org4e53ccc)
    3.  [tip 3: use a mutex to protect critical sections](#org3a493df)
    4.  [tip 4: acquire locks in order](#org8f36c11)
23. [resources - read more about](#org56057a3)



<a id="orgcf6e498"></a>

# what are threads

threads refers to thread of execution in computer program

> Thread: The operating system object that executes the instructions of a process
> 
> -   book: page 273,the art of concurrency,2009.

when we run python script, it starts an instance of python interpreter that runs our code in the main thread.
the main threads is the default thread of a python process

we may develop our program to  perform tasks concurrently in that case we may need threads,these are concurrent threads of execution without our program
example of this will be:

-   execution function calls concurrently
-   execution object methods concurrently

a python thread is an object representation of native thread provided by operating system

when we create and run a new thread, Python will make system calls on the underplaying op. system and request new thread be created and start running new thread

the code in new threads may or may not be executed in parallel,even though the threads are executed concurrently.

these are number of reasons for this,such as:

-   the underplaying hardware may or may not support parallel execution (e.g. one vs multiple CPU cores)
-   the python interpreter may or may not permit multiple threads execute in parallel

> this highlights the distinction between concurrent and parallel execution

-   **Concurrent** : Code that can be executed out of order
-   **Parallel** : Capability to execute code simultaneously


<a id="org9335253"></a>

# thread vs process

a process refers to a computer process

> process: the operating system&rsquo;s spawned and controlled entity that encapsulates an executing application.
> a process has two main functions. the first is to act as the resource holder for the application,
> and the second is to execute the instructions of the application.
> 
> -   book: page 271,the art of concurrency,2009

the op system controls how new processes are created on some system,that may require spawning a new process,and on others,it may require that process is forked.
in Cpython implementation we not need to worry because python interpreter is manage
creating new processes.

a thread always exists within a process and represents the manner in which instructions or code is executed.

a process will have at least one thread, called the main thread.Any additional
threads that we create within the process will belong to that process.

the python process will terminate once all(non background threads) are terminated

-   **process**: an instance of the python interpreter has at least one thread called MainThread
-   **thread**: a thread of execution within Python process,such as the MainThread or new thread.


<a id="org744349d"></a>

# life-cycle of thread

a thread in python is object instanced from  **threading.Thread** class

once a thread is started, interpreter will interface with the operating system and request that new native thread be created. the instance of **threading.Thread**
the provides a python-based reference to his underplaying native thread.

each thread follows same life-cycle . understanding of its life-cycle help with
concurrent programming in python.

for example:

-   the difference between creating and starting a thread

-   the difference between run and start

-   the difference between blocked and terminated

while running, the thread may be executing code or may be blocked,waiting on something such as another thread or external resource.although, not all threads may block, it is optional base on specific use case for the new thread.

1.  new thread
2.  running thread
    1.  blocked thread (optimal).
3.  terminated thread.

A new thread is a thread that has been constructed by. creating an instance of the **threading.Thread** class

a new thread can transition to a running thread by calling the start() function.

a running thread may block in many ways, such as reading or writing from a file or a socket or by waiting on concurrency primitive such as semaphore or a lock
after blocking,the thread will run again.

finally, a thread may terminate once it has finished executing its code or by raising
error or exception

[[./thread-life-cycle.webp][thread life cycle diagr


<a id="org4c6fab3"></a>

# run a func in thread

python funcs can executed in a separate thread using **threading.Thread** class


<a id="org4426654"></a>

## how to run a func in thread

the func executed in another thread may have args in which case can be specified as a tuple and passed to the &ldquo;**args**&rdquo; argument of the threading.threading class constructor or as dictionart to the &ldquo;**kwargs**&rdquo; argument.

the **start()** func will return immediately and the operating system will execute    the function in a seperate thread as soon as it is able.

we do not have control over when the thread will execute precisely or which cpu core wwill execute it. both of these are low-level responsibilities that are handled by operating system.

> doing nessesary imports for examples

    
    # doing nessesary imports for examples
    import threading
    import time


<a id="org71b7a62"></a>

### example

    from __init__ import *
    
    def task():
        # block for 1 second
        time.sleep(1)
        # display a message
    
        print('this is from another thread')
    
    thread = threading.Thread(target=task)
    thread.start()
    print('waiting fo the thread ..')
    thread.join() # explicitly waiting to finish thread

running the example first creates instance  of threeding.Thread then calls the **start()** func.This does not start the thread immediately,but instead allows to operating system to schedule the function to execute as soon as possible.

the main thread then prints a message &rsquo;*waiting &#x2026;*&rsquo; ,then calls the **join()** function to explicitly block and wait for the new thread to finish executing.


<a id="org503189b"></a>

### example with arguments

    from __init__ import *
    
    def task(sleep_time,message):
        # block for 1 second
        time.sleep(sleep_time)
        # display a message
        print(message)
    
    
    thread = threading.Thread(target=task,args=(1.5,'new message from another thread'))
    thread.start()
    print('waiting fo the thread ..')
    thread.join() # explicitly waiting to finish thread


<a id="orge7aff0a"></a>

# extend the thread class

we can also execute funcs in another thread by extending the **threading.Thread** class and overriding the run() function.

In this section we will look at some examples of extending **thread.Thread** class


<a id="orgc9fe10c"></a>

## possible usage cases

given that it is a custom class,you can defina a constructor for the class and use it to pass in data that may be needed in the **run()** function, stored as instance variables (attributes).

you can also define additional functions on the class to split up the work you may need to complete another thread.

finally, attributes caan also be used to store the results of any calculation or IO performed in another thread that may be need to be retrieved afterward.


<a id="orgee0a207"></a>

## example of extending the thread class

example code :

    class CustomThread(Thread):
        ...

this will inherit **Thread** class to our **CustomThread** class,then we need override
**run()** func to execute another threads funcs,overriding a function very basic as syntax:

    def run(self):
        sleep(1)
        print('this is coming from another thread')
    
    # create the thread
    thread = CustomThread()
    
    # start the thread
    
    thread.start()
    
    # wait for the thread finish
    
    print('waiting for the thread to finish')
    
    thread.join()

complete code would be like:

    from __init__ import *
    
    class CustomThread(threading.Thread):
        def run(self):
            time.sleep(1)
            print('this is coming from another thread')
    
    
    thread = CustomThread()
    thread.start()
    print('waitin for thread finish')
    thread.join()


<a id="org3b36ab6"></a>

## example of extending the thread class with return values

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


<a id="org992af7f"></a>

# thread instance attributes

an instance of the thread class provides a handle of a thread of execution.
it provides attributes that we can use to query properties and the status of the underlaying thread.


<a id="org366cfc9"></a>

## thread name

threads are named automatically in a somewhat unique manner within each process withe the form &ldquo;Thread-%d&rdquo; where %d is the integer indicating the thread number within the process,e.g. Thread-1 for the first thread created.


<a id="org379488f"></a>

## thread daemon

a thread may be a deamon thread, daemon threads is the name givent to background threads.by default threads are non-daemon threads.

a python program will only exit when all non-daemon threads have finished exiting. for example , the main threads is a non-daemon threads.this means that daemon threads can run in the background and do not have to finish or be explicitly excited for the program end.


<a id="org9d5d3bc"></a>

## thread identifier

each thread has unique identifier (id) within python process,assigned by python interpreter.

the identifier is a read-only positive integer value and is assigned only after thread has been started.

can be accesed via **&ldquo;ident&rdquo;** property


<a id="orged41eba"></a>

## thread native identifier

each thread has unique identifier assigned by the operating system.

python threads (cpython) are real native threads,means that each thread we created is actually created and managed (scheduled) by operating system.As such, the operating system will assing a unique integer to each thread that is created on the system (across processes).

can be acced via **&ldquo;native<sub>id</sub>&rdquo;** property

it is assigned after thread has been started


<a id="org47d81db"></a>

## thread alive status

thread class property that holds is thread running or dead (non-started or finished)


<a id="org50bcc63"></a>

### in example:

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


<a id="orgaaa42b4"></a>

# configure threads


<a id="orgb42dbc2"></a>

## how to configure thread name

the name of a thread can be ser via the **&ldquo;name&rdquo;** argument in the threading.Thread constructor


<a id="orge9e5952"></a>

## how to configure thread daemon

a thread may be configured to be a daemon or not,and most threads in concurrent programming,including the main thread,are non-daemon threads(no background threads) by default

can be configured via setting **&ldquo;daemon&rdquo;** argument to True in the constructor


<a id="org65a4a42"></a>

### for example:

    from __init__ import *
    thread = threading.Thread(name='daemon Thread',daemon=True,target=lambda:print(f'this message is from daemon thread'))
    print(f'{thread.daemon=}')
    print(f'{thread.name=}')
    thread.start()


<a id="orga6268da"></a>

# whats main thread

each python process is created with one default thread called the **&ldquo;the main thread&rdquo;**

when we execute a python program, it is executing in the main thread.

the main thread is created for each python process

> in normal conditions, the main thread is thread from which the python interpreter was started.

&#x2013; [threading &#x2013; Thread-based parallelism](https://docs.python.org/3/library/threading.html)

the main thread in each python process always has the name **&ldquo;MainThread&rdquo;** and is not a daemon thread.Once the **&ldquo;main thread&rdquo;** exists,the Python will exit,assuming there are non-daemon threads running.

> there is a &ldquo;main thread&rdquo; object;this corresponds to initial thread of control in python program.It is not a daemon thread.

&#x2013; [threading &#x2013; Thread-based parallelism](https://docs.python.org/3/library/threading.html)

we can acquire a main thread by calling **threadin.current<sub>thread</sub>()**

    from __init__ import *
    
    from threading import current_thread
    thread = current_thread()
    print(f'thread;\n{thread.name=},{thread.daemon=},{thread.ident=}')


<a id="org7bca341"></a>

# Thread Utilities


<a id="org6490d15"></a>

## number of active threads

**threading.active<sub>count</sub>()** gives integer that indicates number of threads that are &ldquo;alive&rdquo;


<a id="org9672123"></a>

## current thread

**threading.current<sub>thread</sub>()** gives **threading.Thread** instance of thread running the current code


<a id="orgceba026"></a>

## thread identifier

**threading.get<sub>ident</sub>()** gives current threads identifier integer


<a id="org78786ab"></a>

## native thread identifier

**threading.get<sub>ident</sub>()** gives current threads identifier integer that assigned by operating system


<a id="org3c0b699"></a>

## enumarate active threads

we can get a list of active threads via calling **threading.enumarate()** function,it returns list of active threads

    
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


<a id="org47122aa"></a>

# thread exception handling


<a id="orgde50c0b"></a>

## unhandled exception

an unhandled exception can occur in a new thread.

the effect will be that the thread will unwind and report the message on standart
error.Unwinding the thread means that the thread will stop executing at the point of the (or error) and that the exception will bubble up the stack in the thread until it reaches the top level,e.g. the run() funtion.

    from __init__ import *
    
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


<a id="orgb209cb8"></a>

## exception hook

we can specify how to handle unhandled errors aand exceptions that occuur within new threads via the exception hook

by default,there is no exception hook, in which case the **[sys.excepthook function](https://docs.python.org/3/library/sys.html#sys.excepthook)**
is called that reports the familiar message.

first, we must define a function that takes a single argument that will be an instance of the **ExceptHookArgs** class,containing details of the exception and thread


<a id="org0d5efa9"></a>

### example

    
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


<a id="orgdb161aa"></a>

# limitation of threads in cpython

python interpreter generally does not permit more than one thread to run at a time

this is achieved via mutal exclusion (mutex) lock within interpreter that ensures that only one thread at a time can execute python bytecodes in python virtual machine .

> In CPython, due to the Global Interpreter Lock, only one thread can execute Python code at once (even though certain performance-oriented libraries might overcome this limitation).

&#x2013; [threading &#x2013; Thread-based parallelism](https://docs.python.org/3/library/threading.html)

this lock is referred to as the **Global interpreter Lock** or **GIL** for short.

> In CPython, the global interpreter lock, or GIL, is a mutex that protects access to Python objects, preventing multiple threads from executing Python bytecodes at once. The GIL prevents race conditions and ensures thread safety.

&#x2013; [GLOBAL INTERPRETER LOCK, PYTHON WIKI](https://wiki.python.org/moin/GlobalInterpreterLock)

this means that although we might write concurent code  with threads and run our code  on hardware with many CPU cores, we may not be able to execute our code in parallel

there are some exceptions to this.

specially, the **GIL** is released by the Python interpreter sometimes to allow other threads to run.

such as when the thread is blocked ,such as performing IO with socket or file, or often if the thread is executing computationally intesive code in C library,like hashing bytes.

> Luckily, many potentially blocking or long-running operations, such as I/O, image processing, and NumPy number crunching, happen outside the GIL. Therefore it is only in multithreaded programs that spend a lot of time inside the GIL, interpreting CPython bytecode, that the GIL becomes a bottleneck.

&#x2013; [GLOBAL INTERPRETER LOCK, PYTHON WIKI](https://wiki.python.org/moin/GlobalInterpreterLock)

therefore, although in most cases Cpython will prevent parallel execution of threads, it is allowed in some circumstances,these  circumstances represent the base use case for adopting threads in our python programs.


<a id="orgb24b47f"></a>

# when to use thread

there are times when the GIL lock is released by the interpreter and we can achieve  parallel execution of our concurent code in python.

**examples of when lock is released include:**

-   when thread is performing blocking IO

-   when a thread is executing C code  and explicitly releases

**there are also ways of avoiding the lock entirely,such a:**

-   using third-party interpreter to execute python code


<a id="org543eb72"></a>

## use threads for blocking IO

should use threads for IO bound tasks.

an IO-bound task is a type of tash that involves reading from or writing to device, file, or socket connection.

modern CPUs, like a 4GHz CPU, can execute 4 billion instructions per second, and you likely have more than one CPU core in your system.

doing IO is very slow compared to the speed of CPUs.

interacting with devices,reading  and writing files and socket connections involves calling instructions in your operating system ,which will wait for the operation to complete. If this operation is the main focus for your Cpu ,such as executing in the main thread of your python program,then your cpu is going to wait many milliseconds or even many seconds doing nothing.

that is probably preventing billions of operations from executing.

a thread performing an IO operation will block for the duration of the operation.While blocked,this signals to the operating system that a thread can be suspended and onether thread can execute, called a context switch.

additonally, python interpreter will release the GIL when performing blocking IO operations,allowing other threads within the python process to execute.

therefore, blocking IO provides an excellent use case for using threads in python.

examples of blocking IO operations include:

-   reading or writing a file from the hard drive.

-   reading or writing to standart output, input or error(stdin,stdout,stderr).

-   printing a document.

-   reading or writing bytes on a socket connection with a server.

-   downloading or uplading a file.

-   query a server.

-   query a database.

-   taking a photo.

-   everythin that includes disk write read


<a id="org12d4b10"></a>

## use threads external c code (that realses the GIL)

we may make function calls that themselves call down into a third-party C library.

Often these function calls will realase the GIL as the C library being called will not interact with the intpreter.

this provides an opputunity for other threads in the python process to run.

**for example**,when using the &ldquo;**hash**&rdquo; module in python std library,the GIL is released when hashing the data via the [hash.update() function](https://docs.python.org/3/library/hashlib.html#hashlib.hash.update)

> The Python GIL is released to allow other threads to run while hash updates on data larger than 2047 bytes is taking place when using hash algorithms supplied by OpenSSL.

&#x2013; [HASHLIB — SECURE HASHES AND MESSAGE DIGESTS](https://docs.python.org/3/library/hashlib.html)

Another example is the NumPy library for managing arrays of data which will release the GIL when performing functions on arrays.

> The exceptions are few but important: while a thread is waiting for IO (for you to type something, say, or for something to come in the network) python releases the GIL so other threads can run. And, more importantly for us, while numpy is doing an array operation, python also releases the GIL.

&#x2013; [WRITE MULTITHREADED OR MULTIPROCESS CODE, SCIPY COOKBOOK](https://scipy-cookbook.readthedocs.io/items/ParallelProgramming.html)


<a id="orga17cc0d"></a>

## use threads with (some) third-party python interpreter

there are alternate commericial and open source python interpreters that you can acquire and use to execute your python code.

some python interpreters may implement a GIL and release it more or less than Cpython. Other interpreters remove the GIL entirely and allow multiple python concurent threads to execute in parallel.


<a id="org7e68a89"></a>

# threads blocking calls

a blocking call is a function call that does not return until is complete.

all normal functions are blocking calls.

blocking call are calls to functions that will wait for a specific condition and signal to the operating system that nothing interesting going on while the thread is waiting.

the os may notice that a thread is making a blocking function call and decide to context switch to another thread.

you may recall that the os manages what threads should run and when to run them.it achieves this using a type of multitasking where a running thread is suspended and suspended thread is restored and continues running.This suspending and restoring of threads is called a context switch.

the os prefers to context switch away from blocked threads, allowing non-blocked threads to run.

this means if a thread makes a blocking function call,a call that waits, then it is likely to signal that the thread can be suspended and allow other threads to run.

similarly, many function calls that we may traditionally think block may have non-blocking versions in modern non-blocking concurrency APIs, like asyncio.

there are three types of blocking function calls you need to consider in concurrent programming, they are:

-   blocking calls on concurent primitives

-   blocking calls for IO

-   blocking calls to sleep


<a id="orgb2bdae8"></a>

## blocking calls on concurrency primitives

there are many blocking calls in concurrent programming

common ways are;

-   waiting for a lock,e.g. calling acquire() from &rsquo;threading.Lock&rsquo; class
-   waiting to be notified,e.g. calling wait() from &rsquo;threading.Condition&rsquo; class
-   waiting for a thread to terminate ,e.g. calling join() from &rsquo;threading.Thread&rsquo; class
-   waiting for an event,e.g. calling wait() from &rsquo;threading.Event&rsquo; class
-   waiting for a barrier,e.g. calling wait() from &rsquo;threading.Barrier&rsquo; class


<a id="org4eb22d3"></a>

## blocking calls for I/O

conventionally,function calls that interact with I/O are mostly blocking calls.they are blocking in same sencse as blocking calls in concurency primitives
the wait for the I/O device respond is another signal to operating system that the thread can be context switched.

common examples are;

-   **hdd(hard disk drive)** :reading,writing,appending,renaming,deleting,.. files
-   **perpheral devices**    :mouse,keyboard,screen,printe,camera,serial device etc.
-   **database**             :sql queries
-   **internet**             :downloading,uplading,http requests,etc.
    -   **email**                :send,receieve,querry inbox,etc.
-   **and more,mostly other socket related things**

performing I/O operations with devices is typically very slow compared to CPU operations.

the I/O with devices is coordinated by the operating system and the device.this means the operating system can gather or sen some bytes from or to device.this means operating system can gather or send some bytes from or to the device then context switch back to the blocking thread when needed allowing the function call to progress.


<a id="org3ae67ea"></a>

## blocking calls to sleep

the sleep() function is a capability provided by the underlying operating system that we can make use of within our program.

it is a blocking function call that pauses the thread to block for a fixed time in seconds.
in cpython this can be achieved via **&rsquo;sleep(seconds)&rsquo;** function call from built-in **time** module

    
    # sleep for 5 seconds
    import time
    ...
    time.sleep(5)
    ...

it is a blocking call it signals to the operating system that the thread is waiting and is a good candidate for a context switch.

sleeps are often ısed when timing is important in an application.

in programming, adding a sleep can be useful way to simulate waiting within fixed interval.

sleep often used in worked examples when demonstrating concurrency programming,but adding sleeps to code can also aid in unit testing and debugging concurency failure conditions,such as race conditions by forcing mistiming of events within a dynamic application


<a id="org2117660"></a>

# thread-local data

threads can store local data via an instance of the **threading.local** class

example

    import threading
    # create a instance of local class
    
    local = threading.local()
    
    # store some data
    local.custom = 33

importantly,other threads can use the same property names on local but the values will be limited to each thread.
this is like a namespace limited to each thread and is called &ldquo;thread-local data&rdquo;.it means that threads cannot acces or read the local data of other threads.
importantly, each thread must hang on to the &ldquo;local&rdquo; instance in order to acces the stored data.


<a id="org0df91df"></a>

## example

    
    from __init__ import *
    
    def task(value:int):
        # create local storage
        local=threading.local()
        # store value in local storage
        local.value = value
        # block for given time
        time.sleep(value)
        # retrieve given value
        print(f'stored value: {local.value}')
    
    # create thread and start thread
    threading.Thread(target=task,args=(1,)).start()
    # create another thread and start it
    threading.Thread(target=task,args=(2,)).start()


<a id="orgd6d8a95"></a>

# thread mutex lock - *threading.Lock*


<a id="orgc6ad994"></a>

## what is mutual exclusion lock


<a id="orgf0ace02"></a>

### why we need mutual exclusion lock

<div class="org-center">
<p>
a <span class="underline">mutual exclusion lock</span> is a synchronization primitive intented to prevent a race condition.
</p>

<p>
a race conditions is a concurency failure case when two threads run same code and access or update same resource leaving the resource unkown and inconsistent state.
these censitive parts of cade that can be executed by multiple threads concurently and may result in race conditions are called critical sections, a critical
section may refer to single block of code, but is also refers to multiple accesses to the same data variable or resource from multiple functions.
</p>
</div>


<a id="org408ef10"></a>

### description of mutex

<div class="org-center">
<p>
mutual exclusion lock also known as mutex,is synchronization mechanism used to control acces to a shared resource in concurent system.A mutex is essentially a binary semaphore (e.g railroad switch signals) with two states;locked and unlocked.When a thread acquires a mutex,it sets the lock to locked state,preventing other threads from also acquiring the lock.The thread that acquire the lock is said to have exclusive acces to the shared resource.When the thread releases the lock.The thread that acquired the lock is said to gave exclusive access to the shared resource.When the thread releases the lock,it sets the lock to the unlocked state, allowing other thread to acquire the lock and gain access to the shared resource.this mechanism ensures that only one thread can access resource at a time, preventing race conditions and other synchronization issues.
</p>
</div>


<a id="orge049d82"></a>

## how to use mutex lock

<div class="org-center">
<p>
the class implementing primitive lock objects.
</p>

<p>
NOTE : that <span class="underline">Lock</span> is actually a factory function which returns an instance of the most efficient version of the concrete Lock class that is supported by the platform
</p>
</div>

    # create a lock
    lock = threading.Lock()
    # acquire the lock
    # ...
    # release the lock
    lock.release()

only one thread can acquire lock,if lock not released it cannot be acquired again.

the thread attempting to acquire the lock will block until the lock is acquired, such as if another thread currently holds the lock then releases it.

we can attempt to acquire the lock without blocking by setting the &ldquo;blocking&rdquo; arg to **False**. if the lock cannot be acquired,a value of **False** is returned.

    ...
    # acquire the lock without blocking
    lock.acquire(blocking=false)

we can also attempt to acquire the lock with a timeout,If the lock cannot be acquired a **False** returned.

    ...
    # acquire the lock with a timeout
    lock.acquire(timeout=10)


<a id="org517ead9"></a>

### for example

    ...
    # create a lock
    lock = threading.Lock()
    # acquire the lock
    with lock:
        # ...

this is preffered usage as it makes it clear where the protected code starts and ends,and ensures that the lock is always released, even if there is an exception or error within the critical section.

also we can check if the lock is currently acquired by a thread

    if lock.locked():
        # if lock is acquired runs this indent block of code
    else:
        # if not lock is acquired runs this indent block of code


<a id="org3e84334"></a>

## example of using mutex lock

    
    from __init__ import *
    from random import random
    
    def task(lock,identifier,value:int|float):
        # acquire the lock
        with lock:
            print(f'>thread {identifier} got the lock,sleepin for {value}')
            time.sleep(value)
    # create shared lock
    lock = threading.Lock()
    for i in range(10):
        threading.Thread(target=task, args=(lock, i, random())).start()


<a id="orgfae16de"></a>

# thread reentrant lock  - *threading.RLock*


<a id="org6e2364c"></a>

## what is reentrant lock

a reentrant mutual exclusion lock aka &ldquo;reenrant mutex&rdquo; or &ldquo;reentrant lock&rdquo; for short, is like a mutex lock except it allows a thread to acquire the lock more than once.

> a reentrant lock is synchranization primitive that may be acquired multiple times by the same thread [&#x2026;] In the locked state,some thread owns the lock;in the unlocked state no thread owns it

&#x2013; [rlock objects &#x2013; Thread-based parallelism](https://docs.python.org/3/library/threading.html#rlock-objects.html)


<a id="org0059070"></a>

### why we neet reentrant lock

we can imagine critical sections spread across a number of funcstions,each protected by the same lock.A thread may call across these functions in course of normal execution and may call into one critical section from another critical section.

a limitation of a (non-reentrant) mutex lock is that if a thread has acquired the lock that it cannot acquire it again.In fact, this situation will result in a deadblock as it will wait forever for the lock to be released so that it can be acquired, but it holds the lock and will not release it.


<a id="org6c11d7c"></a>

### description of reentrant lock

a reenrant lock will allow a thread to acquire the same lock again if it has already acquired it.This allows the thread to execute critical sections from within critical sections,as long as they are protected by same reentrant lock.

each time a thread acquires the lock it must also release it, meaning that are recursive levels of acquire and release for the owning thread.As such,this type of lock is sometimes called a &ldquo;recursive mutex lock&rdquo;.


<a id="org5261bb1"></a>

## how to use reentrant lock

    ...
    # create reentrant lock
    lock = RLock()
    # acquires the lock
    lock.acquire()
    ...
    # release the lock
    lock.release()

the thread attempting to acquire the lock will block until the lock is acquired, such as if another thread currently holds the lock (once or more than once) then releases it.

we can use &ldquo;**blocking**&rdquo; argument and &ldquo;**timeout**&rdquo; argument like normal mutex lock.
bonus: we can use via &rsquo;**with**&rsquo; keyword for safety.


<a id="org0a7c07c"></a>

## example of using reentrant lock

    
    from __init__ import *
    from random import random
    
    def report(lock,identifier):
        with lock:
            print(f'>thread {identifier} done')
    
    def task(lock,identifier,value):
        with lock:
            print(f'> thread {identifier} sleeping for {value}')
            time.sleep(value)
            report(lock,identifier)
    lock = threading.RLock()
    for i in range(10):
        threading.Thread(target=task,args=(lock,i,random())).start()

running the examples creates 10 threads with target as task function.
then executes them.only one thread can acquire the lock at time,and then once acquired,blocks and then reenters the same lock again to report the done message.

if non-reentrant lock,e.g. a threading.Lock was used instead,then the thread would block forever waiting for the lock to become available,which it can&rsquo;t because the thread already holds the lock.


<a id="orgc942cd2"></a>

# thread condition - *threading.Condition*


<a id="org8590788"></a>

## what is a threading condition

in concurency,a condition (also called a monitor) allows multiple threads to be notified about some result.

it combines both a mutual exclusion lock(mutex) and a conditional variable.

a mutex allow can be used to protect a critical section, but it cannot be used to alert other threads that a condition has changed or been met.

a condition can be acquired by a thread(like a mutex) after which it canbe wait to be notified by another thread that something has changed. while waiting, the thread is blocked and releases the lock for other threads to acquire.

another thread can then acquire the condition, make change, and notify one, all, or a subset of threads waiting on the condition that something has changed. the waiting thread can then wake-up (be scheduled by the op. sys.), reacquire the condition  (mutex), perform checks on any changed state and perform required actions.

this highlights that a condition and to allow threads to notify other threads waiting on the condition.


<a id="org29dd753"></a>

## how to use condition object

we can create condition object by default it will create a new reentrant mutex lock (**threading.RLock**).

    ...
    # create a new condition
    
    condition = threading.Condition()

we may have a reentrant or non-reentrant mutex that we wish to reuse in the condition for some good reason, in which case we can provide it to the constructor.

this is unrecommended unless you know your use case has this requirement.The chance of getting into trouble is high.

    ...
    # create a new condition with custom lock
    
    condition = threading.Condition(lock=my_lock)

**we can aquire and release conditions like the Locks**

    ...
    # acquire the condition
    condition.acquire()
    # wait to be notified
    condition.wait()
    # release the condition
    condition.release()
    
    # alternate way of doing same things
    
    # acquire the condition
    with condition:
        # wait to be notified
        condition.wait()

we can notify a single waitinh thread viaa the notify function.

    ...
    # acquire the condition
    with condition:
        # notify a waiting thread
        condition.notify()
    ...

the notified thread will stop-blocking as soon as it can re-acquire the mutex within condition.This will be attemted automatically as part of its call to wait(), you do not need to do anything extra.

if there are more than one thread waiting on the condition, we will not know which thread will be notified.

we can notify all threads waitinh on yhe condition via the notify<sub>all</sub>() function.

    ...
    # acquire the condition
    with condition:
        # notify all threads waiting on the condition
        condition.notify_all()
    ...


<a id="org8218e09"></a>

## example of wait and notify with a condition

    from __init__ import *
    
    def task(condition, work_list):
        # block for a moment
        time.sleep(1)
        # add data to the work list
        work_list.append(2)
        # notify a waiting thread that work is done
        print('thread sending notif...')
        with condition:
            condition.notify()
    
    # create a condition
    condition = threading.Condition()
    work_list = list()
    print('main thread waiting for data ...')
    with condition:
        # start a new thread to perform some work
        worker = threading.Thread(target=task, args=(condition,work_list))
        worker.start()
        # wait to be notified
        condition.wait()
    # we know the data is ready
    print(f'got data: {work_list}')


<a id="orge3f3be0"></a>

# thread semaphore - *threading.Semaphore*

a semaphore is essentially a counter protected by a mutex lock used to limit the number of threads that can acces a resource.


<a id="org92a58a0"></a>

## what is a semaphore

a semaphore is a concurency primitive that allows a limit on the number of threads that can acquire a lock protecting a critical section.

it is an extension of a mutual exclusion (mutex) lock that adds a count for the number of threads that can acquire the lock before additional threads will block. once full, new threads can only acquire a position on the semaphore once existing thread holding the semaphore releases a position.

internally, the semaphore maintains a counter protected by a mutex lock that is incremented each time the semphore is acquired and decremented each time it released.

when semaphore is created, the upper limit on the counter is set. If it is set to be 1, then the semphore will operate like a mutex lock.

A semaphore provides a useful concurency, in examples:

-   limiting concurent;
    -   socket connections to a server.
    -   file operations on a hard drive.
    -   calculations


<a id="org27aa1ee"></a>

## how to use a semaphore

the **threading.Semaphore** instance must be configured when it is created to set the limit on the internal counter.This limit will match the number of concurrent threads that can hold the semaphore.

in example

    ...
    # create a semaphore with a limit of 100
    semaphore = Semaphore(100)

in this implementation,each time the semaphore is acquired,the internal counter is decremented. each time the semaphore is released, the internal counter is incremented.The semephore cannot be acquired if the semphore has no avaliable positions in which case, threads attempting to acquire it must block until a postion becomes avaliable.


<a id="org961a242"></a>

### acquiring and releasing

    ...
    # acquire the semphore without blocking
    semphore.acquire(blocking=False)
    # acquire the semaphore with a timeout
    semaphore.acquire(timeout=19)
    # release the semaphore
    semaphore.release()
    
    # acquire the semphore
    with semphore:
        # ...


<a id="org5adb2ea"></a>

## example

    from __init__ import *
    from random import random
    
    def task(semaphore, number:int):
        # attempt to acquire the semaphore
        with semaphore:
            # process
            value = random()
            time.sleep(value)
            # report result
            print(f'thread {number} got {value}')
    
    # create a semaphore
    semaphore = threading.Semaphore()
    for i in range(10):
        worker = threading.Thread(target=task,args=(semaphore, i))
        worker.start()
    # wait for all workers to complete ...


<a id="org3357e88"></a>

# thread event - *threading.Event*

an event is a thread-safe boolean flag.


<a id="orgc7f1f5f"></a>

## how to use event object

an event is a simple pritimitve that allows communitcation between threads.

a **threading.Event** object wraps a boolean variable that can either be &ldquo;set&rdquo; (**True**) or &ldquo;not set&rdquo; (**False**). threads sharing the event instance can check if the event is set and set the event or clear event (make it not set), or wait for the event to be set.

the **threading.Event** provides an easy way to share a boolean variable between threads that can act as a trigger for an action.

> this is one of the simplest mechanism for communitcation between threads: one thread signals an event and other threads wait for it.

&#x2013; [Event objects,threading &#x2013; thread-based parallelism](https://docs.python.org/3/library/threading.html#event-objects)

    ...
    # create an instance of an event
    # ! and the event will be in the "not set" state.
    event = threading.Event()
    
    ...
    
    # check if the event is set
    if event.is_set():
        # do something ...
    # set the event
    event.set()
    # mark the event as not sets
    event.clear()
    
    # wait for the event to be sets
    event.wait()

<div class="org-center">
<p>
NOTE ⚠: waiting threads are only notified when <b>set()</b> function is called, not when <b>clear()</b> function is called
</p>
</div>

a &ldquo;**timeout**&rdquo; argument can be passed to the **wait()** function which will limit how long a thread will return True if the event was set while waiting, otherwise a value **False** returned indicates that the event was not set and called timedout.

    ...
    # wait for the event to be set with a timeout
    event.wait(timeout=10)


<a id="org21a2fca"></a>

## example

    from __init__ import *
    from random import random
    
    def task(event, number):
        # wait for the event to be set
        event.wait()
        # begin processing
        value = random()
        time.sleep(value)
        print(f'thread {number} got {value}')
    
    # create a shared event object
    event = threading.Event()
    # create a suite of threads
    for i in range(5):
        thread = threading.Thread(target=task,args=(event,i))
        thread.start()
    # block for a moment
    print(' main thread blocking ...')
    time.sleep(2)
    # start processing in all threads
    event.set()
    # wait for all threads to finnish ...


<a id="org697496e"></a>

# timer threads - *threading.Timer*

a timer thread will execute a function after a time delay.


<a id="org51fc538"></a>

## how to use a timer thread

the **threading.Timer** is an extension of fhe **threading.Thread** class because of this reason
we can use it just like a normal thread instance.

first, we can create an instance of the timer and configure it.This includes the time to wait before executing in seconds, the function to execute once triggered, adn any arguments to the target function.

    ...
    # create with configuration a timer  thread
    timerT = threading.Timer(10,task,args=(arg1,arg2))
    
    # to start timer func we use
    timerT.start()
    # if we decide cancel the timer before target function has executed,we can use timerthread's cancel() method
    
    timerT.cancel()


<a id="org7071e07"></a>

## example of using a timer thread

    from __init__ import *
    
    def task(message):
        # report the message
        print(message)
    
    # create a thread timer object
    timerT = threading.Timer(3, task, args=('hello world',))
    # start the timer object
    timerT.start()
    # wait for the timer to finish
    print('waiting for the timer ...')


<a id="org69b2f17"></a>

# thread barrier - *threading.Barrier*


<a id="orgfdd0cfa"></a>

## what is barrier

a barrier is a synchranization primitive.

it allows multiple threads to wait on the same barrier object instance (e.g. at the same point in code) until a predefined fixed number of threads arrive (e.g. barrier is full), after which all threads are then notified and released to continue their execution.

internally, a barrier maintains a count of the number of threads waiting on the barrier and a configured maximum number of parties (threads) that are expected. Once the expected number of parties reaches the pre-defined maximum, all waiting threads are notified.


<a id="org0cb927b"></a>

## how to use barrier

a barrier instance must first be created and configured via the constructor specifying the number of parties (threads) that must arrive before the barrier will be lifted.

    ...
    # create a barrier
    Tbarrier = threading.Barrier(10)

we can also perform an action once all threads reach the barrier which can be specified via &ldquo;action&rdquo; arg in the constructor.

this action mus be callable such as a function or a lambda that does not take any arguments and will be executed by one thread once all threads reach the barrier and call the **wait()** function.

    ...
    Tbarrier = threading.Barrier(10,action=my_func)
    # we can use timeout too
    Tbarrier = threading.Barrier(10,action=my_func,timedout=5)
    Tbarrier = threading.Barrier(10,timedout=5)

a thread can reach and wait on the barrier via the **wait()** function.

    ...
    # wait on the barrier for all other threads to arrive
    barrier.wait()

this iss a blocking call and will return once all other threads (the pre-configured number of parties) have reached the barrier.

the wait function does return an integer indicating the number of parties remaining to arrive at the barrier.If a thread was the last thread to arrive, then the return value will be zero.This is helpful if you want the last thread or one thread to perform an action after the barrier is released, and alternative to using the &ldquo;**action**&rdquo; arg in constructor.

    ...
    # wait on the barrier
    remaining = barrier.wait()
    # after released, check if this was the last party
    if remaining == 0:
        print('i was last ..')

a timeout can be set on the call to wait in second via the &ldquo;**timeout**&rdquo; argument.If the timeout expires before all parties reach the  barrier, a **BrokenBarrierError** will be raised
in all threads waiting on the barrier and the barrier will be marked as broken.

if a timeout is used via &ldquo;**timeout**&rdquo; argument  or the default timeout in the constructor, then all calls to the **wait()** function may need to handle the **BrokenBarrierError**.

    ...
    # wait on the barrier for all other threads to arrive
    try:
        barrier.wait()
    except BrokenBarrierError:
        # ...

we can also abort the barrier.aborting the barrier means that all threads waiting on the barrier via the **wait()** function will raise **BrokenBarrierError** and the barrier will be put in the broken state.

to abort the barrier we use **abort()** function

    barrier.abort()

a broken barrier cannot be used.Caalls to **wait()** will raise **BrokenBarrierError**.

a barrier can be fixed and made ready for use again by calling the **reset()** function.

if you cancel a coodination effort although you wish to retry it again with same barrier instance.

    ...
    # reset a broken barrier
    barrier.reset()

the status of the barrier can be checked via attributes.

-   **parties**: reports the canfigured number of parties that must reach the barrier for it to be lifted.
-   **n<sub>waiting</sub>**: reports the current number of threads waiting on the barrier.
-   **broken**: attribute indicates whether the barrier is currently is currently broken or not.


<a id="org43274a9"></a>

## example

in this example we will create a suite of threads, each required to perform some blocking calculation we will use a barrier to coodinate all threads after they have finished their work and perform some action in the main thread. this is a good proxy for the types of coodination we may need to perform with a barrier.

    from __init__ import *
    from random import random
    
    # target function to prepare some work
    def task(barrier, number):
        # generate a unique value
        value = random() * 10
        # block for a moment
        time.sleep(value)
        # report result
        print(f'thread {number} done, got: {value}')
        barrier.wait()
    # create a barrier
    Tbarrier = threading.Barrier(5+1)
    # create the worker threads
    for i in range(5):
        # start a new thread to perform some work
        worker = threading.Thread(target=task,args=(Tbarrier,i))
        worker.start()
    # wait for all thread to finish
    print('main thread waiting on all results ...')
    Tbarrier.wait()
    # report once all threads are done
    print('all threads have their result')


<a id="orgae218ad"></a>

# pyhton : threading best practices


<a id="org065dcee"></a>

## tip 1: use context managers

acquire and release locks using a context manager, wherever possible.


<a id="org0c4e4c9"></a>

### not use this

    ...
    
    # acquire the lock manually
    lock.acquire()
    # critical section...
    # release the lock
    lock.release()


<a id="orgc7d13b8"></a>

### use this for better control over threads (more safe)

    ...
    # acquire the lock
    lock.acquire()
    try:
        # critical section ...
    finally:
        # always release the lock
        lock.release()

same but less code

    ...
    # acquire the lock
    with lock:
        # critical section ...


<a id="org1978ada"></a>

### the real benefit

the benefit of the context manager is that the lock is always released as soon as the block exited,regardless of how it is exited, e.g normally, a return, an error, or an exception.

this applies to a number of concurency primitives,such as:

-   acquiring ;
    -   mutex lock via **threading.Lock** class
    -   reentrant mutex lock via **threading.RLock** class
    -   semaphore via **threading.Semaphore** class
    -   condition via **threading.Condition** class


<a id="org4e53ccc"></a>

## tip 2 : Use timedouts when waiting

always use a timedout when waiting on a blocking call.

many calls made on concurency primitives may block.

examples:

-   waiting to acquire a **threading.Lock()** via **acquire()**.
-   waiting for a thread to terminate via **join()**.
-   waiting to be notified on a **threading.Condition** via **wait()**.
-   and more.

All blocking calls on concurrency primitives take a &ldquo;**timeout**&rdquo; argument and return **True** if the call was successful or **False** otherwise.

Do not call a blocking call without a timedout,wherever possible.

    ...
    # acquire the lock
    if not lock.acquire(timedout=2*60):
        # handle failure case ...

this allow the waiting thread to give-up waiting after a fixed time limit and then attempt to rectify the situation, e.g. report and error, force termination, etc.


<a id="org3a493df"></a>

## tip 3: use a mutex to protect critical sections

always use a mutual exclusion (mutex) lock to protect critical sections in code.

Critical sections are sensitive parts of code that can be executed by multiple threads concurency and may result in race conditions.

a critical section maay refer to a single block code, but it also refers to multiple accesses oto the same data variable or a resource from multiple functions.

a mutex lock can be used to ensure that only one thread at a time executes a critical section of code at time, while all other threads trying to execute the same code must wait until the currently executing thread is finished with the critical section and releases the lock.

each thread must attempt to acquire the lock at the beginning of the critical section.if the lock has not been obtained,then thread will acquire it and other threads must wait until the thread that acquired the lock releases it.

    ...
    # acquire the lock
    with lock:
        # critical section ...


<a id="org8f36c11"></a>

## tip 4: acquire locks in order

acquire locks in the same order throught the application, wherever possible.

this is called &ldquo;lock ordering&rdquo;.

in some applications you may be able to abstract the acquisition of lock using a list of **threading.Lock** object that may be itered  and acquired in order, or a function call that acquired locks in sonsistent order.

when this is not possible, you may need to audit your code to confirm that all paths throught the code acquire the locks in same order.


<a id="org56057a3"></a>

# resources - read more about

-   <https://superfastpython.com/threading-in-python/#Python_Threads>
-   <https://superfastpython.com/>

