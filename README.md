# CacheAlignedMalloc

A cross-platform C function to allocate and cache line aligned memory

    void * caligned_malloc(size_t size);

### Usage

Use `caligned_malloc` in place of `malloc` and `aligned_free` (from sub-modeule AlignedMalloc) in place of `free` when you need cache line aligned memory.

### Supported platforms

Mac OS X and Linux are supported by calling `posix_memalign`, Windows by calling `_aligned_malloc` (`_aligned_malloc_dbg` while compiling with `_DEBUG`). Outside of those platforms, determined with the `__APPLE__`, `__linux__`, and `_WIN32` macro definitions respectively, the function will use a custom implementation. This custom implementation uses `malloc` under the hood, but returns a pointer to an aligned memory address within a larger memory block. It stores the pointer returned by malloc in the extra space before the aligned memory for `aligned_free` to access later. This is necessary to ensure the memory can be freed correctly.