        integer a(50), b(50), c(50)
        write(*, *) 'enter how many elements'
        read(*, *) n
        write(*, *) 'enter', n, ' elements'
        read(*,*) (a(i), i=1, n)
        write(*,*) 'enter the position'
        read(*,*) ipos
        write(*,*) 'enter how many to enter'
        read(*,*) m
        write(*,*) 'enter', m, 'elements'
        read(*,*) (b(i), i=1, m)
        do 100 i=1, m+n
           if(i .lt. ipos) then
                c(i)=a(i)
           else if(i .lt. ipos+m) then
                c(i)=b(i-ipos+1)
           else
                c(i)=a(i-m)
           endif
 100    continue
        write(*,*) (c(i), i=1, m+n)
        stop
        end
