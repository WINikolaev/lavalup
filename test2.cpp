#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data {
   int  thread_id;
   char *message;
};

typedef struct {
	char* msg1;
	char* msg2;
} second_thread_data;

void *PrintHello(void *threadarg) {
	cout << "SLEEP" << endl;
	sleep(5);
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;

	cout << "Thread ID : " << my_data->thread_id ;
	cout << " Message : " << my_data->message << endl;

	pthread_exit(NULL);
}

void* printHello2(void *threadarg) {
	cout << "sleep2 printHello2" << endl;
	sleep(60);
	second_thread_data* data = (second_thread_data *) threadarg;

	cout << "msg1: " << data->msg1 << endl;
	cout << "msg2: " << data->msg2 << endl;

	pthread_exit(NULL);
}

int main () {
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	pthread_attr_t attr;
	void *status;
	int rc;
	int i;

	pthread_t thread2;
	second_thread_data data_detach = {"Hello", "world"};

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	if (!pthread_create(&thread2, NULL, printHello2, (void *)&data_detach)) {
		cout << "Thread create successfully" << endl;
		if (!pthread_detach(thread2)) {
			cout << "Thread detached successfully" << endl;
		}
		
	}
	

	for( i = 0; i < NUM_THREADS; i++ ) {
		cout <<"main() : creating thread, " << i << endl;
		td[i].thread_id = i;
		td[i].message = "This is message";
		rc = pthread_create(&threads[i], &attr, PrintHello, (void *)&td[i]);
	
		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	// free attribute and wait for the other threads
	pthread_attr_destroy(&attr);
	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], &status);
		if (rc) {
			cout << "Error:unable to join," << rc << endl;
			exit(-1);
		}
		cout << "Main: completed thread id :" << i;
		cout << " exiting with status :" << status << endl;
	}
	
	cout << "Main: program exiting." << endl;
	pthread_exit(NULL);
	cout << "END" << endl;
}


//######################################


#include <iostream>
#include <pthread.h>

pthread_mutexattr_t		attr;
pthread_mutex_t			mutex;

struct {
	int a;
	int b;
	int c;
} A;
void g();

void f() {
	pthread_mutex_lock(&mutex);
	A.a++;
	g();
	A.c = 0;
	pthread_mutex_unlock(&mutex);
}

void g() {
	pthread_mutex_lock(&mutex);
	A.b += A.a;
	pthread_mutex_unlock(&mutex);
}

using namespace std;

int main() {
	

	pthread_mutexattr_init(&attr);

	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex, &attr);
	
	cout << "Hello world" << endl;

	f();

	return 0;
}








