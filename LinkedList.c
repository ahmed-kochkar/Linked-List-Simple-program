#include <stdio.h>
#include <stdlib.h>

struct node {
    int value; 
    struct node *next;
};

void print(struct node *);
struct node* create_node(int );
void add_to_list(struct node *,struct node *, struct node *);
struct node *delete_node(struct node *, int);

int main (){
    struct node *strct1,*strct2,*strct3;
    struct node *head, *tail, *tmp;

    tmp = create_node(12);
    strct1 = tmp;
    head = strct1;
    tail = strct1;

    tmp = create_node(31);
    strct2 = tmp;
    add_to_list(strct1, strct2, tail);

    tmp = create_node(65);
    strct3 = tmp;
    add_to_list(strct2, strct3, tail);

    print(head);
    tmp = delete_node(head, 12);
    head = tmp;
    print(head);
    return 0;
}

void print(struct node* head){
    struct node *temp = head;

    while(temp != NULL){
        printf("%d\n", temp->value);
        temp = temp->next;
    };
    printf("\n");
}

struct node *create_node(int num){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = num;
    new_node->next = NULL;
    return new_node;
}

void add_to_list(struct node *last_one,struct node *new_one, struct node *end){
    last_one->next = new_one;
    new_one->next = NULL;
    end = new_one;
}

struct node* delete_node(struct node *head, int num){
    struct node *current = malloc(sizeof(struct node));
    struct node *previous = malloc(sizeof(struct node));

    current = head;
    previous = current;

    for(; current != NULL; previous = current, current = current->next){
        if(current->value == num){
            previous->next = current->next;
            free(current);
                return head;
        }
        else if(previous->value == num){
            printf("number is in the beginning of the list\n");
            head = head->next;
            free(previous);
            return head;
        }
    };
    return head;
}
