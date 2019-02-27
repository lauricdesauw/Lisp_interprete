Object car(Object l, int n) {
    assert(n >= 1);
    if (n == 0) {
        car(l);
    }
    else {
        return car(API::cdr(l),n-1);
    }
}

Object cdr(Object l, int n) {
    assert(n >= 1);
    if (n == 0) {
        cdr(l);
    }
    else {
        return cdr(API::cdr(l),n-1);
    }
}

Object cadr(Object l) {
    return car(l,1);
}

Object cddr(Object l) {
    return cdr(l,1);
}
