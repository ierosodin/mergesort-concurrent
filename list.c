#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "generic_printf.h"
#include "stringToNum.c"

/**
 * @brief Create a new node with data _val_ and set the next node to _net_
 * @param val Specifiy the data to assign to the new node
 * @param next Pointer to the next node
 * @return Pointer to the created new node
 */
static node_t *node_new(val_t val, node_t *next)
{
    /* allocate node */
    node_t *node = malloc(sizeof(node_t));
    node->data = val;
    node->next = next;
    return node;
}

static node_t *node_newp(char *map, node_t *next)
{
    /* allocate node */
    node_t *node = malloc(sizeof(node_t));
    node->data = stringToNum(map);
#ifdef _STRING
    node->lastName = map;
#endif
    node->next = next;
    return node;
}

/**
 * @brief Initialize the linked list.
 *
 * The function will allocate a block of memory for _llist\_t_ and
 * initialize its members _head_ to NULL and _size_ to 0.
 *
 * @return Pointer to the allocated _llist\_t_
 */
llist_t *list_new()
{
    /* allocate list */
    llist_t *list = malloc(sizeof(llist_t));
    list->head = NULL;
    list->size = 0;
    return list;
}

/**
 * @brief Insert a new node with the given value val at the head of the _list_
 * @param list The target linked list
 * @param val Specify the value
 * @return The final size of the linked list
 */
int list_add(llist_t * const list, const val_t val)
{
    node_t *e = node_new(val, NULL);
    e->next = list->head;
    list->head = e;
    list->size++;
    return list->size;
}

int list_addp(llist_t * const list, const char *map)
{
    node_t *e = node_newp(map, NULL);
    e->next = list->head;
    list->head = e;
    list->size++;
    return list->size;
}

/**
 * @brief Get the node specified by index
 * If the index is out of range, it will return NULL.
 *
 * @param list The target linked list
 * @param index Specify the index of the node in the _list_
 * @return The node at index _index_.
 */
node_t *list_get(llist_t * const list, const uint32_t index)
{
    uint32_t idx = index;
    if (!(idx < list->size))
        return NULL;
    node_t *head = list->head;
    while (idx--)
        head = head->next;
    return head;
}

/**
 * @brief Display the data of all nodes in the linked list
 * @param list The target linked list
 */
void list_print(const llist_t * const list)
{
    const node_t *cur = list->head;
    while (cur) {
#if defined _NUMBER
        xprintln(cur->data);
#elif defined _STRING
        for (int i = 0; cur->lastName[i] != '\0'; i++)
            xprint(cur->lastName[i]);
#endif
        cur = cur->next;
    }
}

/**
 * @brief Release the memory allocated to nodes in the linked list
 * @param list The target linked list
 */
void list_free_nodes(llist_t *list)
{
    node_t *cur = list->head;
    while (cur) {
        cur = cur->next;
        free(cur);
    }
    list->head = NULL;
}
