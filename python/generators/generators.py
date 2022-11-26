import asyncio
import collections
import contextlib
import math
from collections.abc import Iterator
from typing import NamedTuple


def get_values():
    # every yield function pauses until other next(next() method) call
    yield 'hello'
    yield 'word'
    yield 123
    # return 42 # very uncommon to return something
    # return doesnt return in next call
    # it raies StopIteration: ReturnValue  Exception
    # -> this function gives StopIteration: 42


def example_get_values():
    for x in get_values():
        print(x)

    print(list(get_values()))
    gen = get_values()
    print(next(gen))
    print(next(gen))
    print(next(gen))

    # print(next(get)) StopIteration

# generator can be used in for loops because in python for loop is like


def example_for(x):
    expr = [1, 2, 3]
    it = iter(expr)
    while True:
        try:
            x = next(it)
        except StopIteration:
            break
        else:
            print(x)  # body of the loop


class Range:
    def __init__(self, stop: int):
        self.start = 0
        self.stop = stop

    def __contains__(self, item):
        return isinstance(item, int) and 0 <= item < self.stop

    def __iter__(self) -> Iterator[int]:
        curr = self.start
        while curr < self.stop:
            yield curr
            curr += 1


def example_example():
    print(42 in Range(1000000000000000000000000000000))
    range_obj = Range(1000000000000000000000000000000)
    range_iter = iter(range_obj)
    print(next(range_iter))  # 0
    print(next(range_iter))  # 1
    print(next(range_iter))  # 2
    for i in Range(5):
        print(i)


class MyDataPoint(NamedTuple):
    x: float
    y: float
    z: float


# very good usage of generator is file reading
# because file size not matter while reading
# if you read line by line with generators

# if file is 1GiB it doesnt matter because you reading
# line by line with generator,program not hold all data in memory it holds
# which line current line is and next line is

def mydata_reader(file):
    for row in file:
        cols = row.rstrip().split(',')
        cols = [float(c) for c in cols]
        yield MyDataPoint._make(cols)


def example_reader():
    with open('mydata.txt') as file:
        for row in mydata_reader(file):
            print(row)


# collatz conjecture : https://www.wikiwand.com/en/Collatz_conjecture

def collatz(n):
    while True:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3*n+1
        yield n
        if n == 1:
            break


def collatz_list(n):
    result = []
    count = 0
    while True:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n+1
        count += 1
        result.append(n)
        if n == 1:
            break
    return result


def collatz_len(n):
    count = 0
    while True:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
        count += 1
        if n == 1:
            break
    return count


def example_collatz():
    n = 27
    # seq = list(collatz(n))
    print(len(collatz_list(n)))
    print(collatz_len(n))
    collatz_gen = collatz(n)
    print_collatz_gen = collatz(n)
    # list vs gen
    for i in collatz_list(n):
        if not (next(collatz_gen) == i):
            print(f'it not work same:{next(print_collatz_gen)} == {i}')
            # this line never work beacuse it will work with less memory

    # first = True
    # for i in collatz(n):
    #     if first:
    #         print(f"[{i}", end="")
    #         first = False
    #     print(f",{i}", end="")
    # print("]")
    #
    # print(collatz_list(n))

# generators can be used other sequencess that we know infinite


def powers_of_two():
    x = 1
    while True:
        yield x
        x *= 2


def rational_numbers():
    ...


def fib():
    ...


def primes():
    ...


def example_gen_comp():
    squares = [x*x for x in range(5)]  # list comprehension
    for sq in squares:
        print(sq)

    squares = (x*x for x in range(5))  # generator comprehension
    for sq in squares:
        print(sq)


def example_composable():
    # this all works lazzly (memory efficent)
    with open('./nums.txt') as file:
        nums = (row.partition("#")[0].rstrip() for row in file)
        nums = (row for row in nums if row)
        nums = (float(row)for row in nums)
        nums = (x for x in nums if math.isfinite((x)))
        nums = (max(0., x)for x in nums)
        s = sum(nums)
        print(f'the sum is {s}')

# advanced usage of generators


def worker(f):
    tasks = collections.deque()
    value = None
    while True:
        batch = yield value
        value = None
        if batch is not None:
            tasks.extend(batch)
        else:
            if tasks:
                args = tasks.popleft()
                value = f(*args)


def example_worker():
    w = worker(str)
    w.send(None)
    w.send([(1,), (2,), (3,)])
    print(next(w))
    print(next(w))
    print(next(w))
    w.send([(4,), (5,)])
    print(next(w))
    print(next(w))
    w.close()
    # this is basically async


def another_operator():
    # yield from (x*x for x in range(5))
    for sq in (x*x for x in range(5)):
        yield sq


def quiet_worker(f):
    # bidirectional example
    # caller <-> quiet_worker <-> worker
    while True:
        w = worker(f)
        try:
            return_of_subgen = yield from w
        except Exception as exc:
            print(f"ignoring {exc.__class__.__name__}")


def cleanup_resource():
    ...


@contextlib.contextmanager
def my_resource(*args):
    resource = acquire_resource(*args)
    try:
        yield resource
    finally:
        cleanup_resource(resource)


def main():
    # example_get_values()
    # example_example()
    # example_reader()
    # example_collatz()
    # print(next(powers_of_two()))
    # print(next(powers_of_two()))
    # print(next(powers_of_two()))
    # print(example_gen_comp())
    # example_composable()


if __name__ == "__main__":
    main()
