class Node
{
    public:

        Node(int d = 0, Node* ptr = nullptr) : data(d), next(ptr) {}
 
    private:

        int data;
        Node* next;
}

class List
{
    public:

        List() : head(nullptr), cursor(nullptr) {}

        ~List();

        void prepend(int value);
        
        int getElement()
        {
            return cursor->data; 
        }

        void advance()
        {
            cursor = cursor->next; 
        }

        void print();

    private:

        Node* head;
        Node* cursor;
}

List::~List()
{
    for (cursor = head; cursor != nullptr; )
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}

void List::prepend(int data)
{
    if (head == nullptr)
    {
        cursor = head = new Node(data, head);
    }
    else
    {
        head = new Node(data, head); 
    }
}

void List::print()
{
    Node* node = head;
    
    while (node != nullptr)
    {
        cout << node->data << ", ";
    }
    cout << "###" << endl;
}
