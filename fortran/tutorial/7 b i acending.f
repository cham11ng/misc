        integer a(20)
        write(*, *) 'Number of Number and Data''s'
        read (*, *) n, (a(i), i = 1, n)
        
        do 20 i = 1, n-1
           do 20 j = i+1, n
              if(a(i) .gt. a(j)) then
                   it = a(j)
                   a(j) = a(i)
                   a(i) = it
              end if
   20   continue
        write(*, *) 'Data''s are ', (a(i), i = 1, n)
        pause
        stop
        end
           
        
