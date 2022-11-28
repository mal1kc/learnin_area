#!/usr/bin/env python3

import time


class LoadTimeMeta(type):
    base_time = time.perf_counter()

    def __new__(cls, name, bases, namespace):
        print(cls, name, bases, namespace)
        namespace["__class_load_time__"] = time.perf_counter() - LoadTimeMeta.base_time
        return super().__new__(cls, name, bases, namespace)


class A2(metaclass=LoadTimeMeta):
    pass


class B2(A2):
    pass


if __name__ == "__main__":
    print(f"{A2.__class_load_time__=} after base time")
    print(f"{B2.__class_load_time__=} after base time")
