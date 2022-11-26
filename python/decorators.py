"""
example decorator and usage
"""
import time
from functools import lru_cache


def decorator_function0(original_function):
    def wrapper_function0(*args, **kwargs):
        print("wrapper executed this before {}".format(original_function.__name__))
        result = original_function(*args, **kwargs)
        print("wrapper executed this after {}".format(original_function.__name__))
        return result

    return wrapper_function0


@decorator_function0
def welcome_User(name):
    print("hello {}".format(name))


# ++ extra example


def prefix_decorator(prefix):
    def decorator_function1(original_function):
        def wrapper_function1(*args, **kwargs):
            print(
                "{} wrapper executed this before {}".format(
                    prefix, original_function.__name__
                )
            )
            result = original_function(*args, **kwargs)
            print(
                "{} wrapper executed this after {}".format(
                    prefix, original_function.__name__
                )
            )
            return result

        return wrapper_function1

    return decorator_function1


@prefix_decorator("log_")
def welcome_Customer(name):
    print("hello {}".format(name))


# ++ extra example


def time_decorator(org_func, *args_, **kwargs_):
    def wrapper_func(*args, **kwargs):
        print(args, kwargs, args_, kwargs_)
        if len(args) == 0:
            args = args_
        if len(kwargs) == 0:
            kwargs = kwargs_
        start = time.perf_counter()
        result = org_func(*args, **kwargs)
        end = time.perf_counter()
        print(f"Timer: {org_func.__name__}{args} took {end - start} s")
        return result

    return wrapper_func


@lru_cache(maxsize=5)  # this caches previosly returned values
@time_decorator
def fib(x):
    if x <= 1:
        return 1
    return fib(x - 1) + fib(x - 2)


if __name__ == "__main__":
    time_decorator(welcome_User, "m")()
    print(f"{fib(40) = }")
    # welcome_User("malik")
    # welcome_User("malenia")
    # welcome_Customer("malik")
    # welcome_Customer("malenia")
