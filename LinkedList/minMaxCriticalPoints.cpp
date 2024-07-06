#include "linkedList.hpp"
using namespace std;
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{

    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return {-1, -1};
    vector<int> critical_points;
    // find all the critical points
    ListNode *prev_node = head;
    ListNode *curr_node = head->next;
    ListNode *next_node = head->next->next;
    int count = 0;
    while (next_node != NULL)
    {
        count++;
        if (prev_node->data > curr_node->data && next_node->data > curr_node->data || prev_node->data < curr_node->data && next_node->data < curr_node->data)
        {
            critical_points.push_back(count);
        }

        prev_node = curr_node;
        curr_node = next_node;
        next_node = next_node->next;
    }

    // minimum and maximum distance

    int n = critical_points.size();
    if (n <= 1)
        return {-1, -1};
    int maxi = critical_points[n - 1] - critical_points[0];
    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        mini = min(mini, critical_points[i + 1] - critical_points[i]);
    }

    return {mini, maxi};
}
