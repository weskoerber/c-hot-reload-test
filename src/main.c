#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  char buf[128] = {0};

  void (*hello)(void);

  while (1) {
    void *lib = dlopen("./liblib.so", RTLD_LAZY);
    if (dlerror()) {
      fprintf(stderr, "dlopen: %s\n", dlerror());
      return 1;
    }

    *(void **)(&hello) = dlsym(lib, "hello");
    if (dlerror()) {
      dlclose(lib);
      if (dlerror()) {
        fprintf(stderr, "dlopen: %s\n", dlerror());
        return 1;
      }
      fprintf(stderr, "dlopen: %s\n", dlerror());
      return 1;
    }

    hello();

    long recv = 0;
    while (1) {
      fgets(buf, sizeof(buf), stdin);
      if (recv < 128) {
        break;
      }
    }

    dlclose(lib);
    if (dlerror()) {
      fprintf(stderr, "dlopen: %s\n", dlerror());
      return 1;
    }
  }
}
