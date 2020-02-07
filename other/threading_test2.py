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
    __count = 0
    """An emergency switch for emergency shutdown the while"""
    _emergency_switch = False
    def __init__(self, period, name=None, args=None, kwargs=None):
        if not name:
            name = "СyclicTimerThread{0}".format(self.__class__.count + 1)
            self.__class__.__count += 1

        Thread.__init__(self, name=name)
        self.period = period
        self.name   = name
        self.args   = args if args is not None else []
        self.kwargs = kwargs if kwargs is not None else {}

        self._event         = threading.Event()
        self.handlerLock    = threading.Lock()

    def __exit__(self, exc_type, exc_val, exc_tb):
        self._stop_thread()

    def _reinitialize_thread(self):
        if self.is_alive():
            return 1
        self._event.clear()
        Thread.__init__(self, name=self.name)

    def _stop_thread(self):
        """Stop the timer if it hasn't finished yet."""
        self._event.set()

    def run(self):
        print('RUN: {}; NAME: {}'.format(self._event.is_set(), self.getName()))
        while not self._event.wait(self.period) and not self._emergency_switch and self.is_alive():
            print('into run while: alive({})'.format(self._event.is_set()))
            try:
                with self.handlerLock:
                    self.handler()
            except Exception as E:
                print('EXCEPT: ', E)
                break
        self._event.set()

    def handler(self):
            pass



class Backup(СyclicTimer):
    def __init__(self, period, name=None):
        СyclicTimer.__init__(self, period, name)

    def handler(self):
        print('***********************************************')
        print('OK LOCK', 2/1)

    def start_again(self):
        self._reinitialize_thread()
        self.start()

    def blocked_event(self):
        self._stop_thread()


class AD(СyclicTimer):
    def __init__(self, period, name=None):
        СyclicTimer.__init__(self, period, name)

    def handler(self):
        print('-----------------------------------------------')
        print('OK LOCK')



def main():
    print('Create thread')
    test2 = Backup(1, "thread_test")
    test2.start()
    i = 0

    while True:
        print('#####################################################################    main thread_{} - Thread({}): is_alive({})'.format(i, threading.active_count(), test2.is_alive()))
        try:
            time.sleep(3)
            i += 1
            if i == 3:
                test2.blocked_event()
            elif i == 6:
                test2.start_again()
        except:
            print('break')
            break

    test2.blocked_event()
    print('end: ', threading.active_count())


if __name__ == '__main__':
    main()

