# <div align="center">Double Circular Linked List</div>

Circular doubly linked list in C or in any programming language is a very useful data structure. Circular double linked list is a type of linked list that consists of node having a pointer pointing to the previous node and the next node points to the previous node in the defined array.

[0-add_node.c]() contains two functions:

* add_node_end:

- Add a new node to the end of a double circular linked list:
    - Prototype: List *add_node_end(List **list, char *str);
    - List: the list to modify
        - str: the string to copy into the new node
        - Returns: Address of the new node, or NULL on failure

* add_node_begin:

- Add a new node to the beginning of a double circular linked list:
    - Prototype: List *add_node_begin(List **list, char *str);
    - List: the list to modify
        - str: the string to copy into the new node
        - Returns: Address of the new node, or NULL on failure
