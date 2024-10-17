# programoutput: <- this is the target, it is simply a name for this rule. You will reference this name if other rule depend on this rule
# helloworld.o <- this is the dependency, it is the file that the target depends on. If the dependency is newer than the target, the target will be rebuilt
# This rule links the helloworld.o file into an executable
helloworldexec: helloworld.o
	gcc lab1.o -o helloworld

# helloworld.o: <- this is the target, it is simply a name for this rule. You will reference this name if other rule depend on this rule
# helloworld.c <- this is the dependency, it is the file that the target depends on. If the dependency is newer than the target, the target will be rebuilt
# This rule compiles the helloworld.c file into an object file
helloworld.o: helloworld.c
	gcc -c helloworld.c


# clean: <- this is the target, it is simply a name for this rule. This rule will not be called when running just make because it is not a dependency of any other rule
# You would call this by running make clean
clean:
	rm *.o helloworld