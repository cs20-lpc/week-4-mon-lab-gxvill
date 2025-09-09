template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // start at the head of the list, traverse to the end (->next == nullptr) then add the element
    // TODO

    Node* app = new Node;
    app->value = elem;
    app->next = nullptr;

    if(head == nullptr){
        head = app;
        return;
    }

    Node* ptr = head;

    while(ptr->next != nullptr){
        ptr = ptr->next;
    }

    // we only get to this point once next is null
    
    ptr->next = app;
}

template <typename T>
void LinkedList<T>::clear() {
    // start from the beginning of the list. As we go to the next, we delete the last. Go until we reach nullptr. 
    // delete the last
    // this should be a loop of 
    // TODO

    if(head == nullptr){
        return;
    }

    while(head != nullptr){
        Node* temp = head;
        head = head->next;

        delete temp;
    }

}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO

    position++;

    if(head == nullptr){
        throw string("Error getElement: list is empty");
    }

    Node* ptr = head;

    for(int i = 0; i < position - 1; i++){
        if(ptr->next != nullptr){
            ptr = ptr->next;
        }
        else{
            throw string("Error getElement: position out of bounds");
        }
    }

    return ptr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    // set prev->next = elem
    // set elem->next = after
    // delete node at position

    position++;

    //position at 1 (base case)
    if(position == 1){
        Node* old = head;
        Node* rep = new Node;
        rep->value = elem;
        rep->next = old->next;
        head = rep;
        delete old;

        return;
    }

    // create node with value elem
    Node* rep = new Node;
    rep->value = elem;

    Node* prev = head;

    //go to node before position
    for(int i = 1; i < position - 1; i++){
        if(prev->next == nullptr){
            throw string("Error replace: out of bounds index");
        }
        prev = prev->next;
    }

    Node* target = prev->next;
    if(target == nullptr){
        throw string("Error replace: out of bounds index");
    }

    prev->next = rep;
    rep->next = target->next;
    delete target;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
