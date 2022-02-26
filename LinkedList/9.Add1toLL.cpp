class Solution
{
    public:
    Node* reverse(Node *head){
        Node* curr = head;
        Node* prev = NULL, *next =NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        Node *curr = head;
        Node *prev= NULL;
       
        if(curr->data < 9){
            curr->data += 1;
        }
        else{
            if(curr->data == 9){
                while(curr && curr->data == 9){ //data = 111999 or 999
                    curr->data = 0;
                    prev= curr;
                    curr = curr->next;
                }
            }
            if(curr == NULL){ //data = 999 -> new data = 1000
                prev->next = new Node(1);
            }
            else{ // data = 199 -> new data = 200
                curr->data += 1;
            }
        }
        
        head = reverse(head);
        return head;
    }
};