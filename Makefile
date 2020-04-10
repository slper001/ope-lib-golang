install:
	make -C lib/

clean:
	rm -f example
	make clean -C lib/
