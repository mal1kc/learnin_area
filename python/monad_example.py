#!/usr/bin/env python3
"""
monad is software design pattern in functional programming
more info about monad : https://www.wikiwand.com/en/Monad_(functional_programming)
this example shows how can we use monads in python.

used source while writing this file : https://www.youtube.com/watch?v=26jVysJHB-s
"""

from time import perf_counter_ns, sleep


def main():
    # if we want time things with decorator this will be like
    #
    # example
    def time_it(f):
        def wrapper(*args, **kwargs):
            start = perf_counter_ns()
            result = f(*args, **kwargs)
            end = perf_counter_ns()
            return result, end - start

        return wrapper

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

    y0, time0 = fast_f(99)
    y1, time1 = slow_f(y0)
    y2, time2 = slow_f2(y1)
    total_time = time0 + time1 + time2

    print(f"result without monad")
    print(f"{y2 = },{total_time = }")

    def bind(value_and_time, func):
        result, t = func(value_and_time[0])
        return result, t + value_and_time[1]

    y2, total_time = bind(bind(fast_f(99), slow_f), slow_f2)

    print(f"{y2 = },{total_time = }")

    class TimedValue(object):
        def __init__(self, value, time=0) -> None:
            self.value = value
            self.time = time

        def bind(self, f):
            timed_value = f(self.value)
            new_value = timed_value.value
            new_time = self.time + timed_value.time
            return TimedValue(new_value, new_time)

    # keep same functions as before ,but change the decorator
    def ntime_it(f):
        def wrapper(*args, **kwargs):
            start = perf_counter_ns()
            result = f(*args, **kwargs)
            end = perf_counter_ns()
            return TimedValue(result, end - start)

        return wrapper

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

    timed_value = nfast_f(99).bind(nslow_f).bind(nslow_f2)
    value = timed_value.value
    time = timed_value.time
    print("result with monad")
    print(f"{value = },{time = }")

    # TimedValue class is good example of monad

    # what is monad good for ?
    #
    #   make composition of functions easier
    #   avoid repeating coöputational patterns
    #   paricularly useful when pipelininig operations

    # how to define monad:
    #
    # define a unit function ( or constructor ):plain value -> monadic value
    # define a bind function: for applying a function to a monadic value
    # unit and bind must respect some properties

    # another example : maybe monad

    # user = props.user
    # friends = user.friends if user else None
    # first_friend = friends[0] if len(friends) > 0 else None
    # friends_of_first_friend = (first_friend.friends if first_friend else None)

    # maybe monad: rationale
    # two kind of values: full or empty
    # if an empty value is encountered during a computation pipeline,just forward it
    # this allows us not to check for 'None' at every step

    class Maybe(object):
        def __init__(self, value) -> None:
            self.value = value

        @classmethod
        def unit(cls, value):
            return cls(value)

        def bind(self, f):
            if self.value is None:
                return self  # forward the empty value
            result = f(self.value)
            if isinstance(result, Maybe):
                return result
            else:
                # conflating and map
                return Maybe.unit(result)

    def first_value(values):
        if len(values) > 0:
            return values[0]
        return None

    friends_of_first_friends = (
        Maybe.unit(props)
        .bind(lambda props: props.user)
        .bind(lambda user: user.friends)
        .bind(first_value)
        .bind(lambda first_friend: first_friend.friends)
    )

    # we can chain funcs without None guards (done once in bind) :D
    # Can we be more concise ?

    # instead of writing this:
    Maybe.unit(obj).bind(lambda obj: obj.method())
    # we would like to write
    Maybe.unit(obj).method()
    # we can probably hack something with __getatttr__ ...
    #

    class Maybe(object):
        def __init__(self, value) -> None:
            self.value = value

        def __getattribute__(self, name: str):
            field = getattr(self.value, name)
            if not callable(field):
                return self.bind(lambda _: field)
            return lambda *args, **kwargs: self.bind(lambda _: field(*args, **kwargs))

        @classmethod
        def unit(cls, value):
            return cls(value)

        def bind(self, f):
            if self.value is None:
                return self  # forward the empty value
            result = f(self.value)
            if isinstance(result, Maybe):
                return result
            else:
                # conflating and map
                return Maybe.unit(result)

    # usage of maybe with update

    friends_of_first_friends = Maybe.unit(props).user.friends.bind(first_value).friends


if __name__ == "__main__":
    main()
