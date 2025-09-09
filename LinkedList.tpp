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

    if(head == nullptr){
        throw string("Error getElement: list is empty");
    }

    Node* ptr = head;

    for(int i = 0; i < position - 1; i++){
        ptr = ptr->next;
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

    // create node with value elem
    Node* rep = new Node;
    rep->value = elem;

    if(head == nullptr && position > 0){
        throw string("Error replace: out of bounds, list is empty");
    }
    else if (position == 0){
        Node* after = head->next;
        head = rep;
        head->next = after;
        return;
    }

    Node* prev = head;
    Node* after = nullptr;
    Node* curr = head;

    // get to the elemtn before the potision, grab pointer
    for(int i = 1; i < position-1; i++){
       prev = prev->next; 
    }

    // go to elem after position, grab pointer

    if(prev->next != nullptr){
        rep->next = curr->next->next;
    }
    else{
        // not sure if this is the proper way 
        throw string("replace: position out of bounds");
    }

    prev->next = rep;
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
