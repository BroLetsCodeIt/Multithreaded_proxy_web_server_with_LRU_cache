#include "proxy_parse.h";
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<pthread.h>

#define MAX_CLIENTS 10;
typedef struct cache_element_list cache_element_list;

// creating the cache 
struct cache_element_list {
    char* data ;  // jo bhi data response mai ayaa hai vo store hoga is data mai.
    int len ;     // data ka length 
    char* url ;   // url of the request eg. https://www.google.com
    time_t lru_time_track; // time ek basis pe LRU cache use karenge.
    cache_element_list* next;   
};


cache_element_list* find(char* url);

int add_cache_element_list(char* data , int size , char* url);

void remove_cache_element();


int port_number = 8000; // proxy server : PORT it will run
int proxy_socketId ;

// jitne client hai uthe thread 
// har ek thread mai ek socket 

pthread_t tid[MAX_CLIENTS];


