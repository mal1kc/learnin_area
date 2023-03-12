#!/usr/bin/env python3


class A:
    a = 1
    b = "hello"

    def f(self):
        return 42


def make_A():
    # how class made
    name = "A"
    bases = ()

    a = 1
    b = "hi"

    def f(self):
        return 42

    namespace = {"a": a, "b": b, "f": f}
    A = type(name, bases, namespace)
    return A


def make_A_more_accurate():
    name = "A"
    bases = ()

    namespace = type.__prepare__(name, bases)

    body = """
    a = 1
    b = "hi"

    def f(self):
        return 42
    """

    exec(body, globals(), namespace)
    A = type(name, bases, namespace)

    return A


# metaclasses is point of customization in class creation progress


class MyMetaClass(type):
    """
    metaclass is class that inherits from type
    """

    pass


class A:
    pass


class B(metaclass=MyMetaClass):
    pass


def example_metaclass1():
    a = A()
    b = B()
    print(f"{type(a)=}")
    print(f"{type(A)=}")
    print(f"{type(b)=}")
    print(f"{type(B)=}")


def main():
    x = int()
    print(f"{x=}")

    A = make_A()
    print(A)
    A = make_A_more_accurate()
    print(A)
    example_metaclass1()


if __name__ == "__main__":
    main()
