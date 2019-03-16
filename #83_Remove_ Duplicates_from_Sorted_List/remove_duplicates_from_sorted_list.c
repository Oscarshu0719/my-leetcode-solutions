/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    struct ListNode *front = head;
    struct ListNode *rear = head->next;

    while (rear)
    {
        if (front->val == rear->val)
        {
            front->next = rear->next;
            rear = rear->next;
        }
        else
        {
            front = front->next;
            rear = rear->next;
        }
    }

    return head;
}