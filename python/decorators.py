# example decorator and usage


def decorator_function0(original_function):
    def wrapper_function0(*args, **kwargs):
        print("wrapper executed this before {}".format(original_function.__name__))
        result = original_function(*args, **kwargs)
        print("wrapper executed this before {}".format(original_function.__name__))
        return result
    return wrapper_function0


@decorator_function0
def welcome_User(name):
    print("hello {}".format(name))


welcome_User("malik")
welcome_User("malenia")

# ++ extra example

def prefix_decorator(prefix):
    def decorator_function1(original_function):
        def wrapper_function1(*args, **kwargs):
            print("{} wrapper executed this before {}".format(prefix,original_function.__name__))
            result = original_function(*args, **kwargs)
            print("{} wrapper executed this before {}".format(prefix,original_function.__name__))
            return result
        return wrapper_function1
    return decorator_function1

@prefix_decorator("log_")
def welcome_Customer(name):
    print("hello {}".format(name))
    
welcome_Customer("malik")
welcome_Customer("malenia")