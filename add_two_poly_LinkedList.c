#include <stdio.h>
#include <stdlib.h>

struct node
{
    int pow;
    float coef;
    struct node *link;
};

struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newp = malloc(sizeof(struct node));
    newp->coef = co;
    newp->pow = ex;
    newp->link = NULL;

    if (head == NULL || ex > head->pow)
    {
        newp->link = head;
        head = newp;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->pow >= ex)
        {
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}

struct node *create(struct node *head)
{
    int n, i;
    float coef;
    int pow;

    printf("enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter the value of coefficient for the %d term: ", i + 1);
        scanf("%f", &coef);

        printf("enter the value of exponent for %d term: ", i + 1);
        scanf("%d", &pow);

        head = insert(head, coef, pow);
    }
    return head;
}

void print(struct node *head)
{
    if (head == NULL)
        printf("no polynomial");
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coef, temp->pow);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

void polyAdd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->pow == ptr2->pow)
        {
            head3 = insert(head3, ptr1->coef + ptr2->coef, ptr1->pow);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->pow < ptr2->pow)
        {
            head3 = insert(head3, ptr1->coef, ptr1->pow);
            ptr1 = ptr1->link;
        }
        else if (ptr1->pow > ptr2->pow)
        {
            head3 = insert(head3, ptr2->coef, ptr2->pow);
            ptr2 = ptr2->link;
        }
    }

    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coef, ptr1->pow);
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coef, ptr2->pow);
        ptr2 = ptr2->link;
    }

    printf("added polynomial is: ");
    print(head3);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("enter the first polynomial\n");
    head1 = create(head1);

    printf("enter the second polynomial\n");
    head2 = create(head2);

    polyAdd(head1, head2);

    return 0;
}
