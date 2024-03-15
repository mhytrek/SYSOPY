
int collatz_conjecture(int i) {
    if (i % 2 == 0) 
        return i / 2;
    return 3 * i + 1;
}

int test_collatz_convergence(int i, int max_iter) {
    int iterations = 0;
    while (i != 1 && iterations < max_iter) {
        i = collatz_conjecture(i);
        iterations++;
    }

    if (iterations == max_iter && i != 1) 
        return -1;

    return iterations;
}