//implimentation of singley linked list
class node
{
    public:
        int value;
        node* next;
   
        node(int val,node* n=0)
        {
            value = val;
            next = n;
        }
};


class list
{
    private:
        node* head = 0;
        node* tail = 0;
    public:
        node* getHead() { return head; }
        node* getTail() { return tail; }

        list();
        list(int value); 
        list(int array[],int size);
        list(int size,int value);


        ~list();
        list(const list& rhs)
        {
            operator=(rhs);
        }
        const list& operator=(const list& rhs) 
        {
            node* ohead = rhs.head;
            distroy();

            while(ohead!=0)
            {
                append_tail(ohead->value);
                ohead = ohead->next;
            }

            return *this;
        }

        void append_head(int value);
        void append_tail(int value);
        void fill_random(int size = 5);
        void distroy();
        void print();
        void reverse(list& tempHead,node* head);
};
list::~list()
{
    distroy();
}

list::list()
{
    head = 0;
    tail = 0;
}

list::list(int value)
{
    append_head(value);
}
list::list(int array[],int size)
{
    for(int i=0;i<size;i++)   
    {
       append_tail(array[i]); 
    }
}

list::list(int size,int value)
{
    for(int i=0;i<size;i++)   
    {
       append_tail(value); 
    }
}

void list::append_head(int value)
{
   if(head ==0)
       head = tail = new node(value);
   else
       head = new node(value,head);
}

void list::append_tail(int value)
{
    if(tail==0)
        head = tail = new node(value);
    else{
        tail->next = new node(value);
        tail = tail->next;
    }
}

void list::fill_random(int size)
{
    list::distroy();
    srand(time(0));
    for(int i = 0; i<size;i++)
        list::append_head(rand()%100);
}

void list::print()
{
    node* temp = head;
    while(temp != 0)
    {
        cout<<temp->value<<"-->";
        temp = temp->next;
    }
    cout<<"//"<<endl; 
}

void list::distroy()
{
    while(head!= 0)
    {
       node* temp = head; 
       head = head->next;
       delete temp;
    }
    head = 0;
    tail = 0;
}
