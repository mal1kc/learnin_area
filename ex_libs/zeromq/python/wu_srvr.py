#!./.venv/bin/python
#
#   Weather update server
#   Binds PUB socket to tcp://*:5556
#   Publishes random weather updates
#

import zmq
from random import randrange


context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:5556")


try: # to not give us error when closing
    while True:
        zipcode = randrange(1, 100000)
        temperature = randrange(-20, 50)
        relhumidity = randrange(10, 60)

        socket.send_string(f"{zipcode} {temperature} {relhumidity}")
except KeyboardInterrupt:
    print("KeyboardInterrupt catched exiting ...")
