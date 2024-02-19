"""
issues with mutable default args
"""

# ref:https://www.youtube.com/watch?v=_JGmemuINww

# - imports for display_time example
from datetime import datetime
import time


def add_user(user, user_list=[]):
    user_list.append(user)
    print(user_list)


def add_user_fixed(user, user_list=None):
    if user_list is None:
        user_list = []
    user_list.append(user)
    print(user_list)


def display_time(time_to_print=datetime.now()):
    print(time_to_print.strftime("%Y-%m-%d %H:%M:%S"))


def display_time_fixed(time_to_print=None):
    if time_to_print is None:
        time_to_print = datetime.now()
    print(time_to_print.strftime("%Y-%m-%d %H:%M:%S"))


print("/---add_user---")
# ? returns default values of function with created with function creation ,this is only evaluated once
print(add_user.__defaults__)
# ? set user_list to [] and append user4 to user_list
add_user("user4")
# ? adds user1 to same list that created with function creation
add_user("user1")
# ? adds same list that created with function creation
add_user("user3")
# ? returns default values of function
print(add_user.__defaults__)

print("\n/---add_user_fixed---")
# ? returns default values of function
print(add_user_fixed.__defaults__)
# ? set user_list to None and append user4 to user_list
add_user_fixed("user4")
# ? set user_list to None and append user1 to user_list
add_user_fixed("user1")
# ? set user_list to None and append user3 to user_list
add_user_fixed("user3")
# ? returns default values of function
print(add_user_fixed.__defaults__)

print("\n/---display_time---")
print(display_time.__defaults__)  # ? returns default values of function
display_time()  # ? returns current time with default values of function
time.sleep(0.3)  # ? module sleeps for 1 second
display_time()  # ? returns current time with default values of function
time.sleep(0.3)
display_time()

print("\n/---display_time_fixed---")
print(display_time_fixed.__defaults__)
display_time_fixed()  # ? returns current time with default values of function
time.sleep(0.3)  # ? module sleeps for 1 second
display_time_fixed()  # ? returns current time with default values of function
time.sleep(0.3)
display_time_fixed()

# - output will be like that
# / ---add_user---
# ([],)
# ['user4']
# ['user4','user1']
# ['user4','user1','user3']
# (['user4', 'user1', 'user3'],)
#
# / ---add_user_fixed---
# (None,)
# ['user4']
# ['user1']
# ['user3']
# (None,)
#
# / ---display_time---
# (datetime.datetime(2022, 5, 17, 11, 40, 41, 553603),)
# 2022-05-17 11:46:41
# 2022-05-17 11:46:41 # seems to be same time(1 second difference is not applied) this is issue with mutable default args
# 2022-05-17 11:46:41 # issue is continued
#
# / ---display_time_fixed---
# (None,)
# 2022-05-17 11:46:43
# 2022-05-17 11:46:44 # seems it is fixed now (1 second difference is applied)
# 2022-05-17 11:46:45 # seems it is fixed now (1 second difference is applied)
