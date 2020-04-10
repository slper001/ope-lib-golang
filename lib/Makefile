install:
	@g++ -c ope.cc hgd.cc zz.cc cwrap.cc prng.cc -I.  -std=c++11
	@ar rs libope.a ope.o hgd.o zz.o cwrap.o prng.o> /dev/null 2>&1
	@rm ope.o hgd.o zz.o cwrap.o prng.o

clean:
	rm -f libope.a
