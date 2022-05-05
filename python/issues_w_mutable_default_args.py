# ref:https://www.youtube.com/watch?v=_JGmemuINww&list=WL&index=6

# needs to be refactored with jupyter notebooks

def add_user(emp, emp_list=[]):
    emp_list.append(emp)
    print(emp_list)
print(add_user.__defaults__)

# emps = ['user1', 'user2', 'user3']
# add_user('user4', emps)
# add_user('user5')
# add_user('user5')
# add_user('user5')
print(add_user.__defaults__)

# -current output:
#['user1', 'user2', 'user3', 'user4']
# ['user5']
# ['user5', 'user5']
# ['user5', 'user5', 'user5']

def add_user_fixed(emp, emp_list=None):
    if emp_list is None:
        emp_list = []
    emp_list.append(emp)
    print(emp_list)

