# import pickle
#
# data = {
#	'a': [1, 2.0, 3, 4+6j],
#	'b': ("character string", b"byte string"),
#	'c': {None, True, False}
# }
#
# with open('data.pickle', 'wb') as f:
#	pickle.dump(data, f)
#
# with open('data.pickle', 'rb') as f:
#	data_new = pickle.load(f)
#
# print(data_new)


class Base:

    def __init__(self, base_parameter_0, base_parameter_1):
        self.base_parameter_0 = base_parameter_0
        self.base_parameter_1 = base_parameter_1
        print('base __init__')

    def handle(self):
        pass

    def print_p(self):
        print('param: ', self.base_parameter_0)

    def __enter__(self):
        print('__enter__ - objBase')
        return self

    def __exit__(self, *args):
        print('__exit__ - objBase')


class child(Base):
    def handle(self):
        data = self.base_parameter_0
        print('v1: ', data)
        data2 = self.base_parameter_1
        print('v2: ', data2)


class child2(child):
    def handle(self):
        data = self.base_parameter_0
        print('data: ', data)


if __name__ == "__main__":
    with child2(0, 1) as obj:
        obj.handle()