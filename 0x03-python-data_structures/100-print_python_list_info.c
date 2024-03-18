#include <stdio.h>
#include <Python.h>

/**
 * display_python_list_info - function to exhibit details about Python lists
 * @p: pointer to Python list object
 *
 * Returns: void
 */
void display_python_list_info(PyObject *p)
{
    // Obtain the size of the Python List
    Py_ssize_t size = PyList_Size(p);
    // Extract the allocated memory information
    Py_ssize_t i;
    PyObject *item;

    // Print size information
    printf("[*] Dimensions of the Python List = %ld\n", size);
    // Print allocated memory details
    printf("[*] Memory Allocated = %ld\n", ((PyListObject *)p)->allocated);

    // Iterate through each element of the list and print its type
    for (i = 0; i < size; i++)
    {
        // Retrieve the i-th element of the list
        item = PyList_GetItem(p, i);
        // Print the type of the element
        printf("Element %ld: Type = %s\n", i, Py_TYPE(item)->tp_name);
    }
}
