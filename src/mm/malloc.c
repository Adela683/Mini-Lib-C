// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define _DEFAULT_SOURCE

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	int *addr;
	size_t len = size + sizeof(size);

	addr = mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (addr == MAP_FAILED)
	{
		return NULL;
	}

	*addr = len;
	return (void *)(&addr[1]);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *addr = malloc(nmemb * size);

	if (addr == NULL)
	{
		return NULL;
	}

	memset(addr, 0, nmemb * size);

	return addr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	int *addr = (int *)ptr;
	if (addr == NULL)
	{
		return;
	}

	addr--;
	size_t len = *addr;

	munmap((void *)addr, len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL)
	{
		return malloc(size);
	}

	if (size <= 0)
	{
		free(ptr);
		return NULL;
	}

	int *addr = (int *)ptr;
	addr--;
	size_t len = *addr;

	if (size > len)
	{
		void *new_ptr = malloc(size);
		if (new_ptr == NULL)
		{
			return NULL;
		}

		memmove(new_ptr, ptr, len);
		free(ptr);

		return new_ptr;
	}
	return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	long long result = nmemb * size;
	if (nmemb != result / size)
	{
		return NULL;
	}

	return realloc(ptr, nmemb * size);
}
