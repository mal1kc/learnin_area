##
# Project Title
#
# @file
# @version 0.1


all: first second third

first:
	touch first.c

second: first
	echo "int main(){return 0 ;}" > first.c

third: second
	cc first.c -o first.out

clean:
	rm -f first.out first.c


# end
