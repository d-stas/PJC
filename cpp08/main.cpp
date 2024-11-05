#include <iostream>
#include <string>

template <typename T>
struct Node
        {
    T data;
    Node* next;
};

template<typename T>
Node<T>* arrayToList(const T tab[], size_t size)
{
    if (size == 0) return nullptr;
    auto* head = new Node<T>{tab[0], nullptr};
    Node<T>* current = head;
    for (size_t i = 1; i < size; ++i)
    {
        current->next = new Node<T>{tab[i], nullptr};
        current = current->next;
    }
    return head;
}

template<typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred predicate)
{
    Node<T>* new_head = nullptr;
    Node<T>* new_tail = nullptr;
    Node<T>** current = &head;

    while (*current)
    {
        if (predicate((*current)->data))
        {
            Node<T>* temp = *current;
            *current = (*current)->next;
            temp->next = nullptr;

            if (!new_head)
            {
                new_head = temp;
                new_tail = new_head;
            }
            else
            {
                new_tail->next = temp;
                new_tail = new_tail->next;
            }
        }
        else
        {
            current = &(*current)->next;
        }
    }

    return new_head;
}

template<typename T>
void deleteList(Node<T>*& head)
{
    while (head)
    {
        Node<T>* temp = head;
        std::cout << "DEL " << head->data << ";" << std::endl;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

template<typename T>
void showList(const Node<T>* head)
{
    const Node<T>* current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool isLong(const std::string& s) { return s.size() >= 5; }

int main()
{
    int tabi[] = { 2, 1, 4, 3, 6, 5, 7, 8 };
    size_t sizei = sizeof(tabi) / sizeof(tabi[0]);
    Node<int>* listAi = arrayToList(tabi, sizei);
    showList(listAi);
    Node<int>* listBi =extract(listAi, [](int n) { return n % 2 == 0; });
    showList(listBi);
    showList(listAi);
    deleteList(listBi);
    deleteList(listAi);

    std::string tabs[] = { "Kasia", "Ola", "Ala", "Zosia", "Ela", "Basia" };
    size_t sizes = sizeof(tabs) / sizeof(tabs[0]);
    Node<std::string>* listAs = arrayToList(tabs, sizes);
    showList(listAs);
    Node<std::string>* listBs = extract(listAs, isLong);
    showList(listBs);
    showList(listAs);
    deleteList(listBs);
    deleteList(listAs);
}
