        integer num, a(50), temp
        write(*, *) 'Number of Numbers'
        read(*, *) n

        do 500 i= 1, n, 1
           write(*, *) 'Number', i
           read(*, *) a(i)
  500   continue
        do 600 i=1, n-1, 1
           do 700 j=i+1, n, 1
               if(a(i) .gt. a(j)) then
                      temp=a(i)
                      a(i)=a(j)
                      a(j)=temp
                end if
  700      continue
  600   continue

  
        write(*, *) 'Ascending Order'
        do 800 i= 1, n, 1
           write(*, *) a(i)
  800   continue
        stop
        end
                      
