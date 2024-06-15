build_dir = build

main_src = src/main.c
main_obj = $(build_dir)/main.o
main_out = $(build_dir)/main

lib_src = lib/lib.c
lib_obj = $(build_dir)/lib.o
lib_out = $(build_dir)/liblib.so

CFLAGS = -g -Wall -Werror -Wpedantic

$(main_out): $(main_obj) | $(lib_out)
	gcc $(CFLAGS) -ldl -o $@ $?

$(lib_out): $(lib_obj)
	gcc $(CFLAGS) -shared -o $@ $?

$(main_obj): $(main_src) | $(lib_out)
	gcc $(CFLAGS) -c -o $@ $<

$(lib_obj): $(lib_src) | $(build_dir)
	gcc $(CFLAGS) -c -fpic -o $@ $<

$(build_dir):
	mkdir -p $@

.PHONY: clean run

clean:
	rm -rf $(build_dir)

run: $(main_out)
	cd build && ./main
