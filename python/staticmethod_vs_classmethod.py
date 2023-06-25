#!/usr/bin/env python

class A:
    def __init__(self, *args):
        self.args = args
    
    def do_something(self, x = None):
        if x is None:
            print(f"Doing something with {self.args} in {self.__class__.__name__}")
        else:
            print(f"Doing something with {x} in {self.__class__.__name__}")

    @classmethod
    def create_do_something(cls, x):
        print(f"Creating an instance of {cls.__name__} and doing something with {x}")
        instance = cls()
        ...  # Do something with instance
        return instance # return changed instance

    @classmethod
    def from_string(cls, string):
        return cls(*string.split('-'))

    @staticmethod
    def static_do_something(x): # like a normal function but inside a class
        print(f"Doing something static with {x}")


class B(A):
    ...


def main():
    a0 = A()
    a0.do_something('Aa')
    a0.static_do_something('Aa')
    a0.create_do_something('Aa')

    a1 = A.create_do_something('Aa')
    a1.do_something('Aa')

    a2 = A.from_string('Aa-Bb-Cc')
    a2.do_something()

    b0 = B()
    b0.do_something('Bb')
    b0.static_do_something('Bb')
    b0.create_do_something('Bb')

    b1 = B.create_do_something('Bb')
    b1.do_something('Bb')

    b2 = B.from_string('Dd-Ee-Ff')
    b2.do_something()

if __name__=="__main__":
    main()