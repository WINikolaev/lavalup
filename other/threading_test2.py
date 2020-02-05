import threading
import time
import sys
import telebot
import logging
from threading import Thread
from threading import Timer

# class MyThread(Thread):
#
#     def __init__(self, interval, name=None, args=None, kwargs=None):
#         Thread.__init__(self)
#         self.interval = interval
#         self.name = name
#         self.args = args if args is not None else []
#         self.kwargs = kwargs if kwargs is not None else {}
#         self.finished = threading.Event()
#         self.lock = threading.Lock()
#
#     def cancel(self):
#         self.finished.set()
#
#
#     def run(self):
#         print('wait: ', self.interval)
#         self.finished.wait(self.interval)
#         print(self.finished.is_set())
#         if not self.finished.is_set():
#             #self.function(*self.args, **self.kwargs)
#             print('RUN: ', self.getName())
#         self.finished.set()


class MyThread(Timer):
    stop_it = False
    def __init__(self, interval, name=None, args=None, kwargs=None):
        Timer.__init__(self, interval, self._while)
        self.interval = interval
        self.name = name
        self.args = args if args is not None else []
        self.kwargs = kwargs if kwargs is not None else {}
        self.lock = threading.Lock()

    def _while(self):
        print('###################################')
        #print('_while : ', threading.active_count())
        while self.is_alive():
            self.finished.wait(self.interval)
            if not self.finished.is_set():
                self.handler()
            if self.stop_it:
                self.cancel()
                break


        #self.run()
        print('test3434: ', self.is_alive())
        #Timer.__init__(self, self.interval, self._while).start()

    def handler(self):
        print('handler: {} | exception: {}'.format(threading.active_count(), 123))



class СyclicTimer(Thread):
    stop_while = False
    def __init__(self, period, name=None, args=None, kwargs=None):
        Thread.__init__(self)
        self.period = period
        self.name = name
        self.args = args if args is not None else []
        self.kwargs = kwargs if kwargs is not None else {}
        self.event = threading.Event()

        if self.name:
            self.setName(self.name)

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.stop()

    def stop(self):
        """Stop the timer if it hasn't finished yet."""
        self.event.set()
        self.stop_while = True

    def run(self):
        print('wait0: {}; '.format(self.event.is_set()))
        while self.is_alive() and not self.stop_while:
            res = self.event.wait(self.period)
            print('wait1: {}; res = {}'.format(self.event.is_set(), res))
            if not self.event.is_set():
                self.handler()
           # self.event.set()
          #  print('wait2: {}; res = {}'.format(self.event.is_set(), res))

    def handler(self):
            pass


class Backup(СyclicTimer):
    def __init__(self, period, name=None):
        СyclicTimer.__init__(self, period, name)

    def handler(self):
        print('++++++++++++++++++++++++++++++++++++++++++++++')
        print('Handler Backup: ', self.getName())


class AD(СyclicTimer):
    def __init__(self, period, name=None):
        СyclicTimer.__init__(self, period, name)

    def handler(self):
        print('-----------------------------------------------')
        print('Handler AD: ', self.getName())


def main():
    print('Create thread')
    test2 = Backup(3, "thread_test")
    test2.start()
    test3 = AD(5, "igorek")
    test3.start()
    # test = MyThread(3)
    # test.start()
    i = 0
    while True:
        # print('main{}: t-{} | is_alive({})'.format(i, threading.active_count(), test.is_alive()))
        print('main thread{} - {}: is_alive({})'.format(i, threading.active_count(), test2.is_alive()))
        try:
            time.sleep(1)
            i += 1
            if i == 500:
                test2.stop()
        except:
            test2.stop()
            test2.join()
            print('break')
            break

    print('end: ', threading.active_count())


if __name__ == '__main__':
    main()

