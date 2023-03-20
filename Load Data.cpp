#include"login.h"

void import_login_data (User_node *&users, ifstream fin){
    users=new User_node;
    User_node* cur=users;
    while(!fin.eof()){
        fin>>cur->data.username>>cur->data.password;
        cur->next=new User_node;
        cur=cur->next;
        cur->next=nullptr;
    }
}