#include "AlignedMalloc/aligned_malloc.h"
#include "CacheLineSize/CacheLineSize.h"

#include <stddef.h>

void * caligned_malloc(size_t size) {
	static size_t cache_line_size = -1;
	if (cache_line_size == -1)
		cache_line_size = CacheLineSize();
	return aligned_malloc(size, cache_line_size);
}