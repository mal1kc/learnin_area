"""
example app showing the usage of py3.10 structural pattern matching
"""
from dataclasses import dataclass  # for dataclass object
from typing import List  # for type hinting


def do_something(command: str) -> None:
    """example for basic pattern matching"""
    match command:
        case "red":
            print("🍎")
        case "green":
            print("🍏")
        case "quit":
            print("bye")
            quit()
        case other:
            print(f"we don't have {other} apple")


def do_something2(command: str) -> None:
    """2nd example for pattern matching"""
    match command.split():
        case ["red", "apple"]:
            print("🍎")
        case ["green", fruit]:
            # '\033[0;32m' is the escape sequence for green color
            print(f"\033[0;32m{fruit}")
        case [
            "quit"
            | "exit"
            | "leave"
            | "stop"
            | "end"
            | "terminate"
            | "kill"
            | "bye",
            *rest,
        ]:
            print("bye")
            if "no" in rest:
                # if 'no' is in rest, then return from the function(exit the function)
                return
            quit()
        case other:
            print(f"we don't have {other} ")


def do_something3(command: str) -> None:
    """3rd example for pattern matching"""
    match command.split():
        case ["red", "apple"]:
            print("🍎")
        case ["green", fruit]:
            # '\033[0;32m' is the escape sequence for green color
            print(f"\033[0;32m{fruit}")
        case [
            "quit"
            | "exit"
            | "leave"
            | "stop"
            | "end"
            | "terminate"
            | "kill"
            | "bye",
            *rest,
        ] if "no" in rest:
            print("tricky move,next time be sure about your choice")
        case [
            "quit"
            | "exit"
            | "leave"
            | "stop"
            | "end"
            | "terminate"
            | "kill"
            | "bye"
        ]:
            print("bye")
            quit()
        case other:
            print(f"we don't have {other} ")


@dataclass
class Command:  # Command class is a dataclass that has two attributes: command and rest
    command: str
    arguments: List[str]


def do_something4(command: Command) -> None:
    match command:
        case Command("red", ["apple"]):
            print("🍎")
        case Command("green", things):
            # '\033[0;32m' is the escape sequence for green color
            print(f"\033[0;32m{things}")
        case Command("quit" | "kill" | "exit" | "bye", arguments=["no" | "-N", *rest]):
            print("tricky move,next time be sure about your choice")
        case Command("quit" | "kill" | "exit" | "bye"):
            print("bye, mate")
            quit()
        case other:
            print(
                f"we don't need this -> {other.arguments} because this is -> {other.command!r} unknown command"
            )


def main() -> None:
    """
    main function
    """
    while True:
        command = input("🔧🔤 > ")
        # do_something(command)
        # do_something2(command)
        # do_something3(command)
        if len(command) > 0:
            do_something4(Command(command.split()[0], command.split()[1:]))


if __name__ == "__main__":
    main()
