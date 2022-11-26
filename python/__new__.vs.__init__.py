"""
# diffrences between __new__ and __init__ methods in classes

where i learn : https://www.youtube.com/watch?v=-zsV0_QrfTw
base src : https://github.com/mCodingLLC/VideosSampleCode/blob/master/videos/076_new_vs_init_in_python/new_vs_init.py
"""


class A:
    def __new__(cls, *args, **kwargs):
        # this makes object
        # this needs to return something -> instance of class
        print(f"new {cls,args,kwargs}")
        return super().__new__(cls)

    def __init__(self, *args, **kwargs) -> None:
        # this initialize object
        # if object __new__ method returns wrong type
        # of instance this method not called
        print(f"init {self,args,kwargs}")


def how_object_construction_works():
    x = A(1, 2, 3, x=4)

    x = A.__new__(A, *args, **kwargs)
    if isinstance(x, A):
        type(x).__init__(x, *args, **kwargs)


class LowercaseTuple(tuple):
    """
    example usage of __new__ method
    """

    def __new__(cls, iterable):
        upper_iterable = (s.lower() for s in iterable)
        return super().__new__(cls, upper_iterable)

    # this __init__ not work because tupples does not support item assigment
    # even in init
    #
    # Tldr error: tuples are immutable,even in init
    #   def __init__(self, iterable) -> None:
    #        print(f"init {iterable}")
    #        for i, arg in enumerate(iterable):
    #        self[i] = arg.lower()


def example_inheriting_immutable_uppercase_tuple():
    print("lowecase tuple")
    print(LowercaseTuple(["HI", "THERE"]))


class Singleton:
    # eg global config object,btw this is not a good pattern to have
    # be cause it works like every variable is global variable
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__new__(cls, *args, **kwargs)
        return cls._instance


def example_singleton():
    print("singleton example")
    x = Singleton()
    y = Singleton()
    print(f"{x is y = },{x , y = }")


class Client:
    _loaded = {}
    _db_file = "file.db"

    def __new__(cls, client_id):
        if (client := cls._loaded.get(client_id)) is not None:
            print(f"returning existing client {client_id} from cache")
            return client

        client = super().__new__(cls)
        cls._loaded[client_id] = client
        client._init_from_file(client_id, cls._db_file)
        return client

    def _init_from_file(self, client_id, file):
        # lookup client in file and read properties
        print(f"reading client {client_id} data from file, db, etc.")
        name = ...
        email = ...
        self.name = name
        self.email = email
        self.id = client_id


def cached_clients_example():
    print("CLIENT CACHE EXAMPLE")
    x = Client(0)
    y = Client(0)
    print(f"{x is y=}")
    z = Client(1)


def main():
    # x = A(1, 2, 3, x=5)
    # example_inheriting_immutable_uppercase_tuple()
    example_singleton()
    cached_clients_example()


if __name__ == "__main__":
    main()
