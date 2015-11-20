/*File Name: cond.c
**Author: 
**Version: 
**Created Time: 15/09/28-09:59  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STOCK (5)

char g_storage[MAX_STOCK]; 
size_t g_stock = 0; //当前库存
pthread_mutex_t g_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t g_empty = PTHREAD_COND_INITIALIZER;

void* show(char const* who,char const* op,char prod){
	printf("%s:",who);
	printf("(%d)",g_stock);
	
	int i;
	for(i=1;i<(MAX_STOCK-g_stock) ; ++i){
		putchar(' ');
	}
	i=0;
	for(i=0;i<g_stock;++i){
		printf("%c",g_storage[i]);
	}
	printf("%s%c\n",op,prod);
	return NULL;
}


void* provider(void* arg){
	char const* who = (char const*) arg;
	for(;;){
		pthread_mutex_lock (&g_mtx);
		while(g_stock >= MAX_STOCK){
			printf("\033[;;32m%s:满仓！\033[0m\n",who);
			pthread_cond_wait(&g_full,&g_mtx);
		}
		char prod = 'A' + rand()%26;
		show(who,"<-",prod);
		g_storage[g_stock++] = prod;
		pthread_cond_signal(&g_empty);
		pthread_mutex_unlock (&g_mtx);
		usleep( (rand()%100) * 5000);
	}
	return NULL;
}

void* customer(void* argv){
	char const* who = (char const*) argv;
	for(;;){
		pthread_mutex_lock(&g_mtx);
		while(! g_stock){
			printf("\033[;;31m%s:空仓！\033[;;0m\n",who);
			pthread_cond_wait(&g_empty,&g_mtx);
		}
		char prod = g_storage[g_stock-1];
		show(who,"->",prod);
		--g_stock;
		pthread_cond_signal(&g_full);
		pthread_mutex_unlock(&g_mtx);
		usleep( (rand()%100) * 5000);
	}
	return NULL;
}





int main(){
	srand(time(NULL));
	pthread_t tid;
	pthread_create(&tid,NULL,provider,"生产者1");
	pthread_t tid2;
	pthread_create(&tid2,NULL,customer,"消费者1");

	getchar();

	return 0;
}

