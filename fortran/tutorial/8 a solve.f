        integer a(10, 10), b(10, 10), c(10, 10), d(10, 10), t(10, 10),
     $ mu(10, 10), m, n, p, q, x, y
  5     write (*, *) ' Order of Matrix A'
        read (*, *) m, n
        write (*, *) ' Order of Matrix B'
        read (*, *) p, q
        if(n .ne. p) then
             write(*, *) 'Matrix Multiplication Impossible'
             goto 5
        end if
        write (*, *) 'Values'
        read (*, *) ((a(i,j), i=1,m), j=1,n)
        write (*, *) 'Values'
        read (*, *) ((b(i,j), i=1,p), j=1,q)

  6     write (*, *) ' Order of Matrix C'
        read (*, *) x, y
        if(m .ne. y .or. q .ne. x) then
             write(*, *) 'Matrix Addition Impossible'
             goto 6
        end if
        write (*, *) 'Values'
        read (*, *) ((c(i,j), i=1,x), j=1,y)
        
        do 20 i = 1, m
           do 20 j = 1, q
              mu(i, j) = 0
              do 20 k = 1, n
              mu(i, j) = mu(i, j) + a(i, k) * b(k, j)
 20     continue
 
        do 30 i = 1, x
           do 30 j = 1, y
              t(j, i) = c(i, j)
 30     continue
 
        do 40 i = 1, m
           do 40 j = 1, q
              d(i, j) = mu(i, j) + t(i, j)
 40     continue
        write (*, *) 'Required matrix', ((d(i,j), i=1,m), j=1,q)
        pause
        stop
        end
        
        ! what is wrong in multiplication of matrix !!!! :@
