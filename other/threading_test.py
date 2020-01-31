import threading
import pickle
import functools
import time
import os
import sys

t1 = None
t2 = None

if os.path.exists('backup.pickle'):
    print('There is backup')
    with open('backup.pickle', 'rb') as bp:
        res = pickle.load(bp)
else:
    res = []

print("res: ", res)

def init(sec, handler):
    threading.Timer(sec, handler).start()

def preiod_11sec():
    t1 = threading.Timer(11, preiod_11sec)
    t1.start()
    print("Period_11sec: \tthread_name: ({})".format(
        threading.current_thread().getName()
    ))
    with lock:
        print("lock - 11sec")
        res.append(11)


def preiod_5sec():
    t2 = threading.Timer(5, preiod_5sec)
    t2.start()
    print("Period_5sec: \tthread_name: ({})".format(
        threading.current_thread().getName()
    ))
    with lock:
        res.append(5)
    #lock.acquire()


def exception():
    print("exception")
    test = 5/0


class main:
    def __enter__(self):
        return self
    def test(self):
        print('TEST MSG', 5/0)
    def __exit__(self, exc_type, exc_val, exc_tb):
        print("exit- res: ", res)
        bp.stop_thread()
        # with open('backup.pickle', 'wb') as bp:
        #     pickle.dump(res, bp)
        #     print('save backup')

class myThread():
    # init our thread
    def __init__(self,  sec, name=None):
        self.sec = sec
        self.name = name
        self.thread = threading.Timer(self.sec, self.func_thread)
        if self.name:
            self.thread.setName(self.name)

    def reinit(self, sec, name=None):
        # if old thread alive we have to kill it.
        if self.thread.is_alive():
            self.thread.cancel()

        self.sec = sec
        self.name = name
        self.thread = threading.Timer(self.sec, self.func_thread)
        if self.name:
            self.thread.setName(self.name)

    def start_thread(self):
        self.thread.start()

    def stop_thread(self):
        if self.thread.is_alive():
            self.thread.cancel()

    def func_thread(self):
        self.handler()
        self.thread = threading.Timer(self.sec, self.func_thread)
        if self.name:
            self.thread.setName(self.name)
        self.thread.start()

    def get_name(self):
        return self.thread.getName()

    def handler(self):
        pass


class backup(myThread):
    def __init__(self, sec, name=None):
        myThread.__init__(self, sec, name)
        # here we can get our pickle file

    def handler(self):
        print("backup handler: ", self.get_name())
        # here we can resave our backup file

if __name__ == '__main__':
    try:
        lock = threading.Lock()
        with main() as main:
            bp = backup(5, "GOOD")
            bp.start_thread()
            # print("thread1: ", threading.currentThread())
            init(20, main.test)
            # init(5, preiod_5sec)
            # init(11, preiod_11sec)
            # print("thread2: ", threading.currentThread())
            # #init(20, exception)
            # res.append(1)
            # #main()
            while(True):
                print("WORK: ", threading.)
                time.sleep(10)
    except:
        print("Unexpected error:", sys.exc_info()[0])
        bp.stop_thread()
        # print("except- res: ", res)
        # with open('backup.pickle', 'wb') as bp:
        #     pickle.dump(res, bp)
        #     print('save backup')
        # t1.cancel()
        # t2.cancel()


