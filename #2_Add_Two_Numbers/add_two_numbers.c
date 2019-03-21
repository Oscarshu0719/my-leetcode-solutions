/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head;
    head = NULL;

    struct ListNode *i, *j;
    i = l1;
    j = l2;

    struct ListNode *front, *rear;
    front = head;
    rear = head;

    int carry = 0;

    while ((i != NULL) || (j != NULL))
    {
        struct ListNode *new;
        new = (struct ListNode *)malloc(sizeof(struct ListNode));

        int val1 = (i != NULL) ? i->val : 0;
        int val2 = (j != NULL) ? j->val : 0;
        new->val = (val1 + val2 + carry) % 10;
        carry = (val1 + val2 + carry) / 10;
        new->next = NULL;

        if (head == NULL)
        {
            head = new;
            front = head;
            rear = head;
        }
        else
        {
            rear->next = new;
            if (rear == head)
            {
                rear = rear->next;
            }
            else
            {
                front = front->next;
                rear = front->next;
            }
        }

        if (i != NULL)
        {
            i = i->next;
        }

        if (j != NULL)
        {
            j = j->next;
        }
    }

    if (carry == 1)
    {
        struct ListNode *tmp;
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));

        tmp->val = 1;
        tmp->next = NULL;

        rear->next = tmp;
    }

    return head;
}