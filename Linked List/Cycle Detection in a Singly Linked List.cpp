   Cycle Detection in a Singly Linked List
Moderate
Score
160/160
Average time to solve is 40m
Problem statement
Send feedback

You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.

A cycle occurs when a node's next points back to a previous node in the list.

Example:
In the given linked list, there is a cycle, hence we return true.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
1 2 3 4 -1
1

Sample Output 1 :
true

Explanation of Sample Input 1:
The linked list given in the input is as follows:

Sample Input 2 :
1 2 3 4 -1
0

Sample Output 2 :
true

Explanation of Sample Input 2:
The linked list given in the input is as follows:

Sample Input 3 :
5 -1
-1

Sample Output 3 :
false

Explanation of Sample Input 3:
 The linked list given in the input is as follows:

Expected Time Complexity:
Try to solve this problem in O(n).

Expected Space Complexity:
Try to solve this problem in O(1).

Constraints :
0 <= n <= 10^6
-1 <= pos < n
-10^9 <= data <= 10^9 and data != -1

Where 'n' is the size of the singly linked list, 'pos' represents the position (0-indexed) in the linked list where the tail connects to, and 'data' is the Integer data of the singly linked list.

Time Limit: 1 sec

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

bool detectCycle(Node *head)
{
	 if(head==NULL||head->next==NULL){
         return false;
     }
     Node* slow = head;
     Node* fast = head->next;
     while(slow!=fast){
         if(fast==NULL||fast->next==NULL){
             return false;
         }
         slow = slow->next;
         fast = fast->next->next;
     }
     return true;
}
class Runner
{
    int t;
    vector<Node *> arr;

public:
    Node *takeInput()
    {
        int data;
        cin >> data;
        Node *head = NULL, *tail = NULL;
        while (data != -1)
        {
            Node *newNode = new Node(data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            cin >> data;
        }

        int pos;
        cin >> pos;

        if (pos != -1)
        {

            Node *temp = head;
            //  Connecting last element to "pos"th node
            while (pos--)
            {
                temp = temp->next;
            }
            tail->next = temp;
        }

        return head;
    }

    void execute(Node *head)
    {
        bool ans = detectCycle(head);
    }

    void executeAndPrintOutput(Node *head)
    {
        bool ans = detectCycle(head);
        if (ans)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Runner runner;
    Node *head = runner.takeInput();
    runner.executeAndPrintOutput(head);

    return 0;
}

  
