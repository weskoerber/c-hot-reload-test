# Hot-reload Test

A very simple test repo for hot-reloading a shared library in C.

## Testing

1. Build the project (`make`)
2. Run the executable (`make run`)
3. Observe output
4. Modify `lib/lib.c`
5. Rebuild the project (`make run`)
6. Observe changed output

## References

- https://man7.org/linux/man-pages/man3/dlopen.3p.html
- https://man7.org/linux/man-pages/man3/dlsym.3p.html
- https://man7.org/linux/man-pages/man3/dlclose.3p.html
