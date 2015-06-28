"""modtest - test module"""
global a
a = 999
def f(x):
    global a
    a=2
    return x
def _g(x):
    return x
