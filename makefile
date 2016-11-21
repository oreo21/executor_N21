compile: exec.c
	gcc exec.c -o exec

clean:
	rm *~ *# exec

run: exec
	./exec
