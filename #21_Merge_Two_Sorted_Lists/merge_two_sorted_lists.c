/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *new_head;

    struct ListNode *p, *p1, *p2;
    p = new_head;
    p1 = l1;
    p2 = l2;

    while (1)
    {
        struct ListNode *tmp;
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));

        if ((p1 != NULL) && (p2 != NULL))
        {

            if ((p1 == l1) && (p2 == l2))
            {
                new_head = tmp;
                p = new_head;
                p->next = NULL;
            }
            else
            {
                p->next = tmp;
                p = p->next;
                p->next = NULL;
            }

            if (p1->val <= p2->val)
            {
                p->val = p1->val;
                p1 = p1->next;
            }
            else
            {
                p->val = p2->val;
                p2 = p2->next;
            }
        }
        else if ((p1 != NULL) || (p2 != NULL))
        {
            while (p1 != NULL)
            {
                if ((p1 == l1) && (p2 == l2))
                {
                    new_head = tmp;
                    p = new_head;
                    p->next = NULL;
                }
                else
                {
                    p->next = tmp;
                    p = p->next;
                    p->next = NULL;
                }

                p->val = p1->val;
                p1 = p1->next;
                tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            }

            while (p2 != NULL)
            {
                if ((p1 == l1) && (p2 == l2))
                {
                    new_head = tmp;
                    p = new_head;
                    p->next = NULL;
                }
                else
                {
                    p->next = tmp;
                    p = p->next;
                    p->next = NULL;
                }

                p->val = p2->val;
                p2 = p2->next;
                tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            }
        }
        else
        {
            tmp = NULL;
            p = NULL;
            p1 = NULL;
            p2 = NULL;
            free(tmp);
            free(p);
            free(p1);
            free(p2);
            break;
        }
    }

    return new_head;
}