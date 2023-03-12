# very basic `makefile` information

```makefile

targets: prerequisites
    command
    command
    command
    command
```
- the targets are filenames,separated by spaces.Typically,there's is only one per rule
- the commands are a series of steps typically used to **make** the target(s). These need to start with a tab character, not spaces.
- the prerequisites are also filenames ,separated by spaces. These files need to exist before the commands for target run they else called dependencies
> exc:
```**make** file
hello:
    echo "hello"
    echo "this line will always print, because hello file not exists."
```

if we run **make** output of command will be like that:
```sh
 echo "hello"
 hello
 echo "this line will always print, because hello file not exists."
 this line will always print, because hello file not exists.
```

after we create empty file named 'hello' and run **make**  output of command will be like that:

```sh
**make** : 'hello' is up to date.

```
because we write only target and commands that will cause to target as file

if we create foo.c and add code to it and create **make** target for it
> foo.c
```c
int main(){return 0;}
``` 
> makefile
```makefile
foo:
    cc foo.c -o foo
```

then supply **make** command , output:

```sh
make: 'hello' is up to date.
```

this will cause because target no supplied as argument to **make**  command
if we supply **make** command like 'make foo' it will run foo target commands
if we update foo.c and we try to run 'make foo' it will give this as output:
```sh
'make: 'foo' is up to date.'
```
that's because foo file already exists,and that causes to not run target (not recompile foo.c file)
solution is quite simple we add filenames as prerequisite , this will cause to if foo.c modified it will recompile

>> makefile
```c
foo: foo.c
    cc foo.c -o foo
```

**more quick examples**

> makefile
```makefile
foo: foo.o
    cc foo.o -o foo # Runs third

foo.o: foo.c
    cc -c foo.c -o foo.o # Runs second
```

Typically foo.c would already exist, but I want to limit any additional required files
```makefile
foo.c:
    echo "int main() { return 0; }" > foo.c # Runs first
```

**step by step description of this example**

- **make** selects target 'foo' because the first target is default target
- foo requires foo.o,so**make** searches for the foo.o target
- foo.o requires foo.c,so**make** searches foo.c target
- foo.c has no dependencies,so the echo command is run
- the cc -c command is run, because of all foo.o dependencies finished
- the top cc command is run , because of all foo depend. is finished
- that's it foo is a compiled c program

__if we delete foo.c,all targets will rerun.__

*another example*

```makefile
some_file: other_file
    echo "This will always run, and runs second"
    touch some_file

other_file:
    echo "This will always run, and runs first"
```

## make clean
 clean is often used as a target that removes the output of other targets,bu that's not a special keyword in **make** 

> example: **makefile** 
```makefile
some_file:
    touch some_file

clean:
    rm -f some_file
```
##  variables
variables can only be strings . you'll use `:=`,but `=` also works
```makefile
files := file1 file2
some_file: $(files)
    echo "look at this variable": $(files)
    touch some_file

file1:
    touch file1
file2:
    touch file2

clean:
    rm -f file1 file2 some_file
```
single or double quotes does not matter,but if you use them they will be stored with quotes
this will be useful for using with commands like `printf`
```makefile
foo := one two  # foo is assigned to str "one two"
bar := 'one two' # not recommended . bar is assigned to "'one two'"
all:
    printf '$foo'
    printf $bar

```
reference variables can be used with either ${} or $()
```makefile
all:
    echo ${foo}
    echo ${bar}
    
    echo $x # working bad practice
    
```

## targets

### the all target
   
like clean `all` was not keyword, but it can be used as default target

```makefile
all: first second third

first:
    touch first.c

second: first
    echo "int main(){return 0 ;}" > first.c

three: second
    cc first.c -o first.out

clean:
    rm -f first.out first.c
```

### multiple targets

```makefile
all: comp1.o comp2.o

f1.o f2.o:
    echo $@
```
above and below is are equivalent **makefile**s
```makefile
all: comp1.o comp2.o

comp1.o:
    echo comp1.o
comp2.o:
    echo comp2.o
```

## automatic variables and wildcards

both `*` and `%` are wildcards in make,but their meaning are completely different
### `*` wildcard
`*`searches your filesystem for matching filenames but there was a
`common pitfall`
```makefile
# Print out file information about every .c file
print: $(wildcard *.c)
	ls -la  $?
```
* may be used in the target, prerequisites, or in the wildcard function.

> `` Danger: `*` may not be directly used in a variable definitions
> `` Danger: When `*` matches no files, it is left as it is (unless run in the wildcard function)

```makefile
thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

all: one two three four

# Fails, because $(thing_wrong) is the string "*.o"
one: $(thing_wrong)

# Stays as *.o if there are no files that match this pattern :(
two: *.o 

# Works as you would expect! In this case, it does nothing.
three: $(thing_right)

# Same as rule three
four: $(wildcard *.o)

```
## `%` wildcard

 `%` is really useful but is somewhat confusing because of usages situations
 example situations

- when used "matching" mode,it matches one or more characters in str. this match called stem
- when used in "replacing " mode, it takes the stem that was matched and replaces that in str
- `%` is generally used in rule definitions and in some specific functions

## automatic variables

there are many `automatic variables`,some of them are:
```makefile
hey: first second
    # outputs "hey",since this is the target named
    echo $@
    
    # outputs all prerequisites newer than target 
    echo $?
    
    # outputs all prerequisites
    echo $^
    
    touch hey

first:
    touch first

second:
    touch second

clean:
    rm -rf first second

```


## sources docs and more knowledge about makefile

source of this knowledge more about makefile
`makefiletutorial` [web](https://makefiletutorial.com) [github repo](https://github.com/theicfire/makefiletutorial)

