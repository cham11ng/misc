        write(*, *) 'A B C'
        read(*, *) A, B, C
        D = B*B-4*A*C
        x = -B / (2 * A)
        y = sqrt(abs(D)) / (2 * A)
        if(D) 10, 20, 30

30      write(*, *) 'real and unequal root', x+y, x-y
        stop

20      write(*, *) 'real and equal root', x
        stop
        
10      write(*, *) 'imaginary root', x, '+i', i, x, '-i', i
        stop

        end

        
