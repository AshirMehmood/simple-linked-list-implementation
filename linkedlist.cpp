#include <iostream>
#include <cstdlib>


struct Node
{
   int value;
   struct Node *next;
};


class LinkedList
{
    public:

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    /*
        void CreateNode()
        void DisplayList()
        void PushStart()
        void PushByValue()
        void RemoveFirst()
        void pop()
        void RemoveByValue
    */

    void pushNode(int value)
    {
        Node *temp = new Node;
        temp->value = value;


        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void DisplayList()
    {
        if (head == nullptr)
        {
            std::cout<<"No Blocks";
        }
        else
        {   Node *current = head;
            while (current != nullptr)
            {
                std::cout<<"\n"<<current->value;
                current = current->next;
            }
        }
        
    }

    void PushStart(int value)
    {
        Node *temp;
        temp->value = value;
        
        if (head != nullptr)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            head = temp;
            temp->next = nullptr;
        }
    }

    void PushByValue(int value, int i)
    {
        Node *current, *temp;
        current = head;
        temp->value = value;
        
        for(int j = 1; j < i; j++)
        {
            if (current != nullptr)
            {
                current = current->next;
            }
        }

        temp->next = current->next;
        current->next = temp;
    }
    
    void RemoveFirst()
    {
        int retrieve = head->value;

        Node *temp = head->next;
        delete head;
        head = temp;
    }

    void pop()
    {
        Node *current, *temp;

        while(current->next->next != nullptr)
        {
            current = current->next;
        }

        delete tail;
        tail = current;
    }

    void RemoveByValue(int n)
    {
        Node *current, *temp;
        current = head;
        
        for(int i = 1; i < n; i++)
        {
            if (current != nullptr)
            {
                current = current->next;
            }
        }
        int retrieve = current->next->next->value;
        temp= current->next->next;
        delete current->next;
        current->next = temp;

    }


    private:
    Node *head;
    Node *tail;
};

int main() {

    LinkedList linkedlist;

    linkedlist.pushNode(1);
    linkedlist.pushNode(3);
    linkedlist.pushNode(2);
    linkedlist.pushNode(5);

    linkedlist.RemoveByValue(3);

    linkedlist.DisplayList();

    return 0;
}