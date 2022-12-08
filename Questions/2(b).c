#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct listint_s
{
int n;
struct listint_s *next;
} listint_t;

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: head of the list
 * @idx: the node
 * @n: the number
 * Return: NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new, *cont;
    unsigned int number = 0;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = n;
    if (idx == 0)
    {
        new->next = *head;
        *head = new;
        return (new);
    }
    cont = *head;
    for (number = 0; number < idx - 1; number++)
    {
        if (cont == NULL)
            return (NULL);
        cont = cont->next;
    }
    new->next = cont->next;
    cont->next = new;
    return (new);
    }

    void free_listint2(listint_t **head)
    {
        listint_t *tmp;
        if (head == NULL)
            return;
        while (*head != NULL)
        {
            tmp = *head;
            *head = (*head)->next;
            free(tmp);
        }
    }
    void free_listint(listint_t *head)
    {
        listint_t *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    size_t print_listint(const listint_t *h)
    {
        size_t cont = 0;
        while (h != NULL)
        {
            printf("%d\n", h->n);
            h = h->next;
            cont++;
        }
        return (cont);
    }
    listint_t *add_nodeint(listint_t **head, const int n)
    {
    listint_t *new;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = n;
    new->next = *head;
    *head = new;
    return (new);
    }
    listint_t *add_nodeint_end(listint_t **head, const int n)
    {
        listint_t *new;
        new = malloc(sizeof(listint_t));
        if (new == NULL)
            return (new);
        new->n = n;
        new->next = NULL;
        if (*head != NULL)
        {
            listint_t *end = *head;
            while (end->next != NULL)
            end = end->next;
            end->next = new;
        }
        else
            *head = new;
        return (*head);
    }
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    printf("-----------------\n");
    insert_nodeint_at_index(&head, 5, 4096);
    print_listint(head);
    free_listint2(&head);
    return (0);
}