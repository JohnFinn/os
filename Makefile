all: mykernel.bin

GPPPARAMS= -m32
ASPARAMS= --32
LDPARAMS= -melf_i386

%.o: %.cpp
	g++ $(GPPPARAMS) -c $< -o $@

%.o: %.s
	as $(ASPARAMS) -o $@ $<

mykernel.bin : linker.ld kernel.o loader.o
	ld $(LDPARAMS) -T $< -o $@ kernel.o loader.o

clean:
	rm *.o *.bin
