#!/usr/bin/env python3
"""
monad is software design pattern in functional programming
more info about monad : https://www.wikiwand.com/en/Monad_(functional_programming)
this example shows how can we use monads in python.
"""

from time import perf_counter_ns, sleep
from dataclasses import dataclass


def time_it(f):
    def wrapper(*args, **kwargs):
        start = perf_counter_ns()
        result = f(*args, **kwargs)
        end = perf_counter_ns()
        return result, end - start

    return wrapper


def example():
    # Define the decorator for timing functions
    def time_it(f):
        def wrapper(*args, **kwargs):
            start = perf_counter_ns()
            result = f(*args, **kwargs)
            end = perf_counter_ns()
            return result, end - start

        return wrapper

    # Decorate functions with the timing decorator
    @time_it
    def fast_f(x):
        sleep(0.01)
        return x + 1

    @time_it
    def slow_f(x):
        sleep(0.1)
        return x + 1

    @time_it
    def slow_f2(x):
        sleep(0.1)
        return x + 2

    # Call decorated functions and calculate total time
    y0, time0 = fast_f(99)
    y1, time1 = slow_f(y0)
    y2, time2 = slow_f2(y1)
    total_time = time0 + time1 + time2

    # Print results without monad
    print("result without monad")
    print(f"{y2 = },{total_time = }")

    # Define a function to bind functions together with timing
    def bind(value_and_time, func):
        result, t = func(value_and_time[0])
        return result, t + value_and_time[1]

    # Bind functions together and calculate total time
    y2, total_time = bind(bind(fast_f(99), slow_f), slow_f2)
    print(f"{y2 = },{total_time = }")

    # Define the TimedValue class
    class TimedValue(object):
        def __init__(self, value, time=0) -> None:
            self.value = value
            self.time = time

        def bind(self, f):
            timed_value = f(self.value)
            new_value = timed_value.value
            new_time = self.time + timed_value.time
            return TimedValue(new_value, new_time)

    # Define the decorator for timing functions with TimedValue
    def ntime_it(f):
        def wrapper(*args, **kwargs):
            start = perf_counter_ns()
            result = f(*args, **kwargs)
            end = perf_counter_ns()
            return TimedValue(result, end - start)

        return wrapper

    # Decorate functions with the TimedValue timing decorator
    @ntime_it
    def nfast_f(x):
        sleep(0.01)
        return x + 1

    @ntime_it
    def nslow_f(x):
        sleep(0.1)
        return x + 1

    @ntime_it
    def nslow_f2(x):
        sleep(0.1)
        return x + 2

    # Bind TimedValue functions together and print results
    timed_value = nfast_f(99).bind(nslow_f).bind(nslow_f2)
    value = timed_value.value
    time = timed_value.time
    print("result with monad")
    print(f"{value = },{time = }")

    # Define the Maybe class

    class Maybe:
        def __init__(self, value):
            self.value = value

        @classmethod
        def unit(cls, value):
            return cls(value)

        def bind(self, f):
            if self.value is None:
                return self  # Forward the empty value
            result = f(self.value)
            if isinstance(result, Maybe):
                return result
            else:
                return Maybe.unit(result)

        def __repr__(self):
            return f"Maybe({self.value})"

    @dataclass
    class User:
        name: str
        friends: list["User"]

    # Define a function to get the first value from a list
    def first_value(values):
        if len(values) > 0:
            return values[0]
        return None

    # Example usage of Maybe monad
    example_user = User(
        "John",
        [
            User(
                "Alice",
                [
                    User("Bob", []),
                    User("Charlie", []),
                ],
            ),
            User("Dave", []),
        ],
    )
    user = Maybe.unit(example_user)
    friends = user.bind(lambda user: Maybe.unit(user.friends)).bind(first_value)
    first_friend = friends.bind(lambda first_friend: Maybe.unit(first_friend.friends))
    friends_of_first_friends = first_friend

    # Print the result
    print(friends_of_first_friends)


def basic_monad():
    class Monad:
        def __init__(self, value):
            self.value = value

        def bind(self, func):
            return func(self.value)

        def __repr__(self):
            return f"Monad({self.value})"

    # Example monadic function: Takes a string and returns a Monad containing its length
    def string_length(s):
        return Monad(len(s))

    # Example monadic function: Takes an integer and returns a Monad containing its square
    def square_number(n):
        return Monad(n**2)

    # Example monadic function: Takes a list and returns a Monad containing the sum of its elements
    def sum_list(lst):
        return Monad(sum(lst))

    # Usage examples
    # Creating a Monad with a value of 5
    monad = Monad(5)
    print("Monad:", monad)

    # Binding the square_number function to the Monad
    squared_monad = monad.bind(square_number)
    print("Square of the Monad's value:", squared_monad)

    # Binding the string_length function to a Monad containing a string
    string_monad = Monad("Hello, world!")
    length_monad = string_monad.bind(string_length)
    print("Length of the string:", length_monad)

    # Binding the sum_list function to a Monad containing a list of numbers
    list_monad = Monad([1, 2, 3, 4, 5])
    sum_monad = list_monad.bind(sum_list)
    print("Sum of the list elements:", sum_monad)


def maybe_monad():
    class Maybe:
        def __init__(self, value):
            self.value = value

        def bind(self, func):
            if self.value is None:
                return Maybe(None)
            else:
                return func(self.value)

        def __repr__(self):
            return f"Maybe({self.value})"

    # Example monadic function: Takes an integer and returns a Maybe containing its square if the integer is positive
    def square_positive_number(n):
        if n >= 0:
            return Maybe(n**2)
        else:
            return Maybe(None)

    # Example usage
    # Creating a Maybe with a value of 5
    maybe_5 = Maybe(5)
    print("Maybe 5 squared:", maybe_5.bind(square_positive_number))

    # Creating a Maybe with a value of -3
    maybe_neg_3 = Maybe(-3)
    print("Maybe -3 squared:", maybe_neg_3.bind(square_positive_number))

    # Creating a Maybe with a value of None
    maybe_none = Maybe(None)
    print("Maybe None squared:", maybe_none.bind(square_positive_number))


def example1():
    basic_monad()
    maybe_monad()


if __name__ == "__main__":
    example()
    example1()
