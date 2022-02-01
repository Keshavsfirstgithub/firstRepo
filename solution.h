int length(Node *head)
{
  int length = 0;
  Node *temp = head;
  while(temp){
    length++;
    temp = temp -> next;
  }

  return length;
}

void printIthNode(Node *head, int i){
  int count = 0;
  Node *temp = head;
  if(temp==NULL){return;}
  while(count<i){
    if(temp->next != NULL){
      count++;
      temp = temp->next;
    }
    else{
      return;
    }
  }
  cout << temp -> data;
}


Node *deleteNode(Node *head, int pos)
{
  if(pos>=length(head)){
    return head;
  }

  else if(pos==0){
    head = head -> next;
    return head;
  }

  else{
    int count = 0;
    Node *temp = head;
    while(count<(pos-1) && temp!=NULL){
      temp = temp->next;
      count++;
    }
    (temp->next) = (temp->next)->next;
    return head;
  }
}

int recursiveLength(Node *head){
  if(head->next == NULL){
    return 1;
  }

  return 1 + recursiveLength(head->next);
}

Node* insertNode(Node *head, int i, int data) {
  
  if(head==NULL){
    return head;
  }

  if(i==0){
    Node *newNode = new Node(data);
    newNode -> next = head;
    head = newNode;

    return head;
  }

  Node *smallCalc = insertNode(head->next,i-1,data);

  head -> next = smallCalc;

  return head;

}

Node *deleteNodeRec(Node *head, int pos) {
	if(head==NULL){
    return head;
  }

  if(pos==0){ //pos == 0
    Node *temp = head;
    head = head -> next;
    delete temp;
    return head;
  }

  Node *smallCalc = deleteNodeRec(head->next,pos-1); //contains changed LL's head 

  head -> next = smallCalc; //link our head with provided head;

  return head;
}

int findNode(Node *head, int n){

  int pos = 0;
  while(head){
    if(head->data == n){
      return pos;
    }
    else{
      head = head -> next;
      pos++;
    }
  }

  return -1;

}

void printReversed(Node *head){

  if(head==NULL){ return; }
  Node *temp = head;
  Node *till = NULL;

  while(till!=head){
    while(temp->next != till){
      temp = temp->next;
    }
    cout << temp->data << " ";
    till = temp;
    temp = head;
  }
}

Node *removeDuplicates(Node *head){

  if(head==NULL){ return head; }

  Node *ptr1 = head;
  Node *ptr2 = head->next;
  while(ptr2!=NULL){

    if(ptr1->data==ptr2->data){

      ptr1->next = ptr2->next;
      Node *temp = ptr2;
      ptr2 = ptr2->next;
      delete temp;
    }

    else{
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }

  }
  return head;

}