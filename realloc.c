#include "shell.h"

/**
 * _realloc - reallocate memory with a new size
 * @ptr: pointer to data type to reallocate mem for
 * @old_size: size of the initially allocated memory
 * @new_size: size of the new memory to be allocated
 * Return: On success a pointer to the input data type
 * is returned.
 * On error a NULL pointer is returned
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;
	char *ptr_cp, *fil_new_ptr;
	size_t i;


	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_cp = ptr;
	new_ptr = malloc(sizeof((*ptr_cp)) * new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	fil_new_ptr = new_ptr;
	for (i = 0; i < old_size && i < new_size; i++)
		fil_new_ptr[i] = ptr_cp[i];
	free(ptr);
	return (new_ptr);
}
