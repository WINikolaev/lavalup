import time
import pickle
import os

class User:
    def __init__(self, chat_id, age, lang):
        self.chat_id = chat_id
        self.age = age
        self.lang = lang

    def get_chat_id(self):
        return self.chat_id

    def age(self):
        return self.age

    def lang(self):
        return self.lang

    def print_age(self):
        print('age: ', self.age)

    def print_chat_id(self):
        print('chat_id: ', self.chat_id)
    def print_lang(self):
        print('lang: ', self.lang)


usersDict = {}
############################TEST1############################
print('############################TEST1############################')
start = time.time()
if os.path.exists('backup.pickle'):
    print('get backaup')
    with open('backup.pickle', 'rb') as bp:
        usersDict = pickle.load(bp)
print('get backup: ', time.time() - start)
print('usersDict len: ', len(usersDict))

############################TEST2############################
print('############################TEST2############################')
start = time.time()
print('added users')
for x in range(len(usersDict), len(usersDict) + 10000):
    usersDict[x] = User(123123, 18, "RU")
print('added users: ', time.time() - start)


############################TEST3############################
print('############################TEST3############################')
start = time.time()
print('save data')
if usersDict:
	with open('backup.pickle', 'wb') as bp:
		print('write backup')
		pickle.dump(usersDict, bp)
print('save data: ', time.time() - start)