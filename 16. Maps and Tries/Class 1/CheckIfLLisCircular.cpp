bool isCircular(node* head){
    unordered_map<node*, bool> map;

    while(head!= NULL){
        if(map.find(head) == map.end()){
            map[head] = true;
        }
        else
            return true;
        head = head->next;
    }
    return false;
}