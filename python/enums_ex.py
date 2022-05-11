'''
example for enums in python
'''
from enum import Enum,auto

class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3

class Color2(Enum):
    RED = auto()
    GREEN = auto()
    BLUE = auto()

class Color3(Enum):
    RED,GREEN,BLUE = range(3)

class Color4(Enum):
    RED = 'red'
    GREEN = 'green'
    BLUE = 'blue'


def main():
    print(f'Color  enum  {Color.RED.value}, {Color.GREEN.value}, {Color.BLUE.value}')    # 1, 2, 3
    print(f'Color2 enum  {Color2.RED.value}, {Color2.GREEN.value}, {Color2.BLUE.value}') # 1, 2, 3
    print(f'Color3 enum  {Color3.RED.value}, {Color3.GREEN.value}, {Color3.BLUE.value}') # 0, 1, 2
    print(f'Color4 enum  {Color4.RED.value}, {Color4.GREEN.value}, {Color4.BLUE.value}') # red, green, blue

if __name__ == '__main__':
    main()