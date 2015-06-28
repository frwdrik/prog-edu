'''scopetst: our scope test module'''
v = 8

def f(x):
    '''f: scope test fuction'''
    print("globals: ", list(globals().keys()))
    print(2+2)
    print("entry local:", locals())
    y = x
    u = v
    print("exit local:", list(locals().keys()))
    
