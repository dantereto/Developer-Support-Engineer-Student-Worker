void searchNode(int i, node **n) {
    if (*n == NULL)
        printf("\nValue does not exist in tree!");
    else if((*n)->data == i)
        printf("\nValue found!");
    else if(i > (*n)->data)
        searchNode(i, &((*n)->rightChildNode));
    else
        searchNode(i, &((*n)->leftChildNode));
}