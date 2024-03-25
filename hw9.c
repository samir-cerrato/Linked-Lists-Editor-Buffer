/*Samir Cerrato
 * COMP 211, Fall 2022
 * Homework 9
 *
 * Linked lists and an editor buffer
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "comp211.h"
#include "hw9.h"

/* empty = an empty buffer.
 */
struct buffer *empty(void) {
  struct buffer* buf = malloc(sizeof(buffer));
  struct node* head  = malloc(sizeof(node));
    head->prev = NULL;
  struct node* tail = malloc(sizeof(node));
    tail->next = NULL;

  head->next=tail;
  tail->prev=head;
  head->data='\0';
  tail->data='\0';

  buf->head=head;
  buf->tail=tail;
  buf->index=head;

  buf->location = 0;
  buf->length = 0;

  return buf;
}

/* insert(buf, c) inserts c to the left of the insertion point of buf.  After
 * the insertion, the insert mark is to the right of c.
 */
void insert(struct buffer *buf, char c) {


  struct node* n=malloc(sizeof(node));
  n->data = c;



  n->next = buf->index->next;
  n->prev= buf->index;
  buf->index -> next -> prev = n;
  buf->index -> next = n;

  buf->location++;
  buf->length++;

}

/* delete_left(buf) deletes the character to the left of the insert mark.  If
 * there is no character to the left of the insert mark, this function has no
 * effect.
 */
void delete_left(struct buffer *buf) {
  if(buf->index->prev == NULL){
    return;
  }
  struct node* delete= buf->index->prev;
  // buf->index->previous->previous = buf->index;
  // buf->index->previous->previous->next = buf->index;
  // buf->index->next = buf->index->next->next;

  buf->index->prev = buf->index->prev->prev;
  buf->index->prev->next = buf->index;
  free(delete);
  buf->length--;
  buf->location--;

}


/* delete_right(buf) deletes the character to the right of the insert mark.  If
 * there is no character to the right of the insert mark, this function has no
 * effect.
 */
void delete_right(struct buffer *buf) {
  if(buf->index->next == NULL){
    return;
  }
  struct node* delete= buf->index->next;

  buf->index->next = buf->index->next->next;
  buf->index->next->prev = buf->index;
  free(delete);
  buf->length++;
  buf->location++;
}

/* move_left(buf) moves the insert mark one character to the left.  If there is
 * no character to the left of the insert mark, this functdion has no effect.
 */
void move_left(struct buffer *buf) {
  if(buf->location == 0){
    return;
  }else{
    buf->location--;
    buf->index= buf->index->prev;
  }
}

/* move_right(buf) moves the insert mark one character to the right.  If there
 * is no character to the right of the insert mark, this functdion has no
 * effect.
 */
void move_right(struct buffer *buf) {
  if(buf->location == buf->length){
    return;
  }else{
    buf->location++;
    buf->index = buf->index->next;
  }
}

/* set(buf, n) sets the insert mark so that it is to the left of the n-th
 * character.  Characters are 0-indexed, so set(buf, 0) sets the insert mark to
 * the beginning of the buffer.  n may be equal to the length of the buffer; in
 * this case, the insert mark is set to the right of the last character.
 *
 * Pre-condition:  0 <= n <= len(buf).
 */
void set(struct buffer *buf, int n) {
  if(n > buf->length){
    return;
  }
  buf->index = buf->head;
  buf->location = 0;
  while(buf->location != n){
    buf->location = buf->location+1;
    buf->index = buf->index->next;
  }
  buf->location = n;
  // while(buf->location != n){
  //   buf->location = buf->location+1;
  //   buf->index = buf->index->next;
  // }
}

/* contents(buf) = c, where c->left is the string to the left of the insert
 * mark and c->right is the string to the right of the insert mark.
 */
struct buffer_contents *contents(struct buffer *buf) {
    /* calloc initializes memory to 0 */

    struct buffer_contents* cnt = calloc(1, sizeof(struct buffer_contents));
    cnt->left = calloc(1, sizeof(char));
    cnt->right = calloc(1, sizeof(char));

    int i = 0;
    struct node* left_counter = buf->head->next;
    while(i < buf->location){
      cnt->left[i] = left_counter->data;
      left_counter = left_counter->next;
      i++;
    }

    int j = buf->location;
    struct node* right_counter = left_counter;
    while(j < buf->length){
      cnt->right[j-buf->location] = right_counter->data;
      right_counter = right_counter->next;
      j++;
    }
    // print(cnt->left);
    // print(cnt->right);
    return cnt;
}
