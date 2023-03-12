
# Table of Contents

1.  [what is **sockets** why we use them](#org17463ed)
2.  [what it is **socket** module](#org3728e4a)
    1.  [the primary socket API functions and methods in this modeule are:](#org382f90b)
3.  [tcp sockets](#org3642373)
4.  [some example echo server,client](#org67769f3)
    1.  [src of echo server](#org9364038)
    2.  [src of echo client](#org810bd97)
5.  [handling multiple connections](#org4f72ee3)
    1.  [code with explanation of multiconnection server](#org90e19f6)
    2.  [code with explanation of multiconnection client](#orgcab70cb)
    3.  [src of multiconnection server](#org643b2a8)
    4.  [src of multiconnection client](#org3d799f4)
6.  [application client and server  (more advanced example of mutliconn):](#orgda9d42f)
    1.  [application protocol header](#org00622b5)
    2.  [sending an  app message](#orgbb7c25c)
    3.  [application message class](#org3c19a01)
        1.  [message entry point](#org565980e)
7.  [publish - subscribe example](#org237b0ce)
    1.  [src of publish - subscribe example](#org2536e39)
8.  [this document heavily used this sources](#orgb3cb8f4)



<a id="org17463ed"></a>

# what is **sockets** why we use them

sockets and the socket Api are  used to send messages over a network.They provide form of interprocess communication (IPC).The network can be logical, local network to computer, or one that&rsquo;s physically connected to an externel network.The most obvius example is Internet.

first their use was ARPANET in 1971 and then become api in Berkeley Software Distrubution (BSD) operating system in 1983 called Berkeley Sockets

[read more about berkeley sockets (commonly implemented socket API)](https://en.wikipedia.org/wiki/Berkeley_sockets?oldformat=true)


<a id="org3728e4a"></a>

# what it is **socket** module

> This module provides access to the BSD socket interface. It is available on all modern Unix systems, Windows, MacOS, and probably additional platforms.

&#x2013; [python org module](https://docs.python.org/3/library/socket.html)


<a id="org382f90b"></a>

## the primary socket API functions and methods in this modeule are:

-   socket <span class="underline">class</span>
    -   .bind()
    -   .listen()
    -   .accept()
    -   .connect()
    -   .connect<sub>ex</sub>()
    -   .send()
    -   .recv()
    -   .close()

python provides good API that maps directly to syscalls,
their `C` counterparts.

as part of its `std` library, python has classes that make using these lower level socket operations easier.


<a id="org3642373"></a>

# tcp sockets

when we create socket object using **socket.socket()**,specifiyn socket type as socket.SOCK<sub>STREAM.When</sub> we do that, the default protocol that&rsquo;s used is the [Transmission Control Protocol a.k.a. TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) . this is default and this is probably what we want.

if we want a lookout there was a [socket diagram (basically tells how tcp works)](https://commons.wikimedia.org/wiki/File:InternetSocketBasicDiagram_zhtw.png)


<a id="org67769f3"></a>

# some example echo server,client


<a id="org9364038"></a>

## src of echo server

    #!/usr/bin/env python3
    import socket
    
    HOST = "127.0.0.1"  # localhost or "127.0.0.1" (standart loopback interface address)
    PORT = 5634  # port to listen on (non-privileged ports are > 1023)
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            print(f"connected by {addr} conn {conn=}")
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                conn.sendall(data)

1.  explanation of server

    -   we create socket object with  [context manager type](https://docs.python.org/3/reference/datamodel.html#context-managers) ,by doing that after a with indent code finishes it automaticly calls `s.close()`
    -   the args of socket obects are
        -   **AF<sub>INET</sub>** : IPV4
        -   **SOCK<sub>STREAM</sub>** : TCP
    -   `s.bind()` is binds our socket to given HOST and PORT
    -   `s.listen()` Enable a server to accept connections. If backlog is specified, it must be at least 0 (if it is lower, it is set to 0); it specifies the number of unaccepted connections that the system will allow before refusing new connections. If not specified, a default reasonable value is chosen.
    -   `s.accept()` blocks execution and waits for incoming connection.when client connects it returns a new socket object represnting connection and a tuple about client address ( ipv4 (host, port) , ipv6 (host, port, flowinfo, scopeid) [(more info socket addr families](https://docs.python.org/3/library/socket.html#socket-families) ) .
    -   after `.accept()` provide connection socket object,an while loop is used to loop over blocking calls to `conn.recv()`.This reads whatever data the client sends and echoest it back using conn.sendall().
    -   if conn.recv() returns emtpy **bytes** object,b&rsquo;&rsquo;,that signals client closed the connection and the loop is terminated


<a id="org810bd97"></a>

## src of echo client

    #!/usr/bin/env python3
    import socket
    HOST = "127.0.0.1"  # the server's hostname or IP address
    PORT = 5634  # the port used by the server
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b"hello, universe.\nHi, friend.")
        data = s.recv(1024)
    
    print(f"received some data:\n{data=}")
    print(f"rendered data :\n---\n{data.decode()}\n---")


<a id="org4f72ee3"></a>

# handling multiple connections

the echo server has its limitations.one of big ones is that is serves onlt one client then exists.the echo client has some limitations too,but there is a extra problem.when client uses `s.recv()`, **it&rsquo;s possible that it will return only one byte,b&rsquo;h&rsquo; from b&rsquo;hello, universe&rsquo;**

the bufsize arg of 1024 used above is the maximum amount of data to be received at once.it doesn&rsquo;t mean that `.recv()` will return 1024 bytes.

the `.send()` method also behaves this way.it returns the number of bytes sent, which may be less than the size of data passed in.we are responsible for checkin this and calling `.send()` as many times as needed to send all of the data.

> Returns the number of bytes sent. Applications are responsible for checking that all data has been sent; if only some of the data was transmitted, the application needs to attempt delivery of the remaining data. For further information on this topic, consult the [Socket Programming HOWTO](https://docs.python.org/3/howto/sockets.html#socket-howto).

&#x2013; [python.org source](https://docs.python.org/3/library/socket.html#socket.socket.send)

in the example `echo client` we avoided havinf to do this by using `.sendall()`

> Unlike `send()`, this method continues to send data from bytes until either all data has been sent or an error occurs. None is returned on success. On error, an exception is raised, and there is no way to determine how much data, if any, was successfully sent.

&#x2013; [python.org source](https://docs.python.org/3/library/socket.html#socket.socket.sendall)

-   we have two problems at this point
    -   how do we handle multiple connections
    
    -   we need to call `.send()` and `.recv()` until all data is sent or received.

there are many approaches to [concurrency](https://realpython.com/python-concurrency/),there was std library module `asyncio` (after python 3.4),there was std library module `threads`.

the trouble with concurrency there are many substleties to consider and guard against.but simpicitily for examples of `socket` module we are going to use somethin trational.we&rsquo;re going to use [.select()](https://docs.python.org/3/library/selectors.html#selectors.BaseSelector.select).

the `.select()` method allows we to check for I/O completion on more than one socket.so new can call `.select()` to see which socket have I/O ready for reading and/or writing.but in python there&rsquo;s more we use [selectors module](https://docs.python.org/3/library/selectors.html) in standar library so that the most efficent implementation is used, regardless of OS (operating system).

> This module (`selectors module`) allows high-level and efficient I/O multiplexing, built upon the select module primitives. Users are encouraged to use this module instead, unless they want precise control over the OS-level primitives used.

&#x2013; [High-level I/O multiplexing - source](https://docs.python.org/3/library/selectors.html)

still,by using `.select()`, we&rsquo;re not exactly to run concurrenctly.it still depends our workload,what our application needs,how many clients ,how many data transfer happens etc.


<a id="org90e19f6"></a>

## code with explanation of multiconnection server

    #!/usr/bin/env python3
    import sys
    import socket
    import selectors
    import types
    
    sel = selectors.DefaultSelector()
    
    ...
    
    if len(sys.argv) < 2:
        raise Exception(
            f'you are not give me correct args\n args must be host and port example:\n python {__file__.split("/")[-1]} HOST PORT\n ./{__file__.split("/")[-1]} HOST PORT\n ./{__file__.split("/")[-1]} 127.0.0.1 5634'
        )
    
    
    host, port = sys.argv[1], int(sys.argv[2])
    
    lsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    lsock.bind((host, port))
    lsock.listen()
    print(f"listenin on host: {host} port: {port} ")
    lsock.setblocking(False)
    sel.register(lsock, selectors.EVENT_READ, data=None)

-   the biggest diffrence between `echo server` and this server is the call to `lsock.setblocking(False)` to configure socket in **non-blocking** mode. calls made to this socket will no longer block.when it&rsquo;s used with `sel.select()`,we can wait for events on one or more sockets then read and write data when it&rsquo;s ready.

-   sel.register() registers the socket to be monitored with `sel.select()` for the events we&rsquo;re interested in (in this example EVENT<sub>READ</sub>).

-   to store arbitarty data we&rsquo;d like along with socket,we&rsquo;ll use `data`.it&rsquo;s returned when `.select()` returns.we&rsquo;ll use data to keep track of what&rsquo;s been sent and received on the socket.

    try:
        while True:
            events = sel.select(timeout=None)
            for key, mask in events:
                if key.data is None:
                    accept_wrapper(key.fileObj)
                else:
                    service_connection(key,mask)
    except KeyboardInterrupt:
        print('caught keyboard interrupt, exiting ...')
    finally:
        sel.close()

-   `sel.select(timeout=None)` blocks until there are sockets ready for I/O. it **returns a list of tuples, one for each socket**.Each tuple **contains a key and a mask**.The key is a [SelectorKey -> namedtuple](https://docs.python.org/3/library/selectors.html#selectors.SelectorKey) that contains a `fileobj` attribute key. **fileobj is socket object**, and mask is an event [mask](https://en.wikipedia.org/wiki/Mask_(computing)) of the operations that are ready.

-   if key.data is None,then we know it&rsquo;s from the listening socket and we need to accept the connection.we&rsquo;ll call our own `accpet_wrapper()` function to get the new socket object and register it with the selector.we&rsquo;ll look at that in a moment.

-   if key.data is not None,then we know it&rsquo;s a client socket that&rsquo;s already been accepted, and we neet to servcice it . `service_connection()` is then called with key and mask as arguments, and that&rsquo;s everything we need to operate on the socket.

    def accept_wrapper(sock):
        conn, addr = sock.accept()  # should be ready to read
        print(f"accepted connection from {addr}")
        conn.setblocking(False)
        data = types.SimpleNamespace(addr=addr, inb=b"", outb=b"")
        events = selectors.EVENT_READ | selectors.EVENT_WRITE
        sel.register(conn, events, data=data)

-   because the listening socket registed for the event selectors. `EVENT_READ`, it should be ready to read. we call `sock.accept()` and then call `conn.setblocking(False)` to put the socket in non-blocking mode.

-   **remember** , this is the main objective in this version of the server because we don&rsquo;t want it to block.if it blocks, then the entire server is stalled until it returns.that means other sockects are left waiting event though the server isn&rsquo;t actively working. **this is the dreaded &ldquo;hanging&rdquo; state that we don&rsquo;t want our server to be in.**

-   next, we create an object to hold the data that we want included along with the socket using a [SimpleNamespace](https://docs.python.org/3/library/types.html#types.SimpleNamespace) , because we want to know when the client connection is ready for reading and writing,both of those events the client connections ready for reading and writing, both of those events are set with **bitwise OR** operators

    
    
    def service_connection(key, mask):
        sock = key.fileobj
        data = key.data
        if mask & selectors.EVENT_READ:
            recv_data = sock.recv(1024)  # should be ready to read
            if recv_data:
                data.outb += recv_data
            else:
                print(f"closing connection to {data.addr}")
                sel.unregister(sock)
                sock.close()
        if mask & selectors.EVENT_WRITE:
            if data.outb:
                print(f"echoing {data.outb!r} to {data.addr}")
                sent = sock.send(data.outb)  # should be ready to write
                data.outb = data.outb[sent:]

<span class="underline">this is heart of simple multi-connection server.</span>

-   if  the socket is ready for reading,then `mask & selectors.EVENT_READ` will evaluate to True, so `sock.recv()` is called.Any data that&rsquo;s read is appended to `data.outb` so that can be sent later.

-   if no data is received, this means that the client has closed their socket,so the server should too. but **don’t forget** to call `sel.unregister()` before closing, so it’s no longer monitored by `.select()`.

-   when the socket is ready for wiriting, which should always be the case for a healthy socket, any received data stored in `data.outb` is echoed to the client using `socket.send()`. the bytes sent are then removed from send buffer.

-   the `.send()` method returns the number of bytes sent. this number can then be used with [slice notation](https://docs.python.org/3/reference/expressions.html#slicings)


<a id="orgcab70cb"></a>

## code with explanation of multiconnection client

    
    import sys
    import socket
    import selectors
    import types
    
    sel = selectors.DefaultSelector()
    messages = [b"hello message 1 from client.", b"hi message 2 from client."]
    
    def start_connections(host, port, num_conns):
        server_addr = (host, port)
        for i in range(0, num_conns):
            connid = i + 1
            print(f"starting connection {connid} to {server_addr}")
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.setblocking(False)
            sock.connect_ex(server_addr)
            events = selectors.EVENT_READ | selectors.EVENT_WRITE
            data = types.SimpleNamespace(
                connid=connid,
                msg_total=sum(len(m) for m in messages),
                recv_total=0,
                messages=messages.copy(),
                outb=b"",
            )
            sel.register(sock, events, data=data)

-   `num_conns` is  read from the command-line and is the number of connections to create to the server.just like server, each socket is set to non-blocking mode.

-   we use [.connect<sub>ex</sub>()](https://docs.python.org/3/library/socket.html#socket.socket.connect_ex) instead of `.connect()` because `.connect()` would immediately raise a BlockingIOError exception.The `.connect_ex()`  method innitially returns an *error indicator, errno.EINPROGRESS* , instead of raising an exception that would interfere with the connection in progress. Once the connection is completed, the socket is ready for reading and writing and is returned by `.select()`.

-   after the socket is set up, the data we want to store with the socket is created using `SimpleNamespace`. the messages that client will send to server are copied using `.copy()` because each connection will call `socket.send()` and modify the list.everything needed to keep track of what the client needs to send, has sent, and has received, including total number of bytes in the messages, is stored in object data.
    
    `service_connection() for the client`
    
        
        def service_connection(key, mask):
            sock = key.fileobj
            data = key.data
            if mask & selectors.EVENT_READ:
                recv_data = sock.recv(1024)  # should be ready to read
                if recv_data:
                    print(f"received {recv_data!r} from connection {data.connid}")
                    data.recv_total += len(recv_data)
                if not recv_data or data.recv_total == data.msg_total:
                    print(f"closing connection {data.connid}")
                    sel.unregister(sock)
                    sock.close()
            if mask & selectors.EVENT_WRITE:
                if not data.outb and data.messages:
                    data.outb = data.messages.pop(0)
                if data.outb:
                    print(f"sending {data.outb!r} to connection {data.connid}")
                    sent = sock.send(data.outb)  # should be ready to write
                    data.outb = data.outb[sent:]


<a id="org643b2a8"></a>

## src of multiconnection server

    #!/usr/bin/env python3
    
    import sys
    import socket
    import selectors
    import types
    
    
    sel = selectors.DefaultSelector()
    
    
    def accept_wrapper(sock):
        conn, addr = sock.accept()  # should be ready to read
        print(f"accepted connection from {addr}")
        conn.setblocking(False)
        data = types.SimpleNamespace(addr=addr, inb=b"", outb=b"")
        events = selectors.EVENT_READ | selectors.EVENT_WRITE
        sel.register(conn, events, data=data)
    
    
    def service_connection(key, mask):
        sock = key.fileobj
        data = key.data
        if mask & selectors.EVENT_READ:
            recv_data = sock.recv(1024)  # Should be ready to read
            if recv_data:
                data.outb += recv_data
            else:
                print(f"closing connection to {data.addr}")
                sel.unregister(sock)
                sock.close()
        if mask & selectors.EVENT_WRITE:
            if data.outb:
                print(f"echoing {data.outb!r} to {data.addr}")
                sent = sock.send(data.outb)  # Should be ready to write
                data.outb = data.outb[sent:]
    
    
    def main():
    
        if len(sys.argv) < 2:
            raise Exception(
                f'you are not give me correct args\n args must be <host> and <port> example:\n python {__file__.split("/")[-1]} <HOST> <PORT>\n ./{__file__.split("/")[-1]} <HOST> <PORT>\n ./{__file__.split("/")[-1]} 127.0.0.1 5634'
            )
    
        host, port = sys.argv[1], int(sys.argv[2])
    
        lsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        lsock.bind((host, port))
        lsock.listen()
        print(f"listenin on host: {host} port: {port} ")
        lsock.setblocking(False)
        sel.register(lsock, selectors.EVENT_READ, data=None)
    
        try:
            while True:
                events = sel.select(timeout=None)
                for key, mask in events:
                    if key.data is None:
                        accept_wrapper(key.fileobj)
                    else:
                        service_connection(key, mask)
        except KeyboardInterrupt:
            print("Caught keyboard interrupt, exiting")
        finally:
            sel.close()
    
    
    if __name__ == "__main__":
        main()


<a id="org3d799f4"></a>

## src of multiconnection client

    #!/usr/bin/env python3
    
    import sys
    import socket
    import selectors
    import types
    
    sel = selectors.DefaultSelector()
    messages = [b"hello message 1 from client.", b"hi message 2 from client."]
    
    def start_connections(host, port, num_conns):
        server_addr = (host, port)
        for i in range(0, num_conns):
            connid = i + 1
            print(f"starting connection {connid} to {server_addr}")
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.setblocking(False)
            sock.connect_ex(server_addr)
            events = selectors.EVENT_READ | selectors.EVENT_WRITE
            data = types.SimpleNamespace(
                connid=connid,
                msg_total=sum(len(m) for m in messages),
                recv_total=0,
                messages=messages.copy(),
                outb=b"",
            )
            sel.register(sock, events, data=data)
    
    
    def service_connection(key, mask):
        sock = key.fileobj
        data = key.data
        if mask & selectors.EVENT_READ:
            recv_data = sock.recv(1024)  # should be ready to read
            if recv_data:
                print(f"received {recv_data!r} from connection {data.connid}")
                data.recv_total += len(recv_data)
            if not recv_data or data.recv_total == data.msg_total:
                print(f"closing connection {data.connid}")
                sel.unregister(sock)
                sock.close()
        if mask & selectors.EVENT_WRITE:
            if not data.outb and data.messages:
                data.outb = data.messages.pop(0)
            if data.outb:
                print(f"sending {data.outb!r} to connection {data.connid}")
                sent = sock.send(data.outb)  # should be ready to write
                data.outb = data.outb[sent:]
    
    
    if len(sys.argv) != 4:
        print(f"usage: {sys.argv[0]} <host> <port> <num_connections> in example:\n {sys.argv[0]} 127.0.0.1 5634 2")
        sys.exit(1)
    
    def main():
        host, port, num_conns = sys.argv[1:4]
        start_connections(host, int(port), int(num_conns))
    
        try:
            while True:
                events = sel.select(timeout=1)
                if events:
                    for key, mask in events:
                        service_connection(key, mask)
                # check for a socket being monitored to continue.
                if not sel.get_map():
                    break
        except KeyboardInterrupt:
            print("caught keyboard interrupt, exiting ...")
        finally:
            sel.close()
    
    if __name__ == '__main__':
        main()


<a id="orgda9d42f"></a>

# application client and server  (more advanced example of mutliconn):

we want a client and servert that handle errors appropriately so that other connections aren&rsquo;t effected.

> All errors raise exceptions. The normal exceptions for invalid argument types and out-of-memory conditions can be raised. Errors related to socket or address semantics raise [OSError](https://docs.python.org/3/library/exceptions.html#OSError) or one of its subclasses.

&#x2013; [source](https://docs.python.org/3/library/socket.html)

so, one thing we need to catch `OSError`.Another important consideration in relation to erros is **timeout**.
**timeouts** are couse a lot of trouble; hosts and routers are rebooted, switch ports go bad, cables go bad, cables get unplugged.best way to handle them is prevent them.

when we use TCP we read data from continues stream from network. however, unlike reading a file, there&rsquo;s no [f.seek()](https://docs.python.org/3/tutorial/inputoutput.html#methods-of-file-objects).

once we&rsquo;ve read them,they need to be saved somewhere, or else we will have dropped them. calling `.recv()` again reads the next stream of bytes avaliable from socket.

we&rsquo;ll be reading from the socket in chunks. so, we need to call `.recv()` and save the data in a buffer until we&rsquo;ve read enough bytes to have a complete message that makes sens to our application.

in other words,we need to keep up with how many bytes read, and figure out where the messages boundaries are.

one of solution of this is send always fixed size data.but it&rsquo;s insufficent for most ways.

we&rsquo;ll learn a generic approach, one that&rsquo;s used by many protocols,including HTTP.we&rsquo;ll prefix messages with a **header** that includes content lenght as well as any other fields we need.by doing this,we&rsquo;ll only need to keep up with the header.Once we’ve read the header, we can process it to determine the length of the message’s content. With the content length, we can then read that number of bytes to consume it.

we&rsquo;ll implement this by creating a custom class that can send and receive messages that contain text or binary data.

before we get started,we need to learn something.in erlier examples we&rsquo;re sending and receiving raw bytes.if we receive data and want to use it in a contex where it&rsquo;s inrerpreted as multiple bytes, for example a 4-byte interger,we&rsquo;ll need to take int o account that it could be in a format that&rsquo;s not native to our machine&rsquo;s CPU.The client or server on the other end could have a CPU that uses a diffrent byte order than our own.if this is the case, then we&rsquo;ll need to convert it to our host&rsquo;s native byte order before using it. this byte order referred to as a CPU&rsquo;s [endiannes](https://en.wikipedia.org/wiki/Endianness).

we&rsquo;ll avoid this issue by takin advantage of Unicode for our message header and using the encoding UTF-8.since UTF-8 uses an 8-bit encoding, there are no byte ordering issues.

by the way we can easily deterine the byte code of our machine by usin `sys.byteorder`

    python -c 'import sys; print(repr(sys.byteorder))'


<a id="org00622b5"></a>

## application protocol header

the app protocol header is:

-   variable-length text
-   unicode with encoding UTF-8
-   a python dict serialize by using [JSON](https://docs.python.org/3/library/json.html)

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">name</td>
<td class="org-left">desc</td>
</tr>


<tr>
<td class="org-left">byteorder</td>
<td class="org-left">the byte order of the machine (uses sys.byteorder).this may not required by every application.</td>
</tr>


<tr>
<td class="org-left">content-lenght</td>
<td class="org-left">the lenght of content in bytes.</td>
</tr>


<tr>
<td class="org-left">content-type</td>
<td class="org-left">type of content in payload (text/json,binary/binary-type)</td>
</tr>


<tr>
<td class="org-left">content-encoding</td>
<td class="org-left">the encoding used by the content (utf-8,binary)</td>
</tr>
</tbody>
</table>


<a id="orgbb7c25c"></a>

## sending an  app message

we have still some problem. we have a variable-lenght header,nice and flexible,but how do we know the lenght of the header when reading it with `.recv()`?

when we previously learned about using `.recv()` and message boundaries, we also learned that fixed lenght can be insefficient. that&rsquo;s true,but we&rsquo;re goint to use a small,2-byte,fixed-lenght header to prefix the JSON header that contains its lenght.


<a id="org3c19a01"></a>

## application message class

to keep things simple but still demonstrate how things work in real worl applications, this example uses an application protocol that implements a basic search feature. the client sens aa search request and the server does a lookup for a match if the request sent by the client isn&rsquo;t recognized as a search, the server assumes it&rsquo;s a binary request and returns a binary response.

general work steps like this:

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-right" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-right">step</td>
<td class="org-left">endpoint</td>
<td class="org-left">action / message content</td>
</tr>


<tr>
<td class="org-right">1</td>
<td class="org-left">client</td>
<td class="org-left">sends a message containing request content</td>
</tr>


<tr>
<td class="org-right">2</td>
<td class="org-left">server</td>
<td class="org-left">receives and processes client request message</td>
</tr>


<tr>
<td class="org-right">3</td>
<td class="org-left">server</td>
<td class="org-left">sends a message containing response content</td>
</tr>


<tr>
<td class="org-right">4</td>
<td class="org-left">client</td>
<td class="org-left">receives and processes server response message</td>
</tr>
</tbody>
</table>

file layout

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">app</td>
<td class="org-left">file</td>
<td class="org-left">code</td>
</tr>


<tr>
<td class="org-left">server</td>
<td class="org-left">app-srvr.py</td>
<td class="org-left">the servers&rsquo;s main coode</td>
</tr>


<tr>
<td class="org-left">server</td>
<td class="org-left">libsrvr.py</td>
<td class="org-left">the servers&rsquo;s message class</td>
</tr>


<tr>
<td class="org-left">client</td>
<td class="org-left">app-clnt.py</td>
<td class="org-left">the client&rsquo;s main code</td>
</tr>


<tr>
<td class="org-left">client</td>
<td class="org-left">libclnt.py</td>
<td class="org-left">the client&rsquo;s message class</td>
</tr>
</tbody>
</table>


<a id="org565980e"></a>

### message entry point

unders


<a id="org237b0ce"></a>

# publish - subscribe example


<a id="org2536e39"></a>

## src of publish - subscribe example

    #!/usr/bin/env python3
    
    def main():
        pass
    
    if __name__ == '__main__':
        main()


<a id="orgb3cb8f4"></a>

# this document heavily used this sources

-   [realpython.com - python sockets](https://realpython.com/python-sockets/)
-   [doc.python.org - socket](https://docs.python.org/3/library/socket.html)

