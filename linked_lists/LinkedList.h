#include <string>
using namespace std;

template <class T>
struct Node
{
    T cargo;
    Node<T>* next;

    Node(T cargo, Node<T>* next)
    {
        this->cargo = cargo;
        this->next = next;
    }

    string to_string() const
    {
        return string(cargo);
    }
};


template <class T>
class LinkedList
{
    int num_nodes;
    Node<T>* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }

    void insert_at_front(T cargo) {
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
        num_nodes++;
    }

    T remove_from_front() {
        if (head == nullptr)
            throw runtime_error("Can't remove from and empty list!");
        T cargo = head->cargo;
        Node<T>* front = head;
        head = head->next;
        delete front;
        num_nodes--;
        return cargo;
    }
    int size(){
    
        return num_nodes;
    }
    T get_item(int pos) const{
        if (pos > num_nodes)
            throw runtime_error("Item outside of list range");
        Node<T>* element_i_pointr = head;
        for (int i = 1; i < pos; i++)
        {  
            element_i_pointr = element_i_pointr->next;
        }
        T element_i = element_i_pointr->cargo;
        return element_i;
    }
    void insert_item(T cargo, int pos){
        if (pos > num_nodes)
            throw runtime_error("Item outside of list range");
        if (pos == 1){
            insert_at_front(cargo);
            return;
        }
   
        Node<T>* element_i_pointr = head;
        for (int i = 2; i < pos; i++)
        {  
            element_i_pointr = element_i_pointr->next;
        }
        Node<T>* element_i = new Node<T>(cargo, element_i_pointr->next);
        element_i_pointr->next = element_i;
        num_nodes++;
    }
    void insert_last(T cargo) {
        Node<T>* new_node = new Node<T>(cargo, nullptr);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
        num_nodes++;
    }
    T remove_item(int pos){
        if (pos > num_nodes)
            throw runtime_error("Item outside of list range");
        if (pos == 1){
            return remove_from_front();
        }
        Node<T>* element_i_pointr = head;
        for (int i = 2; i < pos; i++)
        {  
            element_i_pointr = element_i_pointr->next;
        }
        T element_i = element_i_pointr->next->cargo;
        Node<T>* element_i_next = element_i_pointr->next;
        element_i_pointr->next = element_i_next->next;
        delete element_i_next;
        num_nodes--;
        return element_i;
    }
    string to_string() const
    {
        Node<T>* node = head;
        string s = "";
        while (node != nullptr) {
            s += node->to_string();
            node = node->next;
            if (node != nullptr)
                s += ", ";
        }
        return s;
    }
};