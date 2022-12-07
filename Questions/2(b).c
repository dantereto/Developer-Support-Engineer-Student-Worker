listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new, *cont;
unsigned int number = 0;
new = malloc(sizeof(listint_t));
if (new == '\0')
return ('\0');
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
if (cont == '\0')
return ('\0');
cont = cont->next;
}
new->next = cont->next;
cont->next = new;
return (new);
}